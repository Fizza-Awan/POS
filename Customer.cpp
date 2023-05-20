#include "Customer.h"
#include "SilverCustomer.h"
#include "GoldCustomer.h"
#include "PlatinumCustomer.h"
#include "Utils.cpp"

//Customer::Customer(CustomerTypes Type): Type(Type)
//{
//}

CustomerTypes CustomerTypesFromString(string CustomerTypesInt) {
	if (CustomerTypesInt == "2") return CustomerTypes::Platinum;
	else if (CustomerTypesInt == "1") return CustomerTypes::Gold;
	else return CustomerTypes::Silver;
}

Customer *Customer::GetCustomer(string CNIC, string Name, string Address, string Phone, string Email, CustomerTypes Type)
{
	Customer* customer = nullptr;
    if (Type == CustomerTypes::Silver)
	{
		customer = new SilverCustomer(CNIC, Name, Address, Phone, Email, Type);
	} else if (Type == CustomerTypes::Gold)
	{
		customer = new GoldCustomer(CNIC, Name, Address, Phone, Email, Type);
	} else if (Type == CustomerTypes::Platinum)
	{
		customer = new PlatinumCustomer(CNIC, Name, Address, Phone, Email, Type);
	}
	if (customer != nullptr) {
		customer->AmountPayable = 0;
		//n_customer++;
	}
	return customer;
}

Customer *Customer::fromString(string item)
{
	string CNIC;
	string Name;
	string Address;
	string Phone;
	string Email;
	CustomerTypes Type;

	std::stringstream ss(item.substr(1, item.length()-2));
	getline(ss, CNIC, ',');
	getline(ss, Name, ',');
	getline(ss, Address, ',');
	getline(ss, Phone, ',');
	getline(ss, Email, ',');
	string TypeInt;
	getline(ss, TypeInt, ',');
	Type = CustomerTypesFromString(TypeInt);
    return Customer::GetCustomer(CNIC, Name, Address, Phone, Email, Type);
}

int Customer::get_n_sale() const
{
	return n_sale;
}

void Customer::set_n_sale(int n_sale)
{
	this->n_sale = n_sale;
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

void Customer::addSale(Sale* sale)
{
	if (n_sale == 0 ) {
		this->sales = new Sale*;
		this->sales[0] = sale;
		n_sale = 1;
	}
	addElementToArray<Sale>(this->sales, n_sale, sale);
}

float Customer::getTotalSalesAmount()
{
	float totalSalesAmount = 0.0f;
	for (int i = 0; i < n_sale; i++) {
		totalSalesAmount += this->sales[i]->getSalesAmount();
	}
    return totalSalesAmount;
}

int Customer::n_customer = 0;
