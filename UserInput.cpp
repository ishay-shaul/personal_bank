//
// Created by ishay on 22/08/2025.
//
#include "UserInput.h"
#include <iostream>
#include <memory>

#include "InitialSelectFactory.h"
#include "Item.h"
#define GET_FILE "please enter a file path: "
#define INTRODUCE "what would you like to do?"
#define SELECT "please select one of the options: "
#define GET_SUM "get total spending of a year/month (enter: get sum)."
#define EXIT "exit (enter: exit)."
#define ADD "add a purchase (enter: add)."
#define ITEM_NAME "please enter a name: "
#define ITEM_PRICE "please enter a price: "
#define ZERO_C '0'
#define ONE_C '1'
#define NINE_C '9'
#define NOT_NUM = "price entered was not a number"
#define ITEM_MONTH "please enter a month(as a number): "
#define ITEM_YEAR "please enter a year: "
#define NO_OPTION "no such option"
#define DASH '-'
#define DECIMAL '.'
#define YEAR_LEN 4
#define MAX_MONTH 2
#define MIN_YEAR 1970
#define MAX_YEAR 2025
#define WRONG_PRICE "price entered is invalid"
#define WRONG_MONTH "month entered is invalid"
#define WRONG_YEAR "year entered is invalid"
#define DECEMBER 12

UserInput::UserInput(std::unique_ptr<User> user)
{
  this->user = std::move(user);
}

void UserInput::exit()
{
  finish = true;
}

bool UserInput::isFinished() const
{
  return finish;
}



void UserInput::getFile ()
{
  std::string filePath;
  std::cout << GET_FILE;
  std::cin >> filePath;

}

std::string UserInput::firstInput ()
{
  using std::cout;
  std::string option;
  cout << INTRODUCE << std::endl;
  cout << SELECT << std::endl;
  cout << GET_SUM << std::endl;
  cout << ADD << std::endl;
  cout << EXIT << std::endl;
  std::cin >> option;
  return option;
}

void UserInput::options()
{
 std::string input = firstInput();
 auto factory = new InitialSelectFactory (this);
  while (true)
  {
    if (!factory->getSelection (input))
    {
      std::cout << NO_OPTION << std::endl;
      continue;
    }
    break;
  }
}

bool UserInput::checkPriceInput(std::string& str)
{
  if (str.empty()){return false;}
  bool decimal = false;
  for (int i = 0; i < str.size(); i++)
  {
    char c = str[i];
    // checking if negative
    if (i == 0 && c == DASH){return false;}
    // if a decimal appears, make sure it appears once
    if (c == DECIMAL)
    {
      if (decimal){return false;}
      decimal = true;
      continue;
    }
    if (c < ZERO_C || c > NINE_C)
    {
      return false;
    }
  }
  return true;
}

void UserInput::add()
{
  std::string givenName;
  std::cout << ITEM_NAME;
  std::cin >> givenName;
  double price = acceptPrice();
  int month = acceptMonth();
  int year = acceptYear();
  user->addItem(std::make_unique<Item>(givenName, price), year, month);
}

bool UserInput::checkMonthInput(std::string &str)
{
  // if the length is too long
  if (str.length() < 1 || str.length() > MAX_MONTH){return false;}
  // making sure all are between 0 and 9
  for (int i = 0; i < str.size(); i++)
  {
    const char c = str[i];
    if (c < ZERO_C || c > NINE_C){return false;}
    if (i == MAX_MONTH && str[0] > 1){return false;}
  }
  const int month = std::stoi(str);
  // is month > 12?
  if (month < 0 || month > DECEMBER){return false;}
  return true;
}

bool UserInput::checkYearInput(std::string &str)
{
  if (str.length() != YEAR_LEN){return false;}
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] < ZERO_C || str[i] > NINE_C){return false;}
  }
  int year = std::stoi(str);
  if (year < MIN_YEAR || year > MAX_YEAR)
  {
    return false;
  }
  return true;
}

double UserInput::acceptPrice()
{
  std::string givenPrice;
  while (true)
  {
    std::cout << ITEM_PRICE;
    std::cin >> givenPrice;
    if (!checkPriceInput(givenPrice))
    {
      std::cout << WRONG_PRICE << std::endl;
      continue;
    }
    double price = std::stod(givenPrice);
    return price;
  }
}

int UserInput::acceptMonth()
{
  std::string givenMonth;
  while (true)
  {
    std::cout << ITEM_MONTH;
    std::cin >> givenMonth;
    if (!checkMonthInput(givenMonth))
    {
      std::cout << WRONG_MONTH << std::endl;
      continue;
    }
    int month = std::stoi(givenMonth);
    return month;
  }
}

int UserInput::acceptYear()
{
  std::string givenYear;
  while (true)
  {
    std::cout << ITEM_YEAR;
    std::cin >> givenYear;
    if (!checkYearInput(givenYear))
    {
        std::cout << WRONG_YEAR << std::endl;
      continue;
    }
    int year = std::stoi(givenYear);
    return year;
  }
}

double UserInput::getMonthSum()
{
  const int year = acceptYear();
  const int month = acceptMonth();
  return user->getMonthlyTotal(month, year);
}

double UserInput::getYearSum()
{
  const int year = acceptYear();
  return user->getYearlyTotal(year);
}
