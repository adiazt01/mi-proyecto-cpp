#ifndef BILL_HPP
#define BILL_HPP

#include <vector>
#include "product.hpp"

class Bill
{
public:
    Bill(std::string name, std::string lastname, std::string numberPhone, std::vector<Product> products, double total);

    std::string getName();
    std::string getLastname();
    std::string getNumberPhone();
    int getId();

    void setName(std::string name);
    void setLastname(std::string lastname);
    void setNumberPhone(std::string numberPhone);
    void setId(int id);

private:
    int id;
    std::string name;
    std::string lastname;
    std::string numberPhone;
    std::vector<Product> products;
    double total;
};

#endif // BILL_HPP