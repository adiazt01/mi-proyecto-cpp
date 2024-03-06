#ifndef BILL_LIST_HPP
#define BILL_LIST_HPP

#include <iostream>
#include <bill.hpp>
#include <vector>

class BillList
{
public:
    BillList() : nextId(1) {}

    void addBill(Bill bill);

    Bill getBill(int id);

    std::vector<Bill> getAllBills();

private:
    std::vector<Bill> bills;
    int nextId;
};

#endif
