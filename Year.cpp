//
// Created by ishay on 21/08/2025.
//
#include "Year.h"

Year::Year(int num)
{
  this->year = num;
}

Year::~Year()
{
  free(this->yearlyPurchases);
}

void Year::display()
{
  //pass
}

void Year::addMonth(Month *month)
{
  this->yearlyPurchases[month->getMonth()] = month;
}

void Year::addItem(Item *item) // do i assume that the last item is always of the last month?
{

}




