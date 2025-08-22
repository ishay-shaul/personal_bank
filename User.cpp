//
// Created by ishay on 22/08/2025.
//

#include "User.h"
#include <ctime>

User::User (size_t userBudget)
{
  this->budget = userBudget;
}

bool User::addItem (Item *item, int year, int month)
{
  Year* userYear = findYear (year);
  if(userYear == nullptr){
    return false;
  }
  userYear->findMonth (month)->addItem (item);
  return true;
}

Year *User::findYear (int num)
{
  auto it = allYears.find (num);
  if(it == allYears.end()){
    return nullptr;
  }
  else{
    return it->second;
  }
}

size_t User::getYearlyTotal (int year)
{
  Year* requestedYear = findYear (year);
  if(requestedYear == nullptr){
    return 0;
  }
  else{
    return requestedYear->getTotal();
  }
}

size_t User::getMonthlyTotal (int monthNum, int year)
{
  Year* requestedYear = findYear (year);
  if(requestedYear == nullptr){
    return 0;
  }
  Month* requestedMonth = requestedYear->getMonth (monthNum);
  if(requestedMonth == nullptr){
    return 0;
  }
  else{
    return requestedMonth->getTotal();
  }
}