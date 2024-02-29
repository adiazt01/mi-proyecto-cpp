#include <iostream>
#include <menu.hpp>
#include <admin.routes.hpp>
#include <simulate.controllers.hpp>
#include <simulate.controllers.hpp>

int main()
{
    Menu menu({{"1. Administrar contenido", adminRoutes},
                {"2. Trabajar", simulate},
               {"Salir", [&menu]()
                { menu.exitOption(); }}});
    menu.navigate();

    return 0;
}
