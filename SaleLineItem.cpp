#include "SaleLineItem.h"

#include "Item.h"
#include "Sale.h"

int SaleLineItem::nextLineNo = 1;

int SaleLineItem::get_line_no() const
{
	return LineNo;
}

void SaleLineItem::set_line_no(int line_no)
{
	LineNo = line_no;
}

int SaleLineItem::get_quantity() const
{
	return Quantity;
}

void SaleLineItem::set_quantity(int quantity)
{
	Quantity = quantity;
}

Item* SaleLineItem::get_item() const
{
	return item;
}

void SaleLineItem::set_item(Item* item)
{
	this->item = item;
}

float SaleLineItem::get_SubTotal() const
{
	return SubTotal;
}

SaleLineItem::~SaleLineItem()
{
	this->item->RemoveSaleLineItem(this);
}

SaleLineItem* SaleLineItem::fromString(string itemString, Item **items, int n_items, Sale** sales, int n_sales)
{
	int LineNo;
	int Quantity;

	float SubTotal;

	std::stringstream ss(itemString.substr(1, itemString.length()-2));

	string LineNo_s;
	getline(ss, LineNo_s, ',');
	LineNo = std::stoi(LineNo_s);

	Sale* sale = nullptr;
	string saleId_s;
	getline(ss, saleId_s, ',');
	int saleId = std::stoi(saleId_s);
	for (int i = 0; i < n_sales; i++) {
		if (saleId == sales[i]->get_sale_id()) {
			sale = sales[i];
		}
	}

	Item* item = nullptr;
	string item_SKU;
	getline(ss, item_SKU, ',');
	for (int i = 0; i < n_items; i++) {
		if (item_SKU == items[i]->get_item_sku()) {
			item  = items[i];
		}
	}

	string Quantity_s;
	getline(ss, Quantity_s, ',');
	Quantity = std::stoi(Quantity_s);

    auto saleLineItem = new SaleLineItem(Quantity, Quantity*item->get_price(), item);
	saleLineItem->LineNo = LineNo;
	sale->add_sale_line_item(saleLineItem);
	return saleLineItem;
}

SaleLineItem::SaleLineItem(int quantity, float subtotal, Item *item)
{
	this->Quantity = quantity;
	this->SubTotal = subtotal;
	this->item = item;/*
	item->set_n_sale_line_items(item->get_n_sale_line_items() + 1);*/
	this->LineNo = nextLineNo;
	nextLineNo++;
}
