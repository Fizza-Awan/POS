#pragma once

#ifndef _SALE_
#define _SALE_

#include <string>

#include "Receipt.h"

class Customer;
class SaleLineItem;

using std::string;

class Sale
{
	int SaleId;
	string date;
	bool status;

	SaleLineItem** saleLineItems;
	int n_saleLineItems;
	Receipt** receipt;
	Customer* customer;
	int n_receipt;

public:
	int get_n_receipt() const;
	void set_n_receipt(int n_receipt);
	void AddPayment(Receipt* receipt);

	static int n_sale;
	static int nextSaleID;
	Sale(Customer* customer, SaleLineItem** saleLineItems, int n_saleLineItems, string Date);
	static Sale* fromString(string itemString, Customer** customers, int n_customers);
	int get_sale_id() const;
	void set_sale_id(int sale_id);
	string get_date() const;
	void set_date(const string& date);
	bool is_status() const;
	void set_status(bool status);
	SaleLineItem** get_sale_line_items() const;
	void set_sale_line_items(SaleLineItem** sale_line_items);
	void add_sale_line_item(SaleLineItem* sale_line_item);
	Receipt** get_receipt() const;
	void set_receipt(Receipt** receipt);
	Customer* get_customer() const;
	void set_customer(Customer* customerr);
	float getSalesAmount() const;
	int getNSaleLineItems() const;
};
#endif
