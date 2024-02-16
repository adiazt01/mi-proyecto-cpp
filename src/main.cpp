#include <iostream>
#include "product.hpp"
#include <limits>
#include "menu.hpp"
#include <conio.h>

int main()
{

    /* Test del menu y primera funcionalidad */
    Menu menu({
        {"Agregar producto", []()
         {
             std::string name;
             std::string description;
             float price;
             int stock;
             int id;

             std::cout << "Nombre: ";
             std::cin >> name;
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la nueva línea

             std::cout << "Descripcion: ";
             std::getline(std::cin, description);

             std::cout << "Precio: ";
             std::cin >> price;

             std::cout << "Stock: ";
             std::cin >> stock;

             std::cout << "Id: ";
             std::cin >> id;

             Product newProduct(name, description, price, stock, id);
             std::cout << newProduct.getInfo();
         }},
        {"Listar productos", []()
         {
             std::cout << "Presiona cualquier tecla para continuar.\n";
             _getch();
         }},
        {"Salir", []()
         {
             std::cout << "Saliendo...\n";
             exit(0);
         }},
    });

    menu.navigate();

    return 0;
}