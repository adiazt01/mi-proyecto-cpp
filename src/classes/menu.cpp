#include <iostream>
#include <menu.hpp>
#include <conio.h>
#include <vector>
#include <functional>

Menu::Menu(const std::vector<std::pair<std::string, std::function<void()>>> &options)
    : options(options)
{
}

void Menu::display() const
{
    for (int i = 0; i < options.size(); ++i)
    {
        std::cout << (i == option ? "> " : "  ") << options[i].first << "\n";
    }
}

void Menu::navigate()
{
    int key = 0;

    do
    {
        system("cls");
        display();

        key = _getch();

        if (key == 72)
        { // Tecla de flecha arriba
            if (option > 0)
            {
                option--;
            }
        }
        else if (key == 80)
        { // Tecla de flecha abajo
            if (option < options.size() - 1)
            {
                option++;
            }
        }

        if (key == 13)
        {                             // Tecla Enter
            options[option].second(); // Ejecuta la función de la opción seleccionada
            if (exit)
                break; // Si la opción seleccionada es "Exit", sale del bucle
            std::cout << "Presiona cualquier tecla para continuar.\n";
            _getch(); // Espera a que el usuario presione una tecla
        }
    } while (true);
}
