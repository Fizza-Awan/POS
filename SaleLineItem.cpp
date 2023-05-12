#include "SaleLineItem.h"

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

float SaleLineItem::get_SubTotal()
{
	return SubTotal;
}

SaleLineItem::SaleLineItem(int quantity, float subtotal, Item* item)
{
	this->Quantity = quantity;
	this->SubTotal = subtotal;
	this->item = item;

	this->LineNo = SaleLineItem::nextLineNo;
	SaleLineItem::nextLineNo++;
}
