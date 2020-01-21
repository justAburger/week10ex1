#include "Customer.h"

Customer::Customer(std::string name) : _name(name)
{
}

Customer::Customer()
{
}

Customer::~Customer()
{/*
	_name.clear();
	std::set<Item>::iterator todelete;
	Item* curr;
	for (todelete = _items.begin(); todelete != _items.end(); todelete++)
	{
		curr = &((Item)*todelete);
		delete curr;
	}
	*/
}

std::string Customer::getName() const
{
	return _name;
}

void Customer::setName(std::string name)
{
	this->_name = name;
}

double Customer::totalSum() const
{
	std::set<Item>::iterator it;
	double sum = 0;
	Item* curr;
	for (it = _items.begin(); it != _items.end(); it++)
	{
		curr = &((Item)*it);
		sum += curr->totalPrice();
	}
	return sum;
}

void Customer::addItem(Item item)
{
	std::set<Item>::iterator it = _items.find(item);
	if (it != _items.end())
	{
		Item newItem(it->getName(), it->getSerial(), it->getPrice());
		newItem.setCount(it->getCount() + 1);
		_items.erase(*it);
		_items.insert(newItem);
	}
	else
	{
		this->_items.insert(item); //else just add new item
	}
}

void Customer::removeItem(Item item)
{
	if (item.getCount() == 1)
	{
		_items.erase(item); 
	}
	else
	{
		item.setCount(item.getCount() - 1);
	}
}


void Customer::printItems() const
{
	std::set<Item>::iterator it;
	Item curr();
	// printing all the elements of the set 
	for (it = this->_items.begin(); it != this->_items.end(); ++it)
	{
		std::cout << ((Item)*it).getName() << std::endl;
	}
}

