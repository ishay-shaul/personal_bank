
#include "User.h"
#include <ctime>
#include <iostream>

User::User (size_t userBudget)
{
  this->budget = userBudget;
}

void User::addItem (std::unique_ptr<Item>item, int year, int month)
{
  if (allYears.find(year) == allYears.end())
  {
    allYears[year] = std::make_unique<Year>(year);
  }
  allYears[year]->addItem(std::move(item), month);
}

Year* User::findYear (int num)
{
  const auto it = allYears.find (num);
  if(it != allYears.end()){
    return it->second.get();
  }
  return nullptr;
}

double User::getYearlyTotal (const int year)
{
  const Year* requestedYear = findYear (year);
  if(requestedYear == nullptr){
    return 0;
  }
  return requestedYear->getTotal();
}

double User::getMonthlyTotal (const int monthNum, const int year)
{
  Year* requestedYear = findYear (year);
  if(requestedYear == nullptr){
    return 0;
  }
  const Month* requestedMonth = requestedYear->getMonth (monthNum);
  if(requestedMonth == nullptr){
    return 0;
  }
  return requestedMonth->getTotal();
}

void User::display () const
{
  for(const auto& year: allYears){
    year.second->display();
  }
}
