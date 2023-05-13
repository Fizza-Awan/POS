#pragma once
#ifndef _SALELINEITEM_
#define _SALELINEITEM_

class Item;

class SaleLineItem
{
	int LineNo;
	int Quantity;

	float SubTotal;

	Item * item;

public:
	static int nextLineNo;

	SaleLineItem(int quantity, float subtotal, Item* item);
	int get_line_no() const;
	void set_line_no(int line_no);
	int get_quantity() const;
	void set_quantity(int quantity);
	Item * get_item() const;
	void set_item(Item * item);
	float get_SubTotal();
	~SaleLineItem();
};
#endif
