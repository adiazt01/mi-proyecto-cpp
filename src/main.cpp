#include <iostream>
#include <product.hpp>
#include <productList.hpp>
#include <limits>
#include <menu.hpp>
#include <conio.h>
#include <admin.routes.hpp>
#include <clientQueue.hpp>
#include <client.hpp>
#include <random>
#include <chrono>
#include <thread>

void processClient(ClientQueue &clientQueue)
{
    while (!clientQueue.isEmpty())
    {

        Client client = clientQueue.getNextClient();

        auto start = std::chrono::high_resolution_clock::now();

        // Aquí puedes agregar el código para procesar al cliente

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        if (elapsed.count() > 10 * 30)
        {                                  // Si el cliente tardó más de 10 minutos
            clientQueue.addClient(client); // Añadir al cliente al final de la cola
        }
    }
}

int main()
{
    std::vector<std::string> names = {"Alice", "Bob", "Charlie", "Dave"};
    std::vector<std::string> lastNames = {"Johnson", "Smith", "Williams", "Brown"};

    std::default_random_engine generator;
    std::uniform_int_distribution<int> nameDistribution(0, names.size() - 1);
    std::uniform_int_distribution<int> phoneDistribution(1000000, 9999999);

    int phoneNumber = phoneDistribution(generator);

    ClientQueue clientQueue = ClientQueue();

    while (true)
    {
        Client newClient = Client(names[nameDistribution(generator)], lastNames[nameDistribution(generator)], 1, phoneNumber);
        std::this_thread::sleep_for(std::chrono::seconds(4));
        clientQueue.addClient(newClient);

        processClient(clientQueue);
    }

    Menu menu({{"1. CMS", adminRoutes},
               {"Salir", [&menu]()
                { menu.exitOption(); }}});
    menu.navigate();

    return 0;
}
