#pragma once

#ifndef _CUSTOMER_
#define _CUSTOMER_

#include <string>

#include "Sale.h"

class Sale;

using std::string;

enum CustomerTypes {
	Silver,
	Gold,
	Platinum
};

class Customer
{
	string CNIC;
	string Name;
	string Address;
	string Phone;
	string Email;
	float AmountPayable;
	float SalesLimit;
	CustomerTypes Type;

	Sale** sales;
	int n_sale;
public:
	//Customer(CustomerTypes Type);
	~Customer();
	static Customer* GetCustomer(string CNIC, string Name, string Address, string Phone, string Email, CustomerTypes Type);
	int get_n_sale() const;
	void set_n_sale(int n_sale);
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
	void set_type(const CustomerTypes& type);
	CustomerTypes get_type();
	void addSale(Sale* sale);
	float getTotalSalesAmount();
};
#endif
