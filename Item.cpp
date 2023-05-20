#include "Item.h"
#include <sstream>

Item* Item::fromString(string item)
{
	string item_SKU;
	string Description;
	float Price;
	int AvailableQuantity;
	string CreationDate;

	std::stringstream ss(item.substr(1, item.length()-2));
	getline(ss, item_SKU, ',');
	getline(ss, Description, ',');
	string Price_s;
	getline(ss, Price_s, ',');
	Price = stof(Price_s);
	string AvailableQuantity_s;
	getline(ss, AvailableQuantity_s, ',');
	AvailableQuantity = stoi(AvailableQuantity_s);
	getline(ss, CreationDate, ',');
    return new Item(item_SKU, Description, Price, AvailableQuantity, CreationDate);
}

int Item::get_n_sale_line_items() const
{
	return n_saleLineItems;
}

void Item::set_n_sale_line_items(int n_sale_line_items)
{
	n_saleLineItems = n_sale_line_items;
}

Item::Item(const string& item_sku, const string& description, const float price, const int available_quantity,
           const string& creation_date): item_SKU(item_sku),
                                         Description(description),
                                         Price(price),
                                         AvailableQuantity(available_quantity),
                                         CreationDate(creation_date)
{
	//TotalCount++;
	//NextSKU++;
	n_saleLineItems = 0;
}

Item::~Item()
{
	TotalCount--;
}

string Item::get_item_sku() const
{
	return item_SKU;
}

void Item::set_item_sku(const string& item_sku)
{
	item_SKU = item_sku;
}

string Item::get_description() const
{
	return Description;
}

void Item::set_description(const string& description)
{
	Description = description;
}

float Item::get_price() const
{
	return Price;
}

void Item::set_price(float price)
{
	Price = price;
}

int Item::get_available_quantity() const
{
	return AvailableQuantity;
}

void Item::set_available_quantity(int available_quantity)
{
	AvailableQuantity = available_quantity;
}

string Item::get_creation_date() const
{
	return CreationDate;
}

void Item::set_creation_date(const string& creation_date)
{
	CreationDate = creation_date;
}

void Item::addSaleLineItem(SaleLineItem* saleLineItem)
{
	if (this->n_saleLineItems == 0)
	{
		this->saleLineItems = new SaleLineItem * [1];
		this->saleLineItems[0] = saleLineItem;
		this->n_saleLineItems = 1;
		return;
	}
	addElementToArray<SaleLineItem>(this->saleLineItems, this->n_saleLineItems, saleLineItem);
	//SaleLineItem** newSaleLineItems = new SaleLineItem * [this->n_saleLineItems + 1];
	//for (int i = 0; i < this->n_saleLineItems; i++) { newSaleLineItems[i] = this->saleLineItems[i]; }
	//this->saleLineItems[this->n_saleLineItems] = saleLineItem;
	//this->n_saleLineItems++;
	//delete[] this->saleLineItems;
	//this->saleLineItems = newSaleLineItems;
}

void Item::RemoveSaleLineItem(SaleLineItem* saleLineItem)
{
	if (this->n_saleLineItems == 1)
	{
		delete[] this->saleLineItems[0];
		delete[] this->saleLineItems;
		this->n_saleLineItems = 0;
		return;
	}
	RemoveElementFromArray<SaleLineItem>(this->saleLineItems, this->n_saleLineItems, saleLineItem);
}

bool Item::isNotSoldYet()
{
	if (this->n_saleLineItems == 0) return true;
	return false;
}

int Item::TotalCount = 0;
