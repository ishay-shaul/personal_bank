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
  this->purchasesOrdered.push_back (item);
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

int Month::getMonthNumber()
{
  return month;
}

Month* Month::getMonth(){
  return this;
}

Item *Month::getLastItem ()
{
  return this->purchasesOrdered.front();
}

size_t Month::getTotal ()
{
  size_t total = 0;
  for(auto it = this->purchasesOrdered.begin(); it != this->purchasesOrdered
  .end(); it++){
    Item* curItem = *it;
    total += curItem->getPrice();
  }
  return total;
}




