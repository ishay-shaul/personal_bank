
#include "Item.h"

#include <string>

#define NO_NAME "other"

Item::Item(const std::string &name, int price)
{
  this->name = name;
  this->price = price;
}

Item::Item(int price)
{
  this->price = price;
  this->name = NO_NAME;
}

std::string Item::getName() const
{
  return this->name;
}

int Item::getPrice() const
{
  return this->price;
}

void Item::setPrice(int itemPrice)
{
  this->price = itemPrice;
}