#include "SaleLineItem.h"

#include "Item.h"

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

SaleLineItem::SaleLineItem(int quantity, float subtotal, Item* item)
{
	this->Quantity = quantity;
	this->SubTotal = subtotal;
	this->item = item;/*
	item->set_n_sale_line_items(item->get_n_sale_line_items() + 1);*/
	this->LineNo = nextLineNo;
	nextLineNo++;
}
