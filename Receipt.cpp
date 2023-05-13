#include "Receipt.h"

#include <ctime>

Receipt::Receipt(const float amount): amount(amount)
{
	time_t now;
	time(&now);

	tm localTime;
	localtime_s(&localTime, &now);
	ReceiptDate = std::to_string(localTime.tm_mday) + "/" +
		std::to_string(localTime.tm_mon + 1) + "/" +
		std::to_string(localTime.tm_year + 1900);
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
