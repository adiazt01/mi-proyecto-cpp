#include <iostream>
#include <menu.hpp>
#include <admin.routes.hpp>
#include <simulate.routes.hpp>

int main()
{
    Menu menu({{"1. Administrar contenido", adminRoutes},
               {"2. Trabajar", simulateRoutes},
               {"3. Salir", [&menu]()
                { menu.exitOption(); }}});
    menu.navigate();

    return 0;
}
