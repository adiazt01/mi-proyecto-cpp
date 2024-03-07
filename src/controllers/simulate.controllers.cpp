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
    if (db.hasClients())
    {
        Client client = db.getNextClient();

        auto start = std::chrono::high_resolution_clock::now();
        double maxTime = 10 * 60;

        for (int i = 0; i < numProducts; ++i)
        {
            int productId = productDistribution(generator);
            Product product = db.getProduct(productId);

            if (db.getProduct(productId).getStock() > 0)
            {
                client.shoppingcart.addProduct(product);
                db.reduceStock(product.getId(), 1);

                std::cout << "+ " << product.getName() << " $" << product.getPrice() << std::endl;
            }
            else
            {
                std::cout << "x " << product.getName() << " se ha agotado." << std::endl;
            }

            int time = timeDistribution(generator);
            std::this_thread::sleep_for(std::chrono::seconds(time));
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;

            if (elapsed.count() > 10 * 60)
            {
                std::cout << "El cliente " << client.getName() << " ha excedido el tiempo máximo y será enviado al final de la cola." << std::endl;
                db.addClient(client);
                break;
            }

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
    ClientQueue clientQueue;

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

    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Dave"};
    std::vector<std::string> lastNames = {"Johnson", "Smith", "Williams", "Brown"};

    std::default_random_engine generator;
    std::uniform_int_distribution<int> nameDistribution(0, names.size() - 1);
    std::uniform_int_distribution<int> phoneDistribution(1000000, 9999999);
    std::uniform_int_distribution<int> timeDistribution(15, 30);
    std::uniform_int_distribution<int> numProductsDistribution(1, 30);
    std::uniform_int_distribution<int> productDistribution(1, db.getProducts().size());

    int maxClients = 100;
    int clientCount = 0;

    while (clientCount < maxClients && continueSimulation)
    {
        system("cls");
        std::cout << "Simulación de la tienda" << std::endl;
        std::cout << "-----------------------" << std::endl
                  << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(timeDistribution(generator)));
        std::string name = names[nameDistribution(generator)];
        std::string lastName = lastNames[nameDistribution(generator)];
        long long phoneNumber = phoneDistribution(generator);
        int numProducts = numProductsDistribution(generator);

        Client client(name, lastName, 0, phoneNumber);

        std::cout << "Añadiendo a " << client.getName() << " a la cola 🐧" << std::endl
                  << std::endl;
        db.addClient(client);

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