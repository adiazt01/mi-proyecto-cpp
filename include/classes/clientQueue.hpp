#ifndef CLIENTQUEUE_HPP
#define CLIENTQUEUE_HPP

#include <iostream>
#include <queue>
#include <client.hpp>

class ClientQueue {
    public:
        ClientQueue();

        void addClient(Client client);

        Client getNextClient();

        bool isEmpty();

        void removeClient();

        void displayClients();
    private:
        std::queue<Client> clients;
};

#endif // CLIENTQUEUE_HPP