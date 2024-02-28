#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <shoppingCart.hpp>

/**
 * @brief The Client class represents a client in the system.
 * 
 * This class stores information about a client, such as their name, lastname, ID, and phone number.
 * It also contains a shopping cart object associated with the client.
 */
class Client
{
public:

    /**
     * @brief Constructs a new Client object with the given parameters.
     * 
     * @param name The name of the client.
     * @param lastname The lastname of the client.
     * @param id The ID of the client.
     * @param phonenumber The phone number of the client.
     */
    Client(std::string name, std::string lastname, int id, long long phonenumber);

    /**
     * @brief Destroys the Client object.
     */
    ~Client();

    /**
     * @brief Gets the name of the client.
     * 
     * @return The name of the client.
     */
    std::string getName();

    /**
     * @brief Gets the lastname of the client.
     * 
     * @return The lastname of the client.
     */
    std::string getLastname();

    /**
     * @brief Gets the ID of the client.
     * 
     * @return The ID of the client.
     */
    int getId();

    /**
     * @brief Gets the phone number of the client.
     * 
     * @return The phone number of the client.
     */
    long long getPhonenumber();

    Shoppingcart shoppingcart;

    /**
     * @brief Sets the name of the client.
     * 
     * @param name The name of the client.
     */
    void setName(std::string name);

    /**
     * @brief Sets the lastname of the client.
     * 
     * @param lastname The lastname of the client.
     */
    void setLastname(std::string lastname);

    /**
     * @brief Sets the ID of the client.
     * 
     * @param id The ID of the client.
     */
    void setId(int id);

    /**
     * @brief Sets the phone number of the client.
     * 
     * @param phonenumber The phone number of the client.
     */
    void setPhonenumber(long long phonenumber);

private:    
    std::string name; /**< The name of the client. */
    std::string lastname; /**< The lastname of the client. */
    int id; /**< The ID of the client. */
    long long phonenumber; /**< The phone number of the client. */
}

#endif CLIENT_HPP