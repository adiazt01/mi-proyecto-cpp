#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <vector>
#include "product.hpp"
#include "productList.hpp"

class Database
{
public:
    Database();

private:
    ProductList products;
};
