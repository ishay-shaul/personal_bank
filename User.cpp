
#include "User.h"
#include <ctime>
#include <iostream>

User::User (size_t userBudget)
{
  this->budget = userBudget;
}

// User::~User ()
// {
//   for(const auto& pair: allYears){
//     delete pair.second;
//   }
// //  for(const auto& single: years){
// //    delete single;
// //  }
//   allYears.clear();
// //  years.clear();
// }
//
// User::User (const User &other)
// {
//   for(const auto& pair: other.allYears){
//     allYears[pair.first] = new Year(*pair.second);
//   }
// //  for(const auto& single: other.years){
// //    years.push_back (new Year(*single));
// //  }
// }
//
// User &User::operator= (const User &other)
// {
//   if(this != &other){
//     for(const auto& pair: allYears){
//       delete pair.second;
//     }
// //    for(const auto& single: years){
// //      delete single;
// //    }
//     allYears.clear();
// //    years.clear();
//
//     for(const auto& pair: other.allYears){
//       allYears[pair.first] = new Year(*pair.second);
//     }
// //    for(const auto& single: other.years){
// //      years.push_back (new Year(*single));
// //    }
//   }
//   return *this;
// }

void User::addItem (std::unique_ptr<Item>item, int year, int month)
{
  if (allYears.find(year) == allYears.end())
  {
    allYears[year] = std::make_unique<Year>(year);
  }

  // Year* yearPtr = allYears[year].get();
  //
  // if (!yearPtr->findMonth(month))
  // {
  //   yearPtr->addMonth(std::make_unique<Month>(month));
  // }
  //
  // yearPtr->addItem(std::move(item), month);
  allYears[year]->addItem(std::move(item), month);
}

Year* User::findYear (int num)
{
  auto it = allYears.find (num);
  if(it != allYears.end()){
    return it->second.get();
  }
  return nullptr;
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
  for(const auto& year: allYears){
    year.second->display();
  }
}