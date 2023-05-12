#pragma once
#ifndef _GOLDCUSTOMER_
#define _GOLDCUSTOMER_

#include "Customer.h"

class GoldCustomer :
    public Customer
{
    float Discount;

public:
    float get_discount() const;
    void set_discount(float discount);
    GoldCustomer(const string& cnic, const string& name, const string& address, const std::string& phone, const std::string& email);
};
#endif
