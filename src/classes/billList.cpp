#include <iostream>
#include <bill.hpp>
#include <billList.hpp>
#include <product.hpp>
#include <productList.hpp>
#include <map>

/**
 * @brief Add a bill to the list
 * @param bill
 */
void BillList::addBill(Bill bill)
{
    bill.setId(nextId++);
    bills.push_back(bill);
}

/**
 * @brief Get a bill from the list
 * @param id
 * @return Bill
 */
Bill BillList::getBill(int id)
{
    for (auto bill : bills)
    {
        if (bill.getId() == id)
        {
            return bill;
        }
    }
    throw std::runtime_error("Bill not found");
}

/**
 * @brief Get all bills from the list
 */
std::vector<Bill> BillList::getAllBills()
{
    return bills;
}