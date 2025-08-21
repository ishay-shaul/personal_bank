//
// Created by ishay on 21/08/2025.
//

#include "Month.h"

Month::Month(int num)
{
  this->month = num;
}

void Month::addItem(Item* item)
{
  this->monthlyPurchases[item->getName()] = item;
}

void Month::display()
{
  //pass
}

Item* Month::getItem(std::string name)
{
  if (monthlyPurchases.find(name) != monthlyPurchases.end())
  {
    return monthlyPurchases[name];
  }
  else
  {
    return nullptr;
  }
}

int Month::getMonth()
{
  return month;
}




