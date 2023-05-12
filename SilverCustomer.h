#pragma once
#ifndef _SILVERCUSTOMER
#define _SILVERCUSTOMER_

#include "Customer.h"

class SilverCustomer :
    public Customer
{
public:
	SilverCustomer(const string& cnic, const string& name, const string& address, const std::string& phone, const std::string& email);
};
#endif
