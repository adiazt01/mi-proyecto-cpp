#include <simulate.controllers.hpp>
#include <clientQueue.hpp>
#include <client.hpp>
#include <database.hpp>
#include <random>
#include <chrono>
#include <thread>

void processClient(ClientQueue &clientQueue)
{
    while (!clientQueue.isEmpty())
    {

        Client client = clientQueue.getNextClient();

        auto start = std::chrono::high_resolution_clock::now();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        if (elapsed.count() > 10 * 30)
        {
            clientQueue.addClient(client);
        }
    }
}

void simulate()
{
    Database &db = Database::getInstance();

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

    ClientQueue clientQueue = ClientQueue();

    while (true)
    {
        Database &db = Database::getInstance();

        std::string name = names[nameDistribution(generator)];
        std::string lastName = lastNames[nameDistribution(generator)];
        long long phoneNumber = phoneDistribution(generator);
        int time = timeDistribution(generator);
        int numProducts = numProductsDistribution(generator);

        Client client(name, lastName, phoneNumber);

        for (int i = 0; i < numProducts; ++i)
        {
            int productId = i + 1;
            int quantity = i + 1;

            client.addProductToCart(productId, quantity);
        }

        clientQueue.addClient(client);

        std::this_thread::sleep_for(std::chrono::seconds(time));
        processClient(clientQueue);
    }
}