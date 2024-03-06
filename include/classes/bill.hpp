#ifndef BILL_HPP
#define BILL_HPP

#include <vector>
#include "product.hpp"

/**
 * @brief Bill class
 */
class Bill
{
public:
    /**
     * @brief Construct a new Bill object
     *
     * @param name
     * @param lastname
     * @param numberPhone
     * @param products
     * @param total
     */
    Bill(std::string name, std::string lastname, long long int numberPhone, std::vector<Product> products, double total);

    std::string getName();
    std::string getLastname();
    long long int getNumberPhone();
    int getId();

    void setName(std::string name);
    void setLastname(std::string lastname);
    void setNumberPhone(long long int numberPhone);
    void setId(int id);

private:
    int id;
    std::string name;
    std::string lastname;
    long long int numberPhone;
    std::vector<Product> products;
    double total;
};

#endif // BILL_HPP