#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>
#include "product.hpp"
#include "productList.hpp"
#include "bill.hpp"
#include "billList.hpp"

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

    // Product methods
    void addProduct(const Product &product);
    void removeProduct(int id);
    void updateProduct(int id, const Product &product);
    void reduceStock(int id, int quantity);

    Product getProduct(int id);
    ProductList getProducts();

    // Bill methods
    void addBill(const Bill &bill);
    BillList getBills();

private:
    Database(){}

    BillList bills;
    ProductList products;
};

#endif // DATABASE_HPP