#include <admin.routes.hpp>
#include <menu.hpp>
#include <product.hpp>
#include <productList.hpp>
#include <admin.controllers.hpp>

void adminProductRoutes()
{
    Menu menu({{"Agregar producto", addProduct},
               {"Actualizar producto", updateProduct},
               {"Eliminar producto", removeProduct},
               {"Ver productos", displayProducts},
               {"Salir", [&menu]()
                {
                    menu.exitOption();
                }}});

    menu.navigate();
}

void adminRoutes()
{
    Menu menu({{"1. Productos", adminProductRoutes},
               {"Salir", [&menu]()
                {
                    menu.exitOption();
                }}});

    menu.navigate();
}