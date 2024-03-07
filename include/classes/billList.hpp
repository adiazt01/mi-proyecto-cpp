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

    Bill& operator[](int index) {
        return bills[index];
    }

     size_t size() const {
        return bills.size();
    }

    

    std::vector<Bill> getAllBills();

private:
    std::vector<Bill> bills;
    int nextId;
};

#endif
