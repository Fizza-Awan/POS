#pragma once
#ifndef _SALE_
#define _SALE_

#include <string>

#include "Customer.h"
#include "Receipt.h"
#include "SaleLineItem.h"

using std::string;

class Sale
{
	int SaleId;
	string date;
	bool status;

	SaleLineItem** saleLineItems;
	int n_saleLineItems;
	Receipt* receipt;
	Customer* customer;

public:

	static int n_sale;
	static int nextSaleID;
	Sale(Customer* const customer, SaleLineItem** const saleLineItems, int n_saleLineItems, string Date);
	int get_sale_id() const;
	void set_sale_id(int sale_id);
	string get_date() const;
	void set_date(const string& date);
	bool is_status() const;
	void set_status(bool status);
	SaleLineItem** get_sale_line_items() const;
	void set_sale_line_items(SaleLineItem** sale_line_items);
	Receipt* get_receipt() const;
	void set_receipt(Receipt* receipt);
	Customer* get_customer() const;
	void set_customer(Customer* customer);
	float getSalesAmout() const;
};
#endif
