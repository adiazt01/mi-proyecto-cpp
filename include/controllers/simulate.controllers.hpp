#ifndef SIMULATE_CONTROLLERS_H
#define SIMULATE_CONTROLLERS_H

#include <iostream>
#include <clientQueue.hpp>
#include <client.hpp>
#include <product.hpp>
#include <database.hpp>
#include <random>
#include <chrono>

void processClient(Database &db, std::default_random_engine &generator, std::uniform_int_distribution<int> &productDistribution, std::uniform_int_distribution<int> &timeDistribution, int numProducts);

void simulateShop();

void simulate();

#endif // SIMULATE_CONTROLLERS_H