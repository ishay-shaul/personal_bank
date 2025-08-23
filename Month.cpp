
#include "Month.h"
#include <iostream>

Month::Month(int num)
{
  this->month = num;
}

void Month::addItem(std::unique_ptr<Item> item)
{
  monthlyPurchases[item->getName()] = std::move(item);
  // purchasesOrdered.push_back (std::move(item));
}

void Month::display()
{
  for(const auto& purchase: monthlyPurchases){
    std::cout << purchase.second->getName() << " " << purchase.second->getPrice() << std::endl;
  }
}

Item* Month::getItem(std::string name)
{
  auto it = monthlyPurchases.find(name);
  if (it != monthlyPurchases.end())
  {
    return it->second.get();
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

// Item *Month::getLastItem ()
// {
//   return purchasesOrdered.front().get();
// }

size_t Month::getTotal ()
{
  size_t total = 0;
  for(const auto& pair: monthlyPurchases){
    total += pair.second->getPrice();
  }
  return total;
}