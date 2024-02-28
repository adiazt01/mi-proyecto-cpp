#include <clientQueue.hpp>
#include <client.hpp>
#include <iostream>
#include <queue>
#include <string>


/**
 * @brief Construct a new Client Queue object
 */
ClientQueue::ClientQueue(){};

/**
 * @brief Add a client to the queue
 * @param client
 */
void ClientQueue::addClient(Client client)
{
    std::cout << "Añadiendo a " << client.getName() << " a la cola" << std::endl;
    clients.push(client);
};

/**
 * @brief Remove a client from the queue
 */
void ClientQueue::removeClient()
{
    clients.pop();
};

/**
 * @brief Display all clients in the queue
 */
void ClientQueue::displayClients()
{
    std::queue<Client> temp = clients;
    while (!temp.empty())
    {
        std::cout << temp.front().getName() << std::endl;
        temp.pop();
    };
};

/**
 * @brief Get the next client in the queue
 * @return Client
 */
Client ClientQueue::getNextClient()
{
    if (clients.empty())
    {
        throw std::out_of_range("No hay más clientes en la cola");
    }
    
    Client nextClient = clients.front();
    clients.pop();
    return nextClient;
};

/**
 * @brief Check if the queue is empty
 * @return bool
 */
bool ClientQueue::isEmpty()
{
    return clients.empty();
};