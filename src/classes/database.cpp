#include <product.hpp>
#include <productList.hpp>
#include <database.hpp>

/// @brief Adds a product to the database
/// @param product 
void Database::addProduct(const Product &product)
{
    products.addProduct(product);
}

/// @brief Removes a product from the database
/// @param id 
void Database::removeProduct(int id)
{
    products.removeProduct(id);
}

/// @brief Updates a product in the database
/// @param id 
/// @param product 
void Database::updateProduct(int id, const Product &product)
{
    products.updateProduct(id, product);
}

/// @brief Reduces the stock of a product in the database
/// @param id 
/// @param quantity 
void Database::reduceStock(int id, int quantity)
{
    products.reduceStock(id, quantity);
}

/// @brief Gets a product from the database
/// @param id 
/// @return Product
Product Database::getProduct(int id)
{
    return products.getProduct(id);
}

ProductList Database::getProducts()
{
    return products;
}



