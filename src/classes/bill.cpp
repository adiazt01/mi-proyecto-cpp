#include "bill.hpp"

Bill::Bill(std::string name, std::string lastname, std::string numberPhone, std::vector<Product> products, double total)
    : id(id), name(name), lastname(lastname), numberPhone(numberPhone), products(products), total(total){};

std::string Bill::getName()
{
    return name;
}

std::string Bill::getLastname()
{
    return lastname;
}

std::string Bill::getNumberPhone()
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

void Bill::setNumberPhone(std::string numberPhone)
{
    this->numberPhone = numberPhone;
}

void Bill::setId(int id)
{
    this->id = id;
}