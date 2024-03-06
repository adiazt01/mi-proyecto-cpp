#ifndef CLIENTQUEUE_HPP
#define CLIENTQUEUE_HPP

#include <iostream>
#include <queue>
#include <client.hpp>

class ClientQueue
{
public:
    ClientQueue();

    void addClient(Client client);

    void removeClient();

    Client getNextClient();

    bool isEmpty() const;

    int getSize() const;

private:
    std::queue<Client> clients;
};

#endif // CLIENTQUEUE_HPP