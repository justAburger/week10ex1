#include "Item.h"

Item::Item(std::string name, std::string serial_num, double unitPrice) : _serialNumber(serial_num), _unitPrice(unitPrice), _name(name), _count(1)
{
}

Item::~Item()
{
}

double Item::totalPrice() const
{
	return _count * _unitPrice;
}

//getters and setters
double Item::getPrice() const
{
	return _unitPrice;
}
std::string Item::getSerial() const
{
	return _serialNumber;
}
std::string Item::getName() const
{
	return _name;
}
int Item::getCount() const
{
	return this->_count;
}
void Item::setCount(int count)
{
	this->_count = count;
}

bool Item::operator<(const Item& other) const
{
	return this->getSerial() < other.getSerial();
}

bool Item::operator>(const Item& other) const
{
	return this->getSerial() > other.getSerial();
}

bool Item::operator==(const Item& other) const
{
	return this->getSerial() == other.getSerial();
}