#include <client.hpp>


/**
 * @brief Constructs a new Client object.
 * 
 * @param name The name of the client.
 * @param lastname The last name of the client.
 * @param id The ID of the client.
 * @param phonenumber The phone number of the client.
 */
Client::Client(std::string name, std::string lastname, int id, long long phonenumber)
    : name(name), lastname(lastname), id(id), phonenumber(phonenumber)
{
};

/**
 * @brief Destructor for the Client class.
 * 
 * This destructor is responsible for cleaning up any resources
 * allocated by the Client class.
 */
Client::~Client()
{
};

/**
 * @brief Get the name of the client.
 * 
 * @return std::string The name of the client.
 */
std::string Client::getName()
{
    return name;
};

/**
 * @brief Get the last name of the client.
 * 
 * @return std::string The last name of the client.
 */
std::string Client::getLastname()
{
    return lastname;
};

/**
 * @brief Get the ID of the client.
 * 
 * @return int The ID of the client.
 */
int Client::getId()
{
    return id;
};

/**
 * @brief Get the phone number of the client.
 * 
 * @return The phone number of the client.
 */
long long Client::getPhonenumber()
{
    return phonenumber;
};

/**
 * @brief Sets the name of the client.
 * 
 * This function sets the name of the client to the specified value.
 * 
 * @param name The name of the client.
 */
void Client::setName(std::string name)
{
    this->name = name;
};

/**
 * @brief Sets the last name of the client.
 * 
 * This function sets the last name of the client to the specified value.
 * 
 * @param lastname The last name of the client.
 */
void Client::setLastname(std::string lastname)
{
    this->lastname = lastname;
};

/**
 * @brief Sets the ID of the client.
 * 
 * This function sets the ID of the client to the specified value.
 * 
 * @param id The ID of the client.
 */
void Client::setId(int id)
{
    this->id = id;
};

/**
 * @brief Sets the phone number of the client.
 * 
 * This function sets the phone number of the client to the specified value.
 * 
 * @param phonenumber The phone number of the client.
 */
void Client::setPhonenumber(long long phonenumber)
{
    this->phonenumber = phonenumber;
};

