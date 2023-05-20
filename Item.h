#pragma once
#ifndef _ITEM_
#define _ITEM_

#include <string>
#include "SaleLineItem.h"
#include "Utils.cpp"

using std::string;

class Item
{
	string item_SKU;
	string Description;
	float Price;
	int AvailableQuantity;
	string CreationDate;

	SaleLineItem** saleLineItems;
	int n_saleLineItems;

public:
	static int TotalCount;
	static Item* fromString(string item);
	int get_n_sale_line_items() const;
	void set_n_sale_line_items(int n_sale_line_items);
	Item(const string& item_sku, const string& description, const float price, const int available_quantity,
	     const string& creation_date);
	~Item();

	string get_item_sku() const;
	void set_item_sku(const string& item_sku);
	string get_description() const;
	void set_description(const string& description);
	float get_price() const;
	void set_price(float price);
	int get_available_quantity() const;
	void set_available_quantity(int available_quantity);
	string get_creation_date() const;
	void set_creation_date(const string& creation_date);
	void addSaleLineItem(SaleLineItem* saleLineItem);
	void RemoveSaleLineItem(SaleLineItem* saleLineItem);
	bool isNotSoldYet();
};
#endif

