#include "bill.hpp"

Bill::Bill(std::string name, std::string lastname, long long int numberPhone, std::vector<Product> products, double total)
    : id(id), name(name), lastname(lastname), numberPhone(numberPhone), products(products), total(total){};

std::string Bill::getName()
{
    return name;
}

std::string Bill::getLastname()
{
    return lastname;
}

long long int Bill::getNumberPhone()
{
    return numberPhone;
}

int Bill::getId()
{
    return id;
}

void Bill::setName(std::string name)
{
    this->name = name;
}

void Bill::setLastname(std::string lastname)
{
    this->lastname = lastname;
}

void Bill::setNumberPhone(long long int numberPhone)
{
    this->numberPhone = numberPhone;
}

void Bill::setId(int id)
{
    this->id = id;
}