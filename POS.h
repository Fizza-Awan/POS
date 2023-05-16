#pragma once
#ifndef _POS_
#define _POS_

#include "Sale.h"
#include <iostream>
#include<string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

class POS
{
	Item** items;
	Sale** sales;
	Receipt** receipts;
	Customer** customers;
	int n_receipts;

public:
	int get_n_receipts() const;
	void set_n_receipts(int n_receipts);

	POS();
	Item** get_items() const;
	void set_items(Item** items);
	Sale** get_sales() const;
	void set_sales(Sale** sales);
	Receipt** get_receipts() const;
	void set_receipts(Receipt** receipts);
	Customer** get_customers() const;
	void set_customers(Customer** customers);
	Item* FindItem(string ItemSKU);


	void RemoveItem(Item* item);
	Customer* FindCustomer(const string& cnic);

	SaleLineItem* EnterNewItemInSaleLine();

	void AddNewItem();
	void ModifyItemDetails();
	void FindItems();
	void RemoveCustomer(Customer* customer);
	void FindCustomers();
	void AddNewCustomer();
	void ModifyCustomerDetails();
	void AddNewSale(Sale* sale);
	void addItem(Item* item);
	void addCustomer(Customer* customer);
	Sale* FindSale(int saleid);
	void AddNewReceipts(Sale* sale);
};
#endif
