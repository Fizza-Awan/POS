#include "Sale.h"

int Sale::nextSaleID = 0;
int Sale::n_sale = 0;

Sale::Sale(Customer* const customer, SaleLineItem** const saleLineItems, int n_saleLineItems, string Date) : date(Date), status(false), saleLineItems(saleLineItems), n_saleLineItems(n_saleLineItems), customer(customer)
{
	receipt = nullptr;
	SaleId = Sale::nextSaleID;
	Sale::nextSaleID++;
	customer->set_n_sale(customer->get_n_sale() + 1);
	n_sale++;
}

int Sale::get_sale_id() const
{
	return SaleId;
}

void Sale::set_sale_id(int sale_id)
{
	SaleId = sale_id;
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

SaleLineItem** Sale::get_sale_line_items() const
{
	return saleLineItems;
}

void Sale::set_sale_line_items(SaleLineItem** sale_line_items)
{
	saleLineItems = sale_line_items;
}

Receipt* Sale::get_receipt() const
{
	return receipt;
}

void Sale::set_receipt(Receipt* receipts)
{
	this->receipt = receipts;
}

Customer* Sale::get_customer() const
{
	return customer;
}

void Sale::set_customer(Customer* customer)
{
	this->customer = customer;
}

float Sale::getSalesAmout() const
{
	float sum = 0.0f;
	for (int i = 0; i < n_saleLineItems; i++) {
		sum += this->saleLineItems[i]->get_SubTotal();
	}
    return sum;
}
