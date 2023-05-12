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
	Receipt* receipt;
	Customer* customer;

public:

	static int n_sale = 0;
	static int nextSaleID;
	Sale(Customer* const customer, SaleLineItem** const saleLineItems, string Date);

	int get_sale_id() const;
	void set_sale_id(int sale_id);
	string get_date() const;
	void set_date(const string& date);
	bool is_status() const;
	void set_status(bool status);
	SaleLineItem* get_sale_line_items() const;
	void set_sale_line_items(SaleLineItem* sale_line_items);
	Receipt* get_receipts() const;
	void set_receipts(Receipt* receipts);
	Customer* get_customer() const;
	void set_customer(Customer* customer);
};
#endif
