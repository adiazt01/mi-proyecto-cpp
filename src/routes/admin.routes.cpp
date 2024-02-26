#include <admin.routes.hpp>
#include <menu.hpp>
#include <product.hpp>
#include <productList.hpp>

void adminRoutes()
{
    Menu menu({{"Agregar producto", addProduct},
               {"Eliminar producto", removeProduct},
               {"Ver productos", displayProducts},
               {"Salir", exitOption}})
    menu.navigate();
}