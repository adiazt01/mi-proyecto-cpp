#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include <iostream>
#include <vector>
#include <string>
#include "product.hpp"

class ShoppingCart
{
public:
    ShoppingCart();

    void addProduct(Product product);
    void removeProduct(Product product);

    void clearCart();
    void displayProducts();
    void checkout();
    void setTotalPrice(double price);
    double getTotalPrice();
    void setTotalTax(double tax);
    double getTotalTax();
    void setTotalCost(double cost);
    double getTotalCost();

private:
    std::vector<Product> products;

    double totalPrice;
    double totalTax;
    double totalCost;
};

#endif // SHOPPINGCART_HPP