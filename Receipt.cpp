#include "Receipt.h"

#include <ctime>
#include <iostream>

#include "Sale.h"

using namespace std;

Receipt::Receipt( float amount): amount(amount)
{
	time_t now;
	time(&now);

	tm localTime;
	localtime_r(&now, &localTime);
	ReceiptDate = std::to_string(localTime.tm_mday) + "/" +
		std::to_string(localTime.tm_mon + 1) + "/" +
		std::to_string(localTime.tm_year + 1900);
	ReceiptNo++;
}

Receipt *Receipt::fromString(string receiptStr, Sale **sales, int n_sales)
{
	std::stringstream ss(receiptStr.substr(1, receiptStr.length()-2));

	int ReceiptNo;
	string ReceiptNo_s;
	getline(ss, ReceiptNo_s, ',');
	cout << ReceiptNo_s << endl;
	ReceiptNo = std::stoi(ReceiptNo_s);

	string ReceiptDate;
	getline(ss, ReceiptDate, ',');

	float amount;
	string amount_s;
	getline(ss, amount_s, ',');
	amount = std::stof(amount_s);

	auto receipt = new Receipt(amount);
	receipt->set_receipt_date(ReceiptDate);
	receipt->set_receipt_no(ReceiptNo);

	int saleId;
	for (int i = 0; i < n_sales; i++) {
		if (sales[i]->get_sale_id() == saleId) {
			sales[i]->AddPayment(receipt);
		}
	}
    return receipt;
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
