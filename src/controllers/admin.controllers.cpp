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

    Product product(name, description, price, stock);
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

        // Pregunta al usuario si desea continuar
        std::cout << "¿Deseas continuar? (s/n): ";
        char answer;
        std::cin >> answer;
        if (answer == 'n' || answer == 'N')
        {
            return; // Salir de la función
        }
    }

    try
    {
        Product product = db.getProduct(id);
        db.removeProduct(id);
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "No se encontró el producto con el ID: " << id << std::endl;
    }
}

void updateProduct()
{
    system("cls");

    int id;
    std::cout << "ID del producto: ";
    while (!(std::cin >> id))
    {
        std::cout << "Por favor, ingresa un número válido para el ID del producto: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Pregunta al usuario si desea continuar
        std::cout << "¿Deseas continuar? (s/n): ";
        char answer;
        std::cin >> answer;
        if (answer == 'n' || answer == 'N')
        {
            return; // Salir de la función
        }
    }
    std::cin.ignore();

    try
    {
        Product product = db.getProduct(id); // Buscar el producto

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

        product.setName(name);
        product.setDescription(description);
        product.setPrice(price);
        product.setStock(stock);

        db.updateProduct(id, product); // Actualizar el producto
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "No se encontró el producto con el ID: " << id << std::endl;
    }
}

void displayProducts()
{
    system("cls");

    if (db.getProducts().size() > 0)
    {
        std::cout << "----------------------------------------\n";
        std::cout << "       Información de los Productos\n";
        std::cout << "----------------------------------------\n";
        for (int i = 0; i < db.getProducts().size(); i++)
        {
            std::cout << db.getProducts()[i].getInfo() << "\n";
            std::cout << "----------------------------------------\n";
        }
    }
    else
    {
        std::cout << "No hay productos registrados." << std::endl;
    }

    std::cout << "Presione Enter para continuar...";
    std::cin.get();
}

void showTotalClientsPresented()
{
    system("cls");

    if (db.getNumClientsPresented() > 0)
    {
        std::cout << "Total de clientes presentados: " << db.getNumClientsPresented() << std::endl;

        for (int i = 0; i < db.getNumClientsPresented(); i++)
        {
            Client client = db.getNextClient();
            std::cout << "Cliente: " << client.getName() << " " << client.getLastname() << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
    }
    else
    {
        std::cout << "No hay clientes presentados." << std::endl;
    }

    std::cout << "Presione Enter para continuar...";
    std::cin.get();
}

void showNumClientsCompletedPurchase()
{
    system("cls");

    if (db.getNumClientsCompletedPurchase() > 0)
    {
        std::cout << "Clientes que han completado una compra: " << std::endl;
        BillList bills = db.getBills();
        for (int i = 0; i < bills.size(); i++)
        {
            std::cout << "Cliente: " << bills[i].getName() << std::endl;
            std::cout << "Total: " << bills[i].getTotal() << std::endl;
            std::cout << "-----------------------------------" << std::endl;
        }
    }
    else
    {
        std::cout << "No hay clientes que hayan completado una compra." << std::endl;
    }

    std::cout << "Presione Enter para continuar...";
    std::cin.get();
}

void showMostSoldProduct()
{
    system("cls");

    std::pair<Product, int> mostSoldProduct = db.getMostSoldProduct();

    if (mostSoldProduct.second > 0)
    {

        int productId = mostSoldProduct.first.getId();
        Product product = db.getProduct(productId);

        std::cout << "----------------------------------------\n";
        std::cout << "       Información del Producto\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Nombre del producto más vendido: " << product.getName() << "\n";
        std::cout << "Cantidad vendida de este producto: " << mostSoldProduct.second << "\n";
        std::cout << "----------------------------------------\n";
    }
    else
    {
        std::cout << "No hay productos vendidos." << std::endl;
    }

    std::cout << "Presione Enter para continuar...";
    std::cin.get();
}

void showSales()
{
    system("cls");

    if (db.getBills().size() > 0)
    {
        std::cout << "----------------------------------------\n";
        std::cout << "       Información de las Ventas\n";
        std::cout << "----------------------------------------\n";
        for (int i = 0; i < db.getBills().size(); i++)
        {
            std::cout << db.getBills()[i].getInfo() << "\n";
            std::cout << "----------------------------------------\n";
        }
    }
    else
    {
        std::cout << "No hay ventas registradas." << std::endl;
    }

    std::cout << "Presione Enter para continuar...";
    std::cin.get();
}