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
     */
    Product();

    /**
     * @brief Construct a new Product object
     * @param name
     * @param description
     * @param price
     * @param stock
     */
    Product(std::string name, std::string description, double price, int stock);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getStock() const;
    int getId() const;
    std::string getInfo() const;

    // Setters
    void setPrice(double price);
    void setStock(int stock);
    void setName(std::string name);
    void setDescription(std::string description);
    void setId(int id);

private:
    std::string name;
    std::string description;
    double price;
    int stock;
    int id;
};

#endif // PRODUCT_HPP