#include "SilverCustomer.h"

SilverCustomer::SilverCustomer(const string& cnic, const string& name, const string& address, const std::string& phone,
	const std::string& email)
{
	set_cnic(cnic);
	set_name(name);
	set_address(address);
	set_phone(phone);
	set_email(email);
	set_amount_payable(0);
	set_sales_limit(40000);
}
