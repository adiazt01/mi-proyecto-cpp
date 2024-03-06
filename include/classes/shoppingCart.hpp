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

    void clearCart();
    
    double getTotalPrice();
    
private:
    std::vector<Product> products;

    double totalPrice;
    double totalTax;
    double totalCost;
};

#endif // SHOPPINGCART_HPP