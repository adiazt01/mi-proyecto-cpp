#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>

/**
 * @class Product
 * @brief Create a Product object
 * @details This class is used to create a product object
 */
class Product
{
public:
    /**
     * @brief Construct a new Product object
     * @param name
     * @param description
     * @param price
     * @param stock
     * @param id
     */
    Product(std::string name, std::string description, double price, int stock, int id);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getStock() const;
    int getID() const;
    std::string getInfo() const;

private:
    void setName(std::string name);
    void setDescription(std::string description);
    void setPrice(double price);
    void setStock(int stock);

    std::string name;
    std::string description;
    double price;
    int stock;
    int id;
};

#endif // PRODUCT_HPP