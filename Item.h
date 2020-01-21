#pragma once
#include<iostream>
#include<string>
#include<algorithm>


class Item
{
public:
	Item(std::string, std::string, double);
	~Item();

	double totalPrice() const; //returns _count*_unitPrice
	bool operator <(const Item& other) const; //compares the _serialNumber of those items.
	bool operator >(const Item& other) const; //compares the _serialNumber of those items.
	bool operator ==(const Item& other) const; //compares the _serialNumber of those items.
	//get and set functions
	std::string getSerial() const;
	double getPrice() const;
	std::string getName() const;
	int getCount() const;

	void setCount(int count);

private:
	std::string _name;
	std::string _serialNumber; //consists of 5 numbers
	int _count; //default is 1, can never be less than 1!
	double _unitPrice; //always bigger than 0!

};