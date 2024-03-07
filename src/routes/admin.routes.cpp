#include <admin.routes.hpp>
#include <menu.hpp>
#include <product.hpp>
#include <productList.hpp>
#include <admin.controllers.hpp>

void adminProductRoutes()
{
    Menu menu({{"1. Agregar producto", addProduct},
               {"2. Actualizar producto", updateProduct},
               {"3. Eliminar producto", removeProduct},
               {"4. Ver productos", displayProducts},
               {"5. Salir", [&menu]()
                {
                    menu.exitOption();
                }}});

    menu.navigate();
}

void adminSalesRoutes()
{
    Menu menu({{"1. Clientes presentados", showTotalClientsPresented},
               {"2. Clientes que completaron compra", showNumClientsCompletedPurchase},
               {"3. Producto mas vendido", showMostSoldProduct},
               {"4. Ver ventas", showSales},
               {"5. Salir", [&menu]()
                {
                    menu.exitOption();
                }}});

    menu.navigate();
}

void adminRoutes()
{
    Menu menu({{"1. Productos", adminProductRoutes},
               {"2. Ventas", adminSalesRoutes},
               {"Salir", [&menu]()
                {
                    menu.exitOption();
                }}});

    menu.navigate();
}