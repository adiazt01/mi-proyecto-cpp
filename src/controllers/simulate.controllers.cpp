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
#include "bill.hpp"

void processClient(Database &db, std::default_random_engine &generator, std::uniform_int_distribution<int> &productDistribution, std::uniform_int_distribution<int> &timeDistribution, int numProducts)
{
    // Process client
    if (db.hasClients())
    {
        // Get next client
        Client client = db.getNextClient();

        // Random number generators
        auto start = std::chrono::high_resolution_clock::now();
        double maxTime = 10 * 60;

        for (int i = 0; i < numProducts; ++i)
        {

            // Get a random product
            int productId = productDistribution(generator);
            // Get product from database
            Product product = db.getProduct(productId);

            // If the product is in stock, add it to the shopping cart
            if (db.getProduct(productId).getStock() > 0)
            {
                client.shoppingcart.addProduct(product);
                // Reduce stock
                db.reduceStock(product.getId(), 1);

                std::cout << "+ " << product.getName() << " $" << product.getPrice() << std::endl;
            }
            else
            {
                std::cout << "x " << product.getName() << " se ha agotado." << std::endl;
            }

            // Random time to wait before adding another product
            int time = timeDistribution(generator);

            // Wait
            std::this_thread::sleep_for(std::chrono::seconds(time));

            // Check if the client has exceeded the maximum time
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;

            // If the client has exceeded the maximum time, add it to the end of the queue
            if (elapsed.count() > 10 * 60)
            {
                std::cout << "El cliente " << client.getName() << " ha excedido el tiempo máximo y será enviado al final de la cola." << std::endl;
                db.addClient(client);
                break;
            }

            // Calculate remaining time
            double timeRemaining = maxTime - elapsed.count();
        }

        Bill bill = Bill(client.getName(), client.getLastname(), client.getPhonenumber(), client.shoppingcart.getProducts(), client.shoppingcart.getTotalPrice());

        db.addBill(bill);

        std::cout << "\n------------------ Factura ------------------\n";
        std::cout << "Cliente: " << client.getName() << " " << client.getLastname() << "\n";
        std::cout << "Número de teléfono: " << client.getPhonenumber() << "\n";
        std::cout << "Productos:\n";
        for (const auto &product : client.shoppingcart.getProducts())
        {
            std::cout << "- " << product.getName() << ": $" << product.getPrice() << "\n";
        }
        std::cout << "Total: $" << client.shoppingcart.getTotalPrice() << "\n";
        std::cout << "---------------------------------------------\n\n";

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

    // Add products if there are none
    if (db.getProducts().size() == 0)
    {
        for (int i = 0; i < 3; ++i)
        {
            Product product(
                "Product " + std::to_string(i + 1),
                "Description of product " + std::to_string(i + 1),
                10.0 * (i + 1),
                100);

            db.addProduct(product);
        }
    }

    // Add clients if there are none
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Dave"};
    std::vector<std::string> lastNames = {"Johnson", "Smith", "Williams", "Brown"};

    // Random number generators
    std::default_random_engine generator;

    // Distributions
    // ID for names
    std::uniform_int_distribution<int> nameDistribution(0, names.size() - 1);
    std::uniform_int_distribution<int> phoneDistribution(1000000, 9999999);
    std::uniform_int_distribution<int> timeDistribution(15, 30);
    // Number of products for clients
    std::uniform_int_distribution<int> numProductsDistribution(1, 30);
    // ID for products
    std::uniform_int_distribution<int> productDistribution(1, db.getProducts().size());

    int maxClients = 100;
    int clientCount = 0;

    while (clientCount < maxClients && continueSimulation)
    {
        system("cls");
        std::cout << "Simulación de la tienda" << std::endl;
        std::cout << "-----------------------" << std::endl
                  << std::endl;

        // Random time to wait before adding a client
        std::this_thread::sleep_for(std::chrono::seconds(timeDistribution(generator)));

        // Random client data
        std::string name = names[nameDistribution(generator)];
        std::string lastName = lastNames[nameDistribution(generator)];
        long long phoneNumber = phoneDistribution(generator);
        int numProducts = numProductsDistribution(generator);

        // Add client to the queue
        Client client(name, lastName, 0, phoneNumber);

        std::cout << "Añadiendo a " << client.getName() << " a la cola 🐧" << std::endl
                  << std::endl;

        // Add client to the queue          
        db.addClient(client);

        // Process client
        processClient(db, generator, productDistribution, timeDistribution, numProducts);
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