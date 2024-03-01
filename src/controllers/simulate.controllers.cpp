#include <simulate.controllers.hpp>
#include <clientQueue.hpp>
#include <client.hpp>
#include <product.hpp>
#include <database.hpp>
#include <random>
#include <chrono>
#include <thread>

void processClient(ClientQueue &clientQueue, Database &db, std::default_random_engine &generator, std::uniform_int_distribution<int> &productDistribution, std::uniform_int_distribution<int> &timeDistribution, int numProducts)
{
    if (!clientQueue.isEmpty())
    {
        Client client = clientQueue.getNextClient();

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < numProducts; ++i)
        {
            int productId = productDistribution(generator);
            Product product = db.getProduct(productId);
            client.shoppingcart.addProduct(product);

            std::cout << "El cliente " << client.getName() << " " << client.getLastname() << " ha agregado el producto " << product.getName() << " a su carrito." << std::endl;
            int time = timeDistribution(generator);
            std::this_thread::sleep_for(std::chrono::seconds(time));

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;

            if (elapsed.count() > 10 * 60)
            {
                std::cout << "El cliente " << client.getName() << " ha excedido el tiempo máximo y será enviado al final de la cola." << std::endl;
                clientQueue.addClient(client);
                return;
            }
        }

        std::cout << "El cliente " << client.getName() << " " << client.getLastname() << " ha terminado de comprar." << std::endl;

        clientQueue.removeClient();
    }
}

void simulate()
{
    Database &db = Database::getInstance();
    ClientQueue clientQueue;

    for (int i = 0; i < 5; ++i)
    {
        Product product(
            "Product " + std::to_string(i + 1),
            "Description of product " + std::to_string(i + 1),
            10.0 * (i + 1),
            100,
            i + 1);

        db.addProduct(product);
    }

    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Dave"};
    std::vector<std::string> lastNames = {"Johnson", "Smith", "Williams", "Brown"};

    std::default_random_engine generator;
    std::uniform_int_distribution<int> nameDistribution(0, names.size() - 1);
    std::uniform_int_distribution<int> phoneDistribution(1000000, 9999999);
    std::uniform_int_distribution<int> timeDistribution(15, 30);
    std::uniform_int_distribution<int> numProductsDistribution(1, 30);
    std::uniform_int_distribution<int> productDistribution(1, db.getProducts().size() - 1);

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(timeDistribution(generator)));
        std::string name = names[nameDistribution(generator)];
        std::string lastName = lastNames[nameDistribution(generator)];
        long long phoneNumber = phoneDistribution(generator);
        int numProducts = numProductsDistribution(generator);

        Client client(name, lastName, 0, phoneNumber);

        clientQueue.addClient(client);

        processClient(clientQueue, db, generator, productDistribution, timeDistribution, numProducts);
    }
}