//
// Created by ishay on 21/08/2025.
//
#include "Year.h"

Year::Year(int num)
{
  this->year = num;
}

//Year::~Year()
//{
//  free(this->yearlyPurchases);
//}

void Year::display()
{
  for(auto month: allMonths){
    month->display();
  }
}

void Year::addMonth(Month *month)
{
//  this->yearlyPurchases[month->getMonth()] = month;
  allMonths.push_back(month);
}

void Year::addItem(Item *item) // do i assume that the last item is always of the last month?
{
  this->allMonths.front()->addItem (item);
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
    return this->allMonths[this->allMonths.size() - num];
  }
}

size_t Year::getTotal ()
{
  size_t total = 0;
  for(auto it = this->allMonths.begin(); it != this->allMonths
  .end(); it++){
      Month* curMonth = *it;
      total += curMonth->getTotal();
  }
  return total;
}

Month *Year::findMonth (int num)
{
  if(num < 0 || num > allMonths.size()){
    return nullptr;
  }
  return allMonths[allMonths.size() - num];
}


