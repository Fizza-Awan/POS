#include "POS.h"

#include "GoldCustomer.h"
#include "Item.h"
#include "PlatinumCustomer.h"
#include "SilverCustomer.h"

POS::POS() {
	Customer::n_customer = 0;
	Item::TotalCount = 0;
}

Item** POS::get_items() const
{
	return items;
}

void POS::set_items(Item** items)
{
	this->items = items;
}

Sale** POS::get_sales() const
{
	return sales;
}

void POS::set_sales(Sale** sales)
{
	this->sales = sales;
}

Receipt** POS::get_receipts() const
{
	return receipts;
}

void POS::set_receipts(Receipt** receipts)
{
	this->receipts = receipts;
}

Customer** POS::get_customers() const
{
	return customers;
}

void POS::set_customers(Customer** customers)
{
	this->customers = customers;
}


Item* POS::FindItem(string ItemSKU)
{
	for (int i = 0; i < Item::TotalCount; i++)
	{
		if (this->items[i]->get_item_sku() == ItemSKU) return this->items[i];
	}
	return nullptr;
}

void POS::RemoveItem(Item* item)
{
	RemoveElementFromArray<Item>(this->items, Item::TotalCount, item);

}

Customer* POS::FindCustomer(const string& cnic)
{
	for (int i = 0; i < Customer::n_customer; i++)
	{
		if (this->customers[i]->get_cnic() == cnic) return this->customers[i];
	}
	return nullptr;
}

SaleLineItem* POS::EnterNewItemInSaleLine()
{
	string itemSKU;
	cout << "Item_SKU: ";
	cin >> itemSKU;
	Item* item = this->FindItem(itemSKU);
	if (item) {
		cout << "Description: " << item->get_description() << endl
			<< "Price: Rs. " << item->get_price() << endl
			<< "Quantity: ";
		int quantity;
		cin >> quantity;
		float SubTotal = quantity * item->get_price();

		cout << "Sub-Total: " << SubTotal << endl;
		auto* saleLineItem = new SaleLineItem(quantity, SubTotal, item);
		item->addSaleLineItem(saleLineItem);

		return saleLineItem;
	}
	else
		cout << "Item not found!" << endl;
}

void POS::AddNewItem()
{
	string itemSKU;
	cout << "Item_SKU: ";
	cin >> itemSKU;

	string description;
	cout << "Enter a string: ";
	cin.ignore();
	getline(cin, description);

	float price;
	cout << "Price: Rs. ";
	cin >> price;

	int quantity;
	cout << "Available Quantity: ";
	cin >> quantity;
	cout << endl;

	time_t now;
	time(&now);

	tm localTime;
	localtime_s(&localTime, &now);

	// Format the date as dd/mm/yyyy
	string date = std::to_string(localTime.tm_mday) + "/" +
		std::to_string(localTime.tm_mon + 1) + "/" +
		std::to_string(localTime.tm_year + 1900);
	int confirm;
	cout << "Enter 1 to confirm: ";
	cin >> confirm;

	if (confirm == 1)
	{
		Item* item = nullptr;
		item = new Item(itemSKU, description, price, quantity, date);
		cout << "Item Information successfully saved" << endl << endl;
		addElementToArray(this->items, Item::TotalCount, item);
	}
	else cout << "Item Information not Stored!" << endl << endl;
}

