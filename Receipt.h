#pragma once
#ifndef _RECEIPT_
#define _RECEIPT_

#include <string>

using std::string;

class Receipt
{
	int ReceiptNo = 0;
	string ReceiptDate;
	float amount;

public:
	Receipt(string receipt_date, const float amount);

	int get_receipt_no() const;
	void set_receipt_no(int receipt_no);
	string get_receipt_date() const;
	void set_receipt_date(const string& receipt_date);
	float get_amount() const;
	void set_amount(float amount);
};
#endif
