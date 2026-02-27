# 🛒 Point of Sale (POS) System [C++ OOP]

> 📌 **Note:** Built during my **2nd semester** as an Object-Oriented Programming course project. First real experience designing a multi-class system: applying inheritance, composition, polymorphism, and file-based persistence to model a real-world retail application.

A terminal-based Point of Sale system built in C++ that allows cashiers to manage items, customers, sales, and payments.

---

## 🎮 Features

### Item Management
- Add new items (SKU, Description, Price, Quantity, Creation Date)
- Update item details by SKU
- Search items by any field (SKU, Description, Price, Quantity, Date)
- Remove items — only if no recorded sale exists for the item

### Customer Management
- Add customers with type selection (Silver / Gold / Platinum)
- Update customer details by CNIC
- Search customers by any field (CNIC, Name, Email, Phone, Type)
- Remove customers — only if no associated sales exist

### Sales Processing
- Create new sale — auto-generates Sale ID and date
- Add multiple items per sale with live subtotal display
- Remove an item from the current sale
- Cancel a sale in progress
- End sale — displays full formatted receipt with customer details
- Sales limit enforced per customer type per day

### Payment Management
- Look up sale by Sale ID
- View total amount, amount paid, and remaining balance
- Record partial or full payments
- Customer balance updated automatically on payment

### Customer Tier System
| Type | Sales Limit | Discount |
|---|---|---|
| Silver | Rs. 40,000 | — |
| Gold | Rs. 1,00,000 | Up to 3% |
| Platinum | Rs. 2,50,000 | Up to 5% |

---

## 🧠 OOP Concepts Applied

| Concept | Where Applied |
|---|---|
| **Classes & Objects** | `Item`, `Sale`, `SaleLineItem`, `Receipt`, `Customer`, `POS` |
| **Inheritance (Is-a)** | `GoldCustomer`, `SilverCustomer`, `PlatinumCustomer` extend `Customer` |
| **Composition (Has-a)** | `POS` has `Items`, `Customers`, `Sales`; `Sale` has `SaleLineItems` and `Receipt` |
| **Polymorphism** | Customer type behaviour (discount/limit) varies by subclass |
| **Virtual Functions** | Discount and sales limit logic overridden per customer tier |
| **Encapsulation** | Private data members with public interfaces across all classes |
| **Abstraction** | N-Tier architecture — interface separated from implementation |
| **File Handling** | All data persisted to files using `fstream` |

---

## 🏗️ Class Architecture

```
Customer  (Base Class)
├── SilverCustomer   — Limit: 40,000 | No discount
├── GoldCustomer     — Limit: 1,00,000 | Discount: up to 3%
└── PlatinumCustomer — Limit: 2,50,000 | Discount: up to 5%

POS  (Main Controller)
├── Item             — SKU, Description, Price, Quantity, CreationDate
├── Sale             — SaleID, Customer, Date, Status
│   ├── SaleLineItem — LineNo, Item, Quantity
│   └── Receipt      — ReceiptNo, Date, Amount
└── Utils            — Shared helper functions
```

### Class Data Members

| Class | Key Members |
|---|---|
| `Item` | `Item_SKU`, `Description`, `Price`, `AvailableQuantity`, `CreationDate` |
| `Customer` | `CNIC`, `Name`, `Address`, `Phone`, `Email`, `Type`, `AmountPayable`, `SalesLimit` |
| `GoldCustomer` | `Discount` (max 3%) |
| `PlatinumCustomer` | `Discount` (max 5%) |
| `Sale` | `SaleID`, `Customer`, `SalesLineItems`, `Receipt`, `Date`, `Status` |
| `SaleLineItem` | `LineNo`, `Sale`, `Item`, `Quantity` |
| `Receipt` | `ReceiptNo`, `ReceiptDate`, `Sale`, `Amount` |
| `POS` | `Items[]`, `Customers[]`, `Sales[]`, `Receipts[]` |

---

## 🖥️ Main Menu

```
Main Menu
1- Manage Items
2- Manage Customers
3- Make New Sale
4- Make Payment
5- Exit
```

---

## 🛠️ Tech Stack

| | |
|---|---|
| **Language** | C++11 |
| **Paradigm** | Object-Oriented Programming |
| **Architecture** | N-Tier (Interface separated from Implementation) |
| **Storage** | File I/O (`fstream`) |
| **Build** | g++ |
| **Platform** | Cross-platform terminal |

---

## 🚀 How to Run

```bash
# Compile all source files
g++ -o pos Project23.cpp Customer.cpp GoldCustomer.cpp SilverCustomer.cpp \
    PlatinumCustomer.cpp Item.cpp Sale.cpp SaleLineItem.cpp Receipt.cpp \
    POS.cpp Utils.cpp

# Run
./pos
```

---

## 📁 Project Structure

```
POS/
├── Customer.h / Customer.cpp
├── GoldCustomer.h / GoldCustomer.cpp
├── SilverCustomer.h / SilverCustomer.cpp
├── PlatinumCustomer.h / PlatinumCustomer.cpp
├── Item.h / Item.cpp
├── Sale.h / Sale.cpp
├── SaleLineItem.h / SaleLineItem.cpp
├── Receipt.h / Receipt.cpp
├── POS.h / POS.cpp
├── Utils.cpp
└── Project23.cpp        ← Entry point (main)
```

---

## 📌 Limitations & Possible Extensions

- Terminal-based only (no GUI)
- Flat file storage — could be replaced with a database
- Could add admin login / role-based access
- Draw-by-repetition equivalent: report generation could be expanded

---

## 📄 License

Open-source — feel free to fork or use as a learning reference.