void POS::ModifyItemDetails()
{
	string itemSKU;
	cout << "Item_SKU: ";
	cin >> itemSKU;

	Item* ItemFound = FindItem(itemSKU);
	if (ItemFound != nullptr)
	{
		cout << "Description: " << ItemFound->get_description() << endl;
		cout << "Price: Rs. " << ItemFound->get_price() << endl;
		cout << "Available Quantity: " << ItemFound->get_available_quantity() << endl;
		cout << "Creation Date: " << ItemFound->get_creation_date() << endl;

		cout << "Please specify at least one of the following to modify the item. Leave all fields blank to return to Items Menu" << endl;
		string description;
		cout << "Description: ";
		cin.ignore();
		getline(cin, description);

		float* price = nullptr;
		string floatInput;
		cout << "Price: Rs. ";
		getline(cin, floatInput);
		if (!floatInput.empty()) {
			price = new float(stof(floatInput));
		}

		int* quantity = nullptr;
		string intInput;
		cout << "Available Quantity: ";
		getline(cin, intInput);
		if (!intInput.empty()) {
			quantity = new int(stoi(intInput));
		}
		cout << endl;

		int confirm;
		cout << "Enter 1 to confirm: ";
		cin >> confirm;

		if (confirm == 1)
		{
			if (price != nullptr || quantity != nullptr || !description.empty())
			{
				int idx = FindElementIndexInArray(this->items, Item::TotalCount, ItemFound);
				if (price != nullptr)
				{
					items[idx]->set_price(*price);
				}
				if (quantity != nullptr)
				{
					items[idx]->set_available_quantity(*quantity);
				}
				if (!description.empty())
				{
					items[idx]->set_description(description);
				}
				cout << "Item_SKU: " << ItemFound->get_item_sku() << endl;
				cout << "Description: " << ItemFound->get_description() << endl;
				cout << "Price: Rs. " << ItemFound->get_price() << endl;
				cout << "Available Quantity: " << ItemFound->get_available_quantity() << endl;
				cout << "Creation Date: " << ItemFound->get_creation_date() << endl;
			}
			else
			{
				cout << "No Item Modified!" << endl;
			}
		}
		else
		{
			cout << "No Item Modified!" << endl;
		}

		delete price;
		delete quantity;
		price = nullptr;
		quantity = nullptr;
	}
	else
	{
		cout << "Item Not Found!" << endl;
	}
}


void POS::FindItems()
{
	cout << "Please specify at least one of the following to find the item. Leave all fields blank to return to Items Menu: " << endl;

	string itemSKU;
	cout << "Item_SKU: ";
	cin.ignore();
	getline(cin, itemSKU);
	while (itemSKU.empty())
	{
		cout << "Item SKU cannot be empty. Please enter a valid item SKU: ";
		getline(cin, itemSKU);
	}

	string description;
	cout << "Description: ";
	//cin.ignore();
	getline(cin, description);

	float* price = nullptr;
	string floatInput;
	cout << "Price: Rs. ";
	getline(cin, floatInput);
	if (!floatInput.empty()) {
		price = new float(stof(floatInput));
	}

	int* quantity = nullptr;
	string intInput;
	cout << "Available Quantity: ";
	getline(cin, intInput);
	if (!intInput.empty()) {
		quantity = new int(stoi(intInput));
	}

	string CreationDate;

	do {
		cout << "Creation date (dd/mm/yyyy): ";
		getline(cin, CreationDate);

		if (!CreationDate.empty() && (CreationDate.length() != 10 || CreationDate[2] != '/' || CreationDate[5] != '/')) {
			cout << "Invalid date format. Please use dd/mm/yyyy format.\n";
		}
	} while (!CreationDate.empty() && (CreationDate.length() != 10 || CreationDate[2] != '/' || CreationDate[5] != '/'));
	cout << endl;

	if (!itemSKU.empty() || !description.empty() || price != nullptr || quantity != nullptr || !CreationDate.empty())
	{
		int count = 0;
		for (int i = 0; i < Item::TotalCount; i++)
			if ((itemSKU.empty() || itemSKU == items[i]->get_item_sku()) && (description.empty() || description == items[i]->get_description()) && (price == nullptr || *price == items[i]->get_price()) && (quantity == nullptr || *quantity == items[i]->get_available_quantity()) && (CreationDate.empty() || CreationDate == items[i]->get_creation_date()))
				count++;
		if (count > 0) {
			Item** FoundItem = new Item * [count];
			for (int i = 0, idx = 0; i < Item::TotalCount; i++)
				if ((itemSKU.empty() || itemSKU == items[i]->get_item_sku()) && (description.empty() || description == items[i]->get_description()) && (price == nullptr || *price == items[i]->get_price()) && (quantity == nullptr || *quantity == items[i]->get_available_quantity()) && (CreationDate.empty() || CreationDate == items[i]->get_creation_date()))
				{
					FoundItem[idx] = items[i];
					idx++;
				}
			cout << "----------------------------------------------------------------------------------------------------------" << endl
				<< "Item_SKU\tDescription\tPrice\tQuantity" << endl
				<< "----------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < count; i++)
				cout
				<< FoundItem[i]->get_item_sku()
				<< "\t"
				<< FoundItem[i]->get_description()
				<< "\t"
			<< FoundItem[i]->get_price()
				<< "\t"
				<< FoundItem[i]->get_available_quantity()
				<< endl;
			cout << "----------------------------------------------------------------------------------------------------------" << endl;
		}
		else
			cout << "No item found. Returning to items Menu!" << endl;
	}
	else
		cout << "No Item Modified!" << endl;

	delete price;
	delete quantity;
	price = nullptr;
	quantity = nullptr;

}

