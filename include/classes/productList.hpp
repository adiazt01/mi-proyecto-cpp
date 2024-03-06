#ifndef PRODUCTLIST_HPP
#define PRODUCTLIST_HPP

#include <vector>
#include "product.hpp"

class ProductList
{
public:
    ProductList() : nextId(1) {}

    void addProduct(Product product);
    void removeProduct(int id);
    void updateProduct(int id, Product product);
    void reduceStock(int id, int quantity);

    size_t size();

    // Añade este operador para acceder a los elementos por índice
    Product &operator[](size_t index)
    {
        return products[index];
    }

    // Y este para acceder a los elementos por índice en instancias const
    const Product &operator[](size_t index) const
    {
        return products[index];
    }

    Product getProduct(int id);
    std::vector<Product> getProducts();

private:
        std::vector<Product> products;
    int nextId;
};

#endif // PRODUCTLIST_HPP