#include <iostream>
#include "product.hpp"
#include "productList.hpp"
#include <limits>
#include "menu.hpp"
#include <conio.h>

// Classes => ?Base de datos (Admin, la lista de productos, ventas, facturas, etc)
// Controllers => Controlar las distintas opciones del meno
// libs => Permite funciones que se repiten a lo largo del codigo (Validaciones de datos)


void helloWorld()
{
    std::cout << "Hola mundo\n";
}

void exitOption()
{
    std::cout << "Saliendo...\n";
    exit(0);
}

int main()
{
    ProductList DBProduct;

    Product testProduct("Test", "Waos e velda que el ingles abre pueltas", 32.4, 32, 5);

    DBProduct.addProduct(testProduct);

    DBProduct.getProduct(5).getInfo();

    std::vector<Product> products = DBProduct.getProducts();

    Menu menu(
        {{"Hola mundo desde el menu", helloWorld}, {"Exit", exitOption}, {"Ver productos", [&products]()
                                                                          {
                                                                              for (int i = 0; i < products.size(); i++)
                                                                              {
                                                                                  std::cout << products[i].getInfo() << std::endl;
                                                                              }
                                                                          }}});
    menu.navigate();

    return 0;
}