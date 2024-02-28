#include "productList.hpp"
#include <iostream>


/**
 * @brief Add a product to the list
 * @param product
 */
void ProductList::addProduct(Product product)
{
    product.setId(nextId++);
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
        if (products[i].getId() == id)
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
        if (products[i].getId() == id)
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
        if (products[i].getId() == id)
        {
            return products[i];
        }
    }
    return Product("", "", 0, 0, 0);
}

/**
 * @brief Get the size of the list
 * @return size_t
 */
size_t ProductList::size()
{
    return products.size();
}

/**
 * @brief Reduce the stock of a product
 * @param id
 * @param quantity
 * @return Product
 */
void ProductList::reduceStock(int id, int quantity)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].getId() == id)
        {
            if (products[i].getStock() >= quantity)
            {
                products[i].setStock(products[i].getStock() - quantity);
            }
            else
            {
                std::cerr << "Error:No hay suficiente cantidades del producto " << id << "\n";
                return;
            }
        }
    }
    std::cerr << "Error: Product ID " << id << " not found\n";
}

/**
 * @brief Get all the products from the list
 * @return std::vector<Product>
 */
std::vector<Product> ProductList::getProducts()
{
    return products;
}
