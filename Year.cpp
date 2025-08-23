//
// Created by ishay on 21/08/2025.
//
#include "Year.h"

Year::Year(int num)
{
  year = num;
}

// Year::~Year()
// {
//   for(auto& pair: allMonths){
//     delete pair.second;
//   }
// }
//
// Year::Year (const Year &other)
// {
//   for(const auto& pair: other.allMonths){
//     allMonths[pair.first] = new Month(*pair.second);
//   }
// }
//
// Year &Year::operator= (const Year &other)
// {
//   if(this != &other){
//     for(const auto& pair: allMonths){
//       delete pair.second;
//     }
//     allMonths.clear();
//
//     for(const auto& pair: other.allMonths){
//       allMonths[pair.first] = new Month(*pair.second);
//     }
//   }
//   return *this;
// }

void Year::display()
{
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
//  allMonths.push_back(month);
}

void Year::addItem(std::unique_ptr<Item>item, int month) // do i assume that the last item is
// always of the last month?
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

size_t Year::getTotal ()
{
  size_t total = 0;
  for(auto& pair: allMonths){
      total += pair.second->getTotal();
  }
  return total;
}

Month *Year::findMonth (int num)
{
  return allMonths.find(num)->second.get();
}


