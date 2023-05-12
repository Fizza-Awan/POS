#pragma once
#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <string>

using std::string;

class Customer
{
	string CNIC;
	string Name;
	string Address;
	string Phone;
	string Email;
	float AmountPayable;
	float SalesLimit;

	int n_sale;
	string Type;

public:
	Customer();
	static int n_customer;
	string get_cnic() const;
	void set_cnic(const string& cnic);
	string get_name() const;
	void set_name(const string& name);
	string get_address() const;
	void set_address(const string& address);
	string get_phone() const;
	void set_phone(const string& phone);
	string get_email() const;
	void set_email(const string& email);
	float get_amount_payable() const;
	void set_amount_payable(float amount_payable);
	float get_sales_limit() const;
	void set_sales_limit(float sales_limit);
	bool isNotAssociatedYet();
	void set_type(const string& type);
	string get_type();
};
#endif
