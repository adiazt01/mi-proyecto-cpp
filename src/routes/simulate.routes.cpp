#include <simulate.controllers.hpp>
#include <simulate.routes.hpp>
#include <clientQueue.hpp>
#include <menu.hpp>
#include "globals.hpp"

void simulateRoutes()
{
    Menu menu({{"1. Simular", []()
                {
                    continueSimulation = true;
                    simulateShop();
                }},
               {"2. Salir", [&menu]()
                {
                    continueSimulation = false;
                    menu.exitOption();
                }}});

    menu.navigate();
}