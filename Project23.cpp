#include<conio.h>
#include <iostream>

#include "Item.h"
#include "SilverCustomer.h"
#include "POS.h"
#include "Utils.cpp"

using namespace std;

void printMainMenu()
{
	cout
		<< "1 - Manage Items" << endl
		<< "2 - Manage Customers" << endl
		<< "3 - Make New Sale" << endl
		<< "4 - Make Payment" << endl
		<< "5 - Exit" << endl
		<< "Press 1 to 5 to select an option: ";
}

void printItemsMenu()
{
	cout
		<< "1 - Add new Item" << endl
		<< "2 - Update Item details" << endl
		<< "3 - Find Items" << endl
		<< "4 - Remove Existing Item" << endl
		<< "5 - Back to Main Menu" << endl
		<< "Press 1 to 5 to select an option: ";
}

void printCustomersMenu()
{
	cout
		<< "1 - Add new Customer" << endl
		<< "2 - Update Customer details" << endl
		<< "3 - Find Customer" << endl
		<< "4 - Remove Existing Customer" << endl
		<< "5 - Back to Main Menu" << endl
		<< "Press 1 to 5 to select an option: ";
}

void printSalesMenu()
{
	cout
		<< "Press 1 to Enter New Item" << endl
		<< "Press 2 to End Sale" << endl
		<< "Press 3 to Remove an existing Item from the current sale" << endl
		<< "Press 4 to Cancel Sale" << endl
		<< "Choose from option 1 - 4: ";
}

int main() {
	Customer* customer = Customer::GetCustomer("3520299679023", "Asim", "Lahore", "03123456789", "a@b.c", CustomerTypes::Silver);
	Item * item = new Item("123", "Alus", 40, 20, "07/05/2023");
	POS* pos = new POS();
	pos->addItem(item);
	pos->addCustomer(customer);
	int mainMenuOption = 0;
	do {
		printMainMenu();
		cin >> mainMenuOption;
		if (mainMenuOption < 1 || mainMenuOption > 5)
			cout << "Invalid Input!" << endl << "Try Again!";
		else if (mainMenuOption == 5)
			exit(0);
		else if (mainMenuOption == 4) {
			int Saleid = 0;
			cout << "Sale ID: ";
			cin >> Saleid;
			Sale Sale* = pos->FindSale(Saleid);
			if (!Sale)
			{
				cout << "No Sale ID found!" << endl << endl;
			}
			else {
				float amountPaid = 0, amountToBePaid = 0;
				for (int j = 0; j < Sale->get_n_receipt(); j++)
					amountPaid += Sale->get_receipt()[j]->get_amount();
				cout << "Customer Name" << Sale->get_customer()->get_name() << endl
					//idk what should be here
					<< "Total Sales Amount: " << Sale->get_customer()->get_amount_payable() << endl
					<< "Amount Paid: " << amountPaid << endl
					<< "Remaining Amount: " << Sale->get_customer()->get_amount_payable() << endl
					<< "Amount to be paid: ";
				cin >> amountToBePaid;
				Sale->get_customer()->set_amount_payable(Sale->get_customer()->get_amount_payable() - amountToBePaid);
			}
		}
		else if (mainMenuOption == 3) {

			time_t now;
			time(&now);

			tm localTime;
			localtime_s(&localTime, &now);
			string date = to_string(localTime.tm_mday) + "/" +
				to_string(localTime.tm_mon + 1) + "/" +
				to_string(localTime.tm_year + 1900);

			cout << "Sales ID: " << Sale::nextSaleID << endl
				<< "Sales Date: " << date << endl
				<< "Enter CNIC: ";
			string cnic;
			cin >> cnic;
			Customer* customer = pos->FindCustomer(cnic);

			if (customer == nullptr)
				cout << "Customer Not Found!" << endl;
			else {
				int n_saleLineItems = 1;
				auto** saleLineItems = new SaleLineItem * [n_saleLineItems];

				auto* saleLineItem = pos->EnterNewItemInSaleLine();
				customer->set_amount_payable(saleLineItem->get_SubTotal());

				saleLineItems[0] = saleLineItem;

				int sale_option = 0;
				do {
					printSalesMenu();
					cin >> sale_option;
					if (sale_option < 1 || sale_option > 4)
						cout << "Invalid Input!" << endl << "Try Again!";
					else if (sale_option == 4) {
						for (int i = 0; i < n_saleLineItems; i++)
							delete[] saleLineItems[i];
						delete[] saleLineItems;
						delete[] saleLineItem;
						delete[] customer;
						break;
					}
					else if (sale_option == 3) {
						string itemSKU;
						cout << "Enter item SKU to remove: ";
						cin >> itemSKU;
						SaleLineItem* itemToRemove = nullptr;
						for (int i = 0; i < n_saleLineItems; i++)
							if (itemSKU == saleLineItems[i]->get_item()->get_item_sku())
								itemToRemove = saleLineItems[i];
						if (itemToRemove) {
							int confirm = 0;
							cout << "Enter 1 to confirm: ";
							cin >> confirm;

							if (confirm == 1) {
								cout << "Item is removed!" << endl;
								RemoveElementFromArray<SaleLineItem>(saleLineItems, n_saleLineItems, itemToRemove);
							}
							else
								cout << "Item is not removed!" << endl;
						}
						else
						{
							cout << "No item found. Returning to item Menu." << endl;
							sale_option = 0;
						}
					}
					else if (sale_option == 2) {
						if (customer->get_amount_payable() > customer->get_sales_limit()) {
							cout << "Total sales exceed the sale limit for this customer." << endl;
							sale_option = 0;
						}
						else {
							
							cout << "Sales ID: " << Sale::nextSaleID << "\t\t\t\tCNIC: " << customer->get_cnic() << endl
								<< "Sales Date: " << date << "\t\t\tName: " << customer->get_name() << endl
								<< "Type: " << customer->get_type() << endl
								<< "-----------------------------------------------------------------------------------------------------------------------" << endl << "ItemSKU\tDescription\t\tQuantity\tAmount" << endl
								<< "-----------------------------------------------------------------------------------------------------------------------" << endl;

							for (int i = 0; i < n_saleLineItems; i++)
								cout
								<< saleLineItems[i]->get_item()->get_item_sku()
								<< "\t"
								<< saleLineItems[i]->get_item()->get_description()
								<< "\t"
								<< saleLineItems[i]->get_quantity()
								<< "\t"
								<< saleLineItems[i]->get_SubTotal()
								<< endl;

							cout << "-----------------------------------------------------------------------------------------------------------------------" << endl
								<< "\t\t\t\t\t\t\tTotal Sales: " << customer->get_amount_payable() << endl
								<< "-----------------------------------------------------------------------------------------------------------------------" << endl;
							cout << "Press any key to continue!" << endl;
							_getch();
							auto* sale = new Sale(customer, saleLineItems, n_saleLineItems, date);
							pos->AddNewSale(sale);
						}
					}
					else if (sale_option == 1) {
						saleLineItem = pos->EnterNewItemInSaleLine();
						customer->set_amount_payable(saleLineItem->get_SubTotal());
						cout << "Total Amount Payable: " << customer->get_amount_payable() << endl;
						addElementToArray<SaleLineItem>(saleLineItems, n_saleLineItems, saleLineItem);
					}
				} while (sale_option != 4);
			}
		}
		else if (mainMenuOption == 2) {
			int customer_option = 0;
			do {
				printCustomersMenu();
				cin >> customer_option;
				if (customer_option < 1 || customer_option > 5)
					cout << "Invalid Input!" << endl << "Try Again!";
				else if (customer_option == 5)
					break;
				else if (customer_option == 4) {
					string CNIC;
					cout << "Enter CNIC of customer to remove: ";
					cin >> CNIC;
					Customer* customerToRemove = pos->FindCustomer(CNIC);
					if (customerToRemove)
						if (customerToRemove->isNotAssociatedYet())
						{
							int confirm = 0;
							cout << "Enter 1 to confirm: ";
							cin >> confirm;

							if (confirm == 1) {
								cout << "Customer is removed!" << endl;
								pos->RemoveCustomer(customerToRemove);

							}
							else
								cout << "Customer is not removed!" << endl;
						}
						else
							cout << "Customers that have been in a sale can not be removed from the system." << endl;
					else
					{
						cout << "No customer found. Returning to customer Menu." << endl;
						customer_option = 0;
					}
				}
				else if (customer_option == 3) {
					pos->FindCustomers();
				}
				else if (customer_option == 2) {
					pos->ModifyCustomerDetails();
				}
				else if (customer_option == 1) {
					pos->AddNewCustomer();
				}
			} while (customer_option != 5);
		}
		else if (mainMenuOption == 1) {
			int item_option = 0;
			do {
				printItemsMenu();
				cin >> item_option;
				if (item_option < 1 || item_option > 5)
					cout << "Invalid Input!" << endl << "Try Again!";
				else if (item_option == 5)
					break;
				else if (item_option == 4) {
					string itemSKU;
					cout << "Enter item SKU to remove: ";
					cin >> itemSKU;
					Item* itemToRemove = pos->FindItem(itemSKU);
					if (itemToRemove)
						if (itemToRemove->isNotSoldYet())
						{
							int confirm = 0;
							cout << "Enter 1 to confirm: ";
							cin >> confirm;

							if (confirm == 1) {
								cout << "Item is removed!" << endl;
								pos->RemoveItem(itemToRemove);
							}
							else
								cout << "Item is not removed!" << endl;
						}
						else
							cout << "Items that have been sold can not be removed from the system." << endl;
					else
					{
						cout << "No item found. Returning to item Menu." << endl;
						item_option = 0;
					}
				}
				else if (item_option == 3) {
					pos->FindItems();
				}
				else if (item_option == 2) {
					pos->ModifyItemDetails();
				}
				else if (item_option == 1) {
					pos->AddNewItem();

				}
			} while (item_option != 5);
		}
	} while (true);
}