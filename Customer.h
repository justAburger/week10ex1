#pragma once
#include"Item.h"
#include<set>

class Customer
{
public:
	Customer(std::string);
	Customer();
	~Customer();
	double totalSum() const;//returns the total sum for payment
	void addItem(Item);//add item to the set
	void removeItem(Item);//remove item from the set

	//get and set functions
	std::string getName() const;
	void setName(std::string name);
	void printItems() const;

private:
	std::string _name;
	std::set<Item> _items;
};