#include "Customer.h"
#include "SilverCustomer.h"
#include "GoldCustomer.h"
#include "PlatinumCustomer.h"

Customer::Customer(CustomerTypes Type): Type(Type)
{
}

Customer *Customer::GetCustomer(string CNIC, string Name, string Address, string Phone, string Email, CustomerTypes Type)
{
	Customer* customer = nullptr;
    if (Type == CustomerTypes::Silver)
	{
		customer = new SilverCustomer(CNIC, Name, Address, Phone, Email);
	} else if (Type == CustomerTypes::Gold)
	{
		customer = new GoldCustomer(CNIC, Name, Address, Phone, Email);
	} else if (Type == CustomerTypes::Platinum)
	{
		customer = new PlatinumCustomer(CNIC, Name, Address, Phone, Email);
	}
	if (customer != nullptr) n_customer++;
	return customer;
}

Customer::~Customer () {
	Customer::n_customer--;
}

string Customer::get_cnic() const
{
	return CNIC;
}

void Customer::set_cnic(const string& cnic)
{
	CNIC = cnic;
}

string Customer::get_name() const
{
	return Name;
}

void Customer::set_name(const string& name)
{
	Name = name;
}

string Customer::get_address() const
{
	return Address;
}

void Customer::set_address(const string& address)
{
	Address = address;
}

string Customer::get_phone() const
{
	return Phone;
}

void Customer::set_phone(const string& phone)
{
	Phone = phone;
}

string Customer::get_email() const
{
	return Email;
}

void Customer::set_email(const string& email)
{
	Email = email;
}

float Customer::get_amount_payable() const
{
	return AmountPayable;
}

void Customer::set_amount_payable(float amount_payable)
{
	AmountPayable += amount_payable;
}

float Customer::get_sales_limit() const
{
	return SalesLimit;
}

void Customer::set_sales_limit(float sales_limit)
{
	SalesLimit = sales_limit;
}

bool Customer::isNotAssociatedYet()
{
	if (this->n_sale == 0) return true;
	return false;
}

void Customer::set_type(const CustomerTypes& type)
{
	Type = type;
}

CustomerTypes Customer::get_type()
{
	return Type;
}

int Customer::n_customer = 0;