void POS::RemoveCustomer(Customer* customer)
{
	RemoveElementFromArray<Customer>(this->customers, Customer::n_customer, customer);

}

void POS::FindCustomers()
{
	cout << "Please specify at least one of the following to find the customer. Leave all fields blank to return to Customers Menu: " << endl;

	string CNIC;
	cout << "CNIC: ";
	cin.ignore();
	getline(cin, CNIC);
	string Name;
	cout << "Name: ";
	//cin.ignore();
	getline(cin, Name);

	string Email;
	cout << "Email: ";
	getline(cin, Email);

	string Phone;
	cout << "Phone: ";
	getline(cin, Phone);


	
	CustomerTypes Type;
	string type;
	do {
		cout << "Enter the Option Number" << endl
			<< "Type: " << endl
			<< "1. Gold Customer" << endl
			<< "2. Platinum Customer" << endl
			<< "3. Silver Customer" << endl;
		getline(cin, type);

		if (type == "1") {
			Type = Gold;
			break;
		}
		else if (type == "2") {
			Type = Platinum;
			break;
		}
		else if (type == "3") {
			Type = Silver;
			break;
		}
		else if(type.empty())
		{
			break;
		}
		else {
			cout << "Invalid option. Please enter a valid option number." << endl;
		}

	} while (true);

	if (!CNIC.empty() || !Name.empty() || !Email.empty() || !Phone.empty() || !type.empty())
	{
		int count = 0;
		for (int i = 0; i < Customer::n_customer; i++)
			if ((CNIC.empty() || CNIC == customers[i]->get_cnic()) && (Name.empty() || Name == customers[i]->get_name()) && (Email.empty() || Email == customers[i]->get_email()) && (Phone.empty() || Phone == customers[i]->get_phone()) && (type.empty() || Type == customers[i]->get_type()))
				count++;
		if (count > 0) {
			Customer** FoundCustomers = new Customer * [count];
			for (int i = 0, idx = 0; i < Customer::n_customer; i++)
				if ((CNIC.empty() || CNIC == customers[i]->get_cnic()) && (Name.empty() || Name == customers[i]->get_name()) && (Email.empty() || Email == customers[i]->get_email()) && (Phone.empty() || Phone == customers[i]->get_phone()) && (type.empty() || Type == customers[i]->get_type()))
				{
					FoundCustomers[idx] = customers[i];
					idx++;
				}
			cout << "----------------------------------------------------------------------------------------------------------" << endl
				<< "CNIC\tName\tEmail\tPhone\tSales Limit" << endl
				<< "----------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < count; i++)
				cout
				<< FoundCustomers[i]->get_cnic()
				<< "\t"
				<< FoundCustomers[i]->get_name()
				<< "\t"
				<< FoundCustomers[i]->get_email()
				<< "\t"
				<< FoundCustomers[i]->get_phone()
				<< "\t"
				<< FoundCustomers[i]->get_sales_limit()
				<< endl;
			cout << "----------------------------------------------------------------------------------------------------------" << endl;
		}
		else
			cout << "No customer found. Returning to customers Menu!" << endl;
	}
	else
		cout << "No customer Modified!" << endl;
}

