
#include "Month.h"
#include <iostream>
#define EMPTY " "

Month::Month(int num)
{
  month = num;
}

void Month::addItem(std::unique_ptr<Item> item)
{
  const Item* curItem = item.get();
  monthlyPurchases[curItem->getName()] = std::move(item);
}

void Month::display() const
{
  for(const auto& purchase: monthlyPurchases){
    std::cout << purchase.second->getName() << EMPTY << purchase.second->getPrice() << std::endl;
  }
}

Item* Month::getItem(const std::string& name)
{
  const auto it = monthlyPurchases.find(name);
  if (it != monthlyPurchases.end())
  {
    return it->second.get();
  }
  return nullptr;
}

int Month::getMonthNumber() const
{
  return month;
}

Month* Month::getMonth(){
  return this;
}

double Month::getTotal () const
{
  double total = 0;
  for(const auto& pair: monthlyPurchases){
    total += pair.second->getPrice();
  }
  return total;
}