#include "Receipt.h"

Receipt::Receipt(string receipt_date, const float amount):
	ReceiptDate(std::move(receipt_date)), amount(amount)
{
	ReceiptNo++;
}

int Receipt::get_receipt_no() const
{
	return ReceiptNo;
}

void Receipt::set_receipt_no(int receipt_no)
{
	ReceiptNo = receipt_no;
}

string Receipt::get_receipt_date() const
{
	return ReceiptDate;
}

void Receipt::set_receipt_date(const string& receipt_date)
{
	ReceiptDate = receipt_date;
}

float Receipt::get_amount() const
{
	return amount;
}

void Receipt::set_amount(float amount)
{
	this->amount = amount;
}
