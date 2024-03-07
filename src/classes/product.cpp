#include <product.hpp>

Product::Product()
{
}

/**
 * @brief Constructs a new Product object.
 * 
 * @param name The name of the product.
 * @param description The description of the product.
 * @param price The price of the product.
 * @param stock The stock quantity of the product.
 * @param id The unique identifier of the product.
 */
Product::Product(std::string name, std::string description, double price, int stock)
    : name(name), description(description), price(price), stock(stock)
{
}

// Getters

/**
 * @brief Get the name of the product
 * @return std::string
 */
std::string Product::getName() const
{
    return name;
}

/**
 * @brief Get the description of the product
 * @return std::string
 */
std::string Product::getDescription() const
{
    return description;
}

/**
 * @brief Get the price of the product
 * @return int
 */
double Product::getPrice() const
{
    return price;
}

/**
 * @brief Get the stock of the product
 * @return int
 */
int Product::getStock() const
{
    return stock;
}

/**
 * @brief Get the id of the product
 * @return int
 */
int Product::getId() const
{
    return id;
}

/**
 * @brief Get all the information of the product
 * @return std::string
 */
std::string Product::getInfo() const
{
    return "ID: " + std::to_string(id) + "\nName: " + name + "\nDescription: " + description + "\nPrice: " + std::to_string(price) + "\nStock: " + std::to_string(stock);
}

// setters

/**
 * @brief Set the name of the product
 * @param name
 */
void Product::setName(std::string name)
{
    this->name = name;
}

/**
 * @brief Set the description of the product
 * @param description
 */
void Product::setDescription(std::string description)
{
    this->description = description;
}

/**
 * @brief Set the price of the product
 * @param price
 */
void Product::setPrice(double price)
{
    this->price = price;
}

/**
 * @brief Set the stock of the product
 * @param stock
 */
void Product::setStock(int stock)
{
    this->stock = stock;
}

/**
 * @brief Set the id of the product
 * @param id
 */
void Product::setId(int id)
{
    this->id = id;
}