#include <shoppingCart.hpp>
#include <product.hpp>
#include <vector>
#include <string>
#include <iostream>

ShoppingCart::ShoppingCart()
{
    totalPrice = 0;
    totalTax = 0;
    totalCost = 0;
}


void ShoppingCart::addProduct(Product product)
{
    products.push_back(product);
    totalPrice += product.getPrice();
}

void ShoppingCart::clearCart()
{
    products.clear();
    totalPrice = 0;
    totalTax = 0;
    totalCost = 0;
}