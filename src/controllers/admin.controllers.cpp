#include <admin.controllers.hpp>
#include <database.hpp>
#include <product.hpp>
#include <menu.hpp>
#include <iostream>
#include <limits>

Database &db = Database::getInstance();

void addProduct()
{
    system("cls");

    std::string name;
    std::string description;
    double price;
    int stock;

    std::cout << "Nombre: ";
    std::getline(std::cin, name);

    std::cout << "Descripcion: ";
    std::getline(std::cin, description);

    std::cout << "Precio: ";
    while (!(std::cin >> price))
    {
        std::cout << "Por favor, ingresa un número válido para el precio: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Stock: ";
    while (!(std::cin >> stock))
    {
        std::cout << "Por favor, ingresa un número válido para el stock: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore();

    Product product(name, description, price, stock, 1);
    db.addProduct(product);
}

void removeProduct()
{
    system("cls");

    int id;
    std::cout << "ID del producto: ";
    while (!(std::cin >> id))
    {
        std::cout << "Por favor, ingresa un número válido para el ID del producto: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    db.removeProduct(id);
}

void displayProducts()
{
    system("cls");

    ProductList products = db.getProducts();

    for (int i = 0; i < products.size(); i++)
    {
        std::cout << "ID: " << products[i].getId() << std::endl;
        std::cout << "Nombre: " << products[i].getName() << std::endl;
        std::cout << "Descripcion: " << products[i].getDescription() << std::endl;
        std::cout << "Precio: " << products[i].getPrice() << std::endl;
        std::cout << "Stock: " << products[i].getStock() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    };
}