
#include "Month.h"
#include <iostream>

Month::Month(int num)
{
  this->month = num;
}

void Month::addItem(std::unique_ptr<Item> item)
{
  const Item* curItem = item.get();
  monthlyPurchases[curItem->getName()] = std::move(item);
}

void Month::display() const
{
  for(const auto& purchase: monthlyPurchases){
    std::cout << purchase.second->getName() << " " << purchase.second->getPrice() << std::endl;
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

// Item *Month::getLastItem ()
// {
//   return purchasesOrdered.front().get();
// }

size_t Month::getTotal () const
{
  size_t total = 0;
  for(const auto& pair: monthlyPurchases){
    total += pair.second->getPrice();
  }
  return total;
}