//
// Created by ishay on 21/08/2025.
//
#include "Year.h"

#include <iostream>
#include <ostream>
#define YEAR "Year: "

Year::Year(int num)
{
  year = num;
}

void Year::display() const
{
  std::cout << YEAR << year<< std::endl;
  for(const auto& month: allMonths){
    month.second->display();
  }
}

void Year::addMonth(std::unique_ptr<Month> month)
{
  const int monthNum = month->getMonthNumber();
  if(allMonths.find(monthNum) != allMonths.end()){
    return;
  }
  allMonths[monthNum] = std::move(month);
}

void Year::addItem(std::unique_ptr<Item>item, int month)
{
  if(allMonths.find(month) == allMonths.end()){
    allMonths[month] = std::make_unique<Month>(month);
  }
  allMonths[month]->addItem (std::move(item));
}

int Year::getYear() const
{
  return year;
}

Month *Year::getMonth (int num)
{
  auto it = allMonths.find(num);
  if(it != allMonths.end())
  {
    return it->second.get();
  }
  return nullptr;
}

double Year::getTotal () const
{
  double total = 0;
  for(auto& pair: allMonths){
      total += pair.second->getTotal();
  }
  return total;
}

Month *Year::findMonth (int num) const
{
  return allMonths.find(num)->second.get();
}

std::unordered_map<int, std::unique_ptr<Month> > Year::getAllMonths()
{
  return allMonths;
}