void POS::AddNewCustomer()
{
	string CNIC;
	cout << "CNIC: ";
	cin.ignore();
	getline(cin, CNIC);
	while (CNIC.empty())
	{
		cout << "CNIC cannot be empty. Please enter a valid CNIC: ";
		getline(cin, CNIC);
	}

	string Name;
	cout << "Name: ";
	getline(cin, Name);
	while (Name.empty())
	{
		cout << "Name cannot be empty. Please enter a valid Name: ";
		getline(cin, Name);
	}

	string Address;
	cout << "Address: ";
	getline(cin, Address);
	while (Address.empty())
	{
		cout << "Address cannot be empty. Please enter a valid Address: ";
		getline(cin, Address);
	}

	string Email;
	cout << "Email: ";
	getline(cin, Email);
	while (Email.empty())
	{
		cout << "Email cannot be empty. Please enter a valid Email: ";
		getline(cin, Email);
	}

	string Phone;
	cout << "Phone: ";
	getline(cin, Phone);
	while (Phone.empty())
	{
		cout << "Phone cannot be empty. Please enter a valid Phone: ";
		getline(cin, Phone);
	}

	string Type;
	cout << "Enter the Option Number" << endl << "Type: " << endl
		<< "1. Gold Customer" << endl
		<< "2. Platinum Customer" << endl
		<< "3. Silver Customer" << endl;
	getline(cin, Type);
	while (Type.empty())
	{
		cout << "Type cannot be empty. Please enter a valid Type: ";
		getline(cin, Type);
	}

	int confirm;
	cout << "Enter 1 to confirm: ";
	cin >> confirm;

	if (confirm == 1)
	{

		if (Type == "Gold")
		{
			Customer* customer = Customer::GetCustomer(CNIC, Name, Address, Phone, Email, CustomerTypes::Gold);
			this->addCustomer(customer);
			cout << "Customer Information successfully saved" << endl << endl;
		}
		else if (Type == "Platinum")
		{
			Customer* customer = Customer::GetCustomer(CNIC, Name, Address, Phone, Email, CustomerTypes::Gold);
			this->addCustomer(customer);
			cout << "Customer Information successfully saved" << endl << endl;
		}
		else if (Type== "Silver")
		{
			Customer* customer = Customer::GetCustomer(CNIC, Name, Address, Phone, Email, CustomerTypes::Gold);
			this->addCustomer(customer);
			cout << "Customer Information successfully saved" << endl << endl;
		}
		else
		{
			cout << "Invalid customer type. Customer Information not stored!" << endl << endl;
		}
	}
	else
	{
		cout << "Customer Information not stored!" << endl << endl;
	}
}

void POS::ModifyCustomerDetails()
{
	string CNIC;
	cout << "CNIC: ";
	cin.ignore();
	getline(cin, CNIC);
	while (CNIC.empty())
	{
		cout << "CNIC cannot be empty. Please enter a valid CNIC: ";
		getline(cin, CNIC);
	}

	Customer* CustomerFound = FindCustomer(CNIC);
	if (CustomerFound != nullptr)
	{
		cout << "Name: " << CustomerFound->get_name() << endl
		<< "Address: " << CustomerFound->get_address() << endl
		<< "Email: " << CustomerFound->get_email() << endl
		<< "Phone: " << CustomerFound->get_phone() << endl;

		cout << "Please specify at least one of the following to modify the customer. Leave all fields blank to return to Customers Menu" << endl;
		
		string Name;
		cout << "Name: ";
		getline(cin, Name);

		string Address;
		cout << "Address: ";
		getline(cin, Address);

		string Email;
		cout << "Email: ";
		getline(cin, Email);

		string Phone;
		cout << "Phone: ";
		getline(cin, Phone);

		int confirm;
		cout << "Enter 1 to confirm: ";
		cin >> confirm;

		if (confirm == 1)
		{
			if (!Name.empty() || !Address.empty() || !Email.empty() || !Phone.empty())
			{
				int idx = FindElementIndexInArray(this->customers, Customer::n_customer, CustomerFound);
				if (!Name.empty())
				{
					customers[idx]->set_name(Name);
				}
				if (!Address.empty())
				{
					customers[idx]->set_address(Address);
				}
				if (!Email.empty())
				{
					customers[idx]->set_email(Email);
				}
				if (!Phone.empty())
				{
					customers[idx]->set_phone(Phone);
				}
				cout << "CNIC: " << CustomerFound->get_cnic() << endl;
				cout << "Name: " << CustomerFound->get_name() << endl;
				cout << "Address: " << CustomerFound->get_address() << endl;
				cout << "Email: " << CustomerFound->get_email() << endl;
				cout << "Phone: " << CustomerFound->get_phone() << endl;
			}
			else
			{
				cout << "No customer Modified!" << endl;
			}
		}
		else
		{
			cout << "No customer Modified!" << endl;
		}
		
	}
	else
	{
		cout << "Customer Not Found!" << endl;
	}
}

void POS::AddNewSale(Sale* sale)
{
	addElementToArray(this->sales, Sale::n_sale, sale);
}

void POS::addItem(Item* item)
{
	addElementToArray(this->items, Item::TotalCount, item);
}

void POS::addCustomer(Customer* customer)
{
	addElementToArray(this->customers, Customer::n_customer, customer);
}

Sale* POS::FindSale(int saleid)
{
	for (int i = 0; i < Sale::n_sale; i++)
		if (saleid == this->get_sales()[i]->get_sale_id())
			return this->get_sales()[i];
	return nullptr;

}
