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
    clients.push(client);
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
bool ClientQueue::isEmpty() const
{
    return clients.empty();
};

/**
 * @brief Get the size of the queue
 * @return int
 */
int ClientQueue::getSize() const
{
    return clients.size();
}