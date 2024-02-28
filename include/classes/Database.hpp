#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>
#include "product.hpp"
#include "productList.hpp"

class Database
{
public:

    static Database &getInstance()
    {
        static Database instance;
        return instance;
    }

    Database(Database const &) = delete;
    void operator=(Database const &) = delete;

    void addProduct(const Product &product);
    void removeProduct(int id);
    void updateProduct(int id, const Product &product);
    void reduceStock(int id, int quantity);

    Product getProduct(int id);
    ProductList getProducts();

private:
    Database(){}

    ProductList products;
};

#endif // DATABASE_HPP