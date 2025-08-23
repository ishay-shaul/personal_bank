//
// Created by ishay on 21/08/2025.
//
#include "Year.h"

Year::Year(int num)
{
  year = num;
}

Year::~Year()
{
  for(auto& pair: allMonths){
    delete pair.second;
  }
}

Year::Year (const Year &other)
{
  for(const auto& pair: other.allMonths){
    allMonths[pair.first] = new Month(*pair.second);
  }
}

Year &Year::operator= (const Year &other)
{
  if(this != &other){
    for(const auto& pair: allMonths){
      delete pair.second;
    }
    allMonths.clear();

    for(const auto& pair: other.allMonths){
      allMonths[pair.first] = new Month(*pair.second);
    }
  }
  return *this;
}

void Year::display()
{
  for(auto month: allMonths){
    month.second->display();
  }
}

void Year::addMonth(Month *month)
{
  int monthNum = month->getMonthNumber();
  if(allMonths.find(monthNum) != allMonths.end()){
    return;
  }
  allMonths[monthNum] = month;
//  allMonths.push_back(month);
}

void Year::addItem(Item *item, int month) // do i assume that the last item is
// always of the last month?
{
  if(allMonths.find(month) == allMonths.end()){
    allMonths[month] = new Month(month);
  }
  allMonths[month]->addItem (item);
}

int Year::getYear()
{
  return this->year;
}

Month *Year::getMonth (int num)
{
  if(num > 12 or num < 1){
    return nullptr;
  }
  else if(this->allMonths.size() < num){
    return nullptr;
  }
  else{
    return allMonths[num];
  }
}

size_t Year::getTotal ()
{
  size_t total = 0;
  for(auto it = this->allMonths.begin(); it != this->allMonths
  .end(); it++){
      Month* curMonth = it->second;
      total += curMonth->getTotal();
  }
  return total;
}

Month *Year::findMonth (int num)
{
  if(num < 0 || num > allMonths.size()){
    return nullptr;
  }
  return allMonths[num-1];
}


