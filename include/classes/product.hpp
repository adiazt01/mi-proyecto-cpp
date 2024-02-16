#include <string>

/**
 * @class Product
 * @brief Create a Product object
 */
class Product
{
public:
    /**
     * @brief Construct a new Product object
     *
     * @param name  The name of the product
     * @param description  The description of the product
     * @param price  The price of the product
     * @param stock  The stock of the product
     * @param id  The id of the product
     */
    Product(std::string name, std::string description, double price, int stock, int id);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getStock() const;
    int getID() const;
    std::string getInfo() const;

    // Setters
    void setName(std::string name);
    void setDescription(std::string description);
    void setPrice(double price);
    void setStock(int stock);

private:
    std::string name;
    std::string description;
    double price;
    int stock;
    int id;
};
