#include "Sale.h"
#include "Utils.cpp"
#include "Customer.h"
#include "SaleLineItem.h"

int Sale::nextSaleID = 0;
int Sale::n_sale = 0;

int Sale::get_n_receipt() const
{
	return n_receipt;
}

void Sale::set_n_receipt(int n_receipt)
{
	this->n_receipt = n_receipt;
}

void Sale::AddPayment(Receipt* receipt)
{
	if (n_receipt == 0)
	{
		this->receipt = new Receipt*;
		this->receipt[0] = receipt;
		n_receipt = 1;
	}
	addElementToArray<Receipt>(this->receipt, n_receipt, receipt);
	float sumReceipts = 0;
	for (int i =0;i < n_receipt;i++)
	{
		sumReceipts += this->receipt[i]->get_amount();
	}
	if (sumReceipts >= this->getSalesAmount())
	{
		this->status = true;
	}
}

Sale::Sale(Customer* customer, SaleLineItem** saleLineItems, int n_saleLineItems, string Date) : date(Date), status(false), saleLineItems(saleLineItems), n_saleLineItems(n_saleLineItems), customer(customer)
{
	receipt = nullptr;
	SaleId = Sale::nextSaleID;
	Sale::nextSaleID++;
	// customer->set_n_sale(customer->get_n_sale() + 1);
	customer->addSale(this);
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

Sale* Sale::fromString(string itemString, Customer** customers, int n_customers)
{
	std::stringstream ss(itemString.substr(1, itemString.length()-2));

	int SaleId;
	string date;
	bool status;

	string SaleId_s;
	getline(ss, SaleId_s, ',');
	SaleId = std::stoi(SaleId_s);

	Customer* customer = nullptr;
	string customerCNIC;
	getline(ss, customerCNIC, ',');
	for (int i = 0; i < n_customers; i++) {
		if (customers[i]->get_cnic() == customerCNIC) {
			customer = customers[i];
		}
	}

	// SaleLineItem** this_saleLineItems = nullptr;
	// int this_n_saleLineItems = 0;
	// string saleLineItemNo_s;
	// getline(ss, saleLineItemNo_s, ',');
	// saleLineItemNo_s = saleLineItemNo_s.substr(1);
	// do {
	// 	int saleLineItemNo = std::stoi(saleLineItemNo_s);
	// 	for (int i = 0; i < n_saleLineItems; i++) {
	// 		if (saleLineItems[i]->get_line_no() == saleLineItemNo) {
	// 			addElementToArray<SaleLineItem>(this_saleLineItems, this_n_saleLineItems, saleLineItems[i]);
	// 		}
	// 	}
	// } while (saleLineItemNo_s[saleLineItemNo_s.length()-1] == ']');
	// saleLineItemNo_s = saleLineItemNo_s.substr(0, saleLineItemNo_s.length()-1);
	// int saleLineItemNo = std::stoi(saleLineItemNo_s);
	// for (int i = 0; i < n_saleLineItems; i++) {
	// 	if (saleLineItems[i]->get_line_no() == saleLineItemNo) {
	// 		addElementToArray<SaleLineItem>(this_saleLineItems, this_n_saleLineItems, saleLineItems[i]);
	// 	}
	// }

	getline(ss, date, ',');

	string status_s;
	getline(ss, status_s, ',');
	status = std::stoi(status_s);

    auto sale = new Sale(customer, nullptr, 0, date);
	sale->set_status(status);
	return sale;
}

void Sale::add_sale_line_item(SaleLineItem *sale_line_item)
{
	addElementToArray<SaleLineItem>(this->saleLineItems, this->n_saleLineItems, sale_line_item);
}

Receipt **Sale::get_receipt() const
{
	return receipt;
}

void Sale::set_receipt(Receipt** receipts)
{
	this->receipt = receipts;
}

Customer* Sale::get_customer() const
{
	return customer;
}

void Sale::set_customer(Customer* customerr)
{
	this->customer = customerr;
}

int Sale::getNSaleLineItems() const
{
    return n_saleLineItems;
}

float Sale::getSalesAmount() const
{
	float sum = 0.0;
	for (int i = 0; i < n_saleLineItems; i++) {
		sum += this->saleLineItems[i]->get_SubTotal();
	}
    return sum;
}
