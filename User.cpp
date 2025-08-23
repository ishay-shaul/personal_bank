
#include "User.h"
#include <ctime>
#include <iostream>

User::User (size_t userBudget)
{
  this->budget = userBudget;
}

User::~User ()
{
  for(const auto& pair: allYears){
    delete pair.second;
  }
//  for(const auto& single: years){
//    delete single;
//  }
  allYears.clear();
//  years.clear();
}

User::User (const User &other)
{
  for(const auto& pair: other.allYears){
    allYears[pair.first] = new Year(*pair.second);
  }
//  for(const auto& single: other.years){
//    years.push_back (new Year(*single));
//  }
}

User &User::operator= (const User &other)
{
  if(this != &other){
    for(const auto& pair: allYears){
      delete pair.second;
    }
//    for(const auto& single: years){
//      delete single;
//    }
    allYears.clear();
//    years.clear();

    for(const auto& pair: other.allYears){
      allYears[pair.first] = new Year(*pair.second);
    }
//    for(const auto& single: other.years){
//      years.push_back (new Year(*single));
//    }
  }
  return *this;
}

bool User::addItem (Item *item, int year, int month)
{
  Year* userYear = findYear (year);
  if(userYear == nullptr){
    std::cout << "got here" << std::endl;
    userYear = new Year(year);
    allYears[year] = userYear;
  }
  userYear->findMonth (month)->addItem (item);
  if(!userYear->findMonth (month)){
    userYear->addMonth (new Month(month));
    userYear->addItem (item, month);
  }
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

void User::display ()
{
  for(auto year: allYears){
    year.second->display();
  }
}