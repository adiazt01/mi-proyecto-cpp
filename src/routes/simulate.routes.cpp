#include <simulate.controllers.hpp>
#include <simulate.routes.hpp>
#include <clientQueue.hpp>
#include <menu.hpp>
#include "globals.hpp"

void simulateRoutes()
{
    Menu menu({{"Simular", []()
                {
                    continueSimulation = true;
                    simulateShop();
                }},
               {"Salir", [&menu]()
                {
                    continueSimulation = false;
                    menu.exitOption();
                }}});

    menu.navigate();
}