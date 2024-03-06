#include <simulate.controllers.hpp>
#include <clientQueue.hpp>
#include <client.hpp>
#include <product.hpp>
#include <database.hpp>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>
#include "globals.hpp"

void processClient(ClientQueue &clientQueue, Database &db, std::default_random_engine &generator, std::uniform_int_distribution<int> &productDistribution, std::uniform_int_distribution<int> &timeDistribution, int numProducts)
{
    if (!clientQueue.isEmpty())
    {
        Client client = clientQueue.getNextClient();

        auto start = std::chrono::high_resolution_clock::now();
        double maxTime = 10 * 60;

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
                break;
            }

            double timeRemaining = maxTime - elapsed.count();
            std::cout << "Tiempo restante para el cliente " << client.getName() << ": " << timeRemaining << " segundos." << std::endl;
        }

        std::cout << "El cliente " << client.getName() << " " << client.getLastname() << " ha terminado de comprar." << std::endl;
        std::cout << "El total de la compra es: " << client.shoppingcart.getTotalPrice() << std::endl;

        std::string input;
        std::cout << "¿Desea continuar con la simulación? (s/n): ";
        std::cin >> input;
        if (input == "n" || input == "N")
        {
            continueSimulation = false;
        }
    }
}

void simulateShop()
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

    int maxClients = 100;
    int clientCount = 0;

    while (clientCount < maxClients && continueSimulation)
    {
        std::this_thread::sleep_for(std::chrono::seconds(timeDistribution(generator)));
        std::string name = names[nameDistribution(generator)];
        std::string lastName = lastNames[nameDistribution(generator)];
        long long phoneNumber = phoneDistribution(generator);
        int numProducts = numProductsDistribution(generator);

        Client client(name, lastName, 0, phoneNumber);

        clientQueue.addClient(client);

        processClient(clientQueue, db, generator, productDistribution, timeDistribution, numProducts);
        clientCount++;

        if (!continueSimulation)
        {
            break;
        }
    }
}

void simulate()
{
    simulateShop();

    if (!continueSimulation)
    {
        std::cout << "Simulación terminada." << std::endl;
    }
    else
    {
        std::cout << "Simulación cancelada." << std::endl;
    }
}