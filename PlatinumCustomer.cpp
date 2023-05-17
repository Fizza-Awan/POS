#include "PlatinumCustomer.h"

float PlatinumCustomer::get_discount() const
{
	return Discount;
}

void PlatinumCustomer::set_discount(float discount)
{
	Discount = discount;
}

PlatinumCustomer::PlatinumCustomer(const string& cnic, const string& name, const string& address,
	const std::string& phone, const std::string& email, CustomerTypes Type)
{
	set_type(Type);
	set_cnic(cnic);
	set_name(name);
	set_address(address);
	set_phone(phone);
	set_email(email);
	set_amount_payable(0);
	set_sales_limit(250000);
	Discount = 0.05;
}
