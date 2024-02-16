#include <iostream>
#include "product.hpp"

int main()
{
    Product product("Pan", "Un fucking pan", 3, 20.0, 5);
    std::cout << product.getInfo(); 
    return 0;
}