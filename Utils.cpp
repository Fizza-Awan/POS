#pragma once

#ifndef _UTILS_
#define _UTILS_

template <typename Type>
void addElementToArray(Type**& items, int& n_items, Type* item)
{
	Type** newSaleLineItems = new Type * [n_items + 1];

	for (int i = 0; i < n_items; i++) { newSaleLineItems[i] = items[i]; }
	newSaleLineItems[n_items] = item;

	n_items++;
	delete[] items;
	items = newSaleLineItems;
}

template <typename Type>
int FindElementIndexInArray(Type**& items, int& n_items, Type* item)
{
	for (int i = 0; i < n_items; i++) if (items[i] == item) return i;
	return -1;
}

template <typename Type>
void RemoveElementFromArray(Type**& items, int& n_items, Type* item)
{
	Type** newSaleLineItems = new Type * [n_items - 1];

	int itemIndex = FindElementIndexInArray<Type>(items, n_items, item);

	for (int i = 0; i < n_items-1; i++)
	{
		if (i < itemIndex) newSaleLineItems[i] = items[i];
		else newSaleLineItems[i] = items[i+1];
	}

	n_items--;
	delete[] items;
	items = newSaleLineItems;
}
#endif
