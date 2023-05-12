#include "Sale.h"

int Sale::nextSaleID = 0;

Sale::Sale(Customer* const customer, SaleLineItem** const saleLineItems, string Date) : date(Date), status(false), saleLineItems(saleLineItems), customer(customer)
{
	receipt = nullptr;
	SaleId = Sale::nextSaleID;
	Sale::nextSaleID++;
	n_sale++;
}

string Sale::get_date() const
{
	return date;
}

void Sale::set_date(const string& date)
{
	this->date = date;
}

bool Sale::is_status() const
{
	return status;
}

void Sale::set_status(bool status)
{
	this->status = status;
}

SaleLineItem* Sale::get_sale_line_items() const
{
	return saleLineItems;
}

void Sale::set_sale_line_items(SaleLineItem* sale_line_items)
{
	saleLineItems = sale_line_items;
}

Receipt* Sale::get_receipts() const
{
	return receipts;
}

void Sale::set_receipts(Receipt* receipts)
{
	this->receipts = receipts;
}

Customer* Sale::get_customer() const
{
	return customer;
}

void Sale::set_customer(Customer* customer)
{
	this->customer = customer;
}
