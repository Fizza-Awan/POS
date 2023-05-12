#pragma once
#ifndef _PLATINUMCUSTOMER_
#define _PLATINUMCUSTOMER_

#include "Customer.h"

class PlatinumCustomer :
    public Customer
{
    float Discount;

public:
    float get_discount() const;
    void set_discount(float discount);
    PlatinumCustomer(const string& cnic, const string& name, const string& address, const std::string& phone, const std::string& email);
};
#endif
