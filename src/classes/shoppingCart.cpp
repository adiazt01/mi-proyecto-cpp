#include <shoppingCart.hpp>

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
    totalTax += produ
}