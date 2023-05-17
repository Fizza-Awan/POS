#include "GoldCustomer.h"

float GoldCustomer::get_discount() const
{
	return Discount;
}

void GoldCustomer::set_discount(float discount)
{
	Discount = discount;
}

GoldCustomer::GoldCustomer(const string& cnic, const string& name, const string& address, const string& phone,
	const string& email, CustomerTypes Type)
{
	set_type(Type);
	set_cnic(cnic);
	set_name(name);
	set_address(address);
	set_phone(phone);
	set_email(email);
	set_amount_payable(0);
	set_sales_limit(100000);
	Discount = 0.03;
}
