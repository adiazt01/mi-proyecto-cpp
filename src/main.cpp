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
    Menu menu(
        {{"\033[32mProducto agregado exitosamente!\033[0m", helloWorld}, {"Exit", exitOption}});

    menu.navigate();

    return 0;
}