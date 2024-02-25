#include "productList.hpp"

/**
 * @brief Allow initialize of the database of products
 */
ProductList::ProductList(){};

/**
 * @brief Add a product to the list
 * @param product
 */
void ProductList::addProduct(Product product)
{
    products.push_back(product);
}

/**
 * @brief Remove a product from the list
 * @param id
 */
void ProductList::removeProduct(int id)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getID() == id)
        {
            products.erase(products.begin() + i);
            return;
        }
    }
}

/**
 * @brief Update a product from the list
 * @param id
 * @param product
 */
void ProductList::updateProduct(int id, Product product)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getID() == id)
        {
            products[i] = product;
            return;
        }
    }
}

/**
 * @brief Get a product from the list
 * @param id
 * @return Product
 */
Product ProductList::getProduct(int id)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getID() == id)
        {
            return products[i];
        }
    }
    return Product("", "", 0, 0, 0);
}

/**
 * @brief Reduce the stock of a product
 * @param id
 * @param quantity
 * @return Product
 */
Product ProductList::reduceStock(int id, int quantity)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getID() == id)
        {
            products[i].setStock(products[i].getStock() - quantity);
            return products[i];
        }
    }
    return Product("", "", 0, 0, 0);
}

/**
 * @brief Get all the products from the list
 * @return std::vector<Product>
 */
std::vector<Product> ProductList::getProducts()
{
    return products;
}
