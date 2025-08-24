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

UserInput::UserInput(std::unique_ptr<User> user)
{
  this->user = std::move(user);
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
  cout << INTRODUCE;
  cout << SELECT;
  cout << GET_SUM;
  cout << ADD;
  cout << EXIT;
  std::cin >> option;
  return option;
}

void UserInput::options()
{
 std::string input = firstInput();
 InitialSelectFactory* factory = new InitialSelectFactory (this);
  factory->getSelection (input); // uses rest of methods in this class
}

bool UserInput::checkPriceInput(std::string& str)
{
  if (str.empty()){return false;}
  bool decimal = false;
  for (int i = 0; i < str.size(); i++)
  {
    char c = str[i];
    if (i == 0 && c == '-'){return false;}
    if (c == '.')
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
  std::string& givenName;
  std::cout << ITEM_NAME;
  std::cin >> givenName;
  double price = acceptPrice();
  int month = acceptMonth();
  int year = acceptYear();
  user->addItem(std::make_unique<Item>(givenName, price), year, month);
}

bool UserInput::checkMonthInput(std::string &str)
{
  if (str.length() < 1 || str.length() > 2){return false;}
  for (int i = 0; i < str.size(); i++)
  {
    char c = str[i];
    if (c < ZERO_C || c > NINE_C){return false;}
    if (i == 2 && str[0] > 1){return false;}
  }
  return true;
}

bool UserInput::checkYearInput(std::string &str)
{
  if (str.length() != 4){return false;}
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] < '0' || str[i] > '9'){return false;}
  }
  int year = std::stoi(str);
  if (year < 1970 || year > 2025)
  {
    return false;
  }
  return true;
}

double UserInput::acceptPrice()
{
  std::string& givenPrice;
  while (true)
  {
    std::cout << ITEM_PRICE;
    std::cin >> givenPrice;
    if (!checkPriceInput(givenPrice))
    {
      std::cout << "price entered was not a number";
      continue;
    }
    double price = std::stod(givenPrice);
    return price;
  }
}

int UserInput::acceptMonth()
{
  std::string& givenMonth;
  while (true)
  {
    std::cout << ITEM_MONTH;
    std::cin >> givenMonth;
    if (!checkMonthInput(givenMonth))
    {
      std::cout << "month entered was not a number";
      continue;
    }
    int month = std::stoi(givenMonth);
    return month;
  }
}

bool UserInput::checkYearInput(std::string &str)
{
  std::string& givenYear;
  while (true)
  {
    std::cout << ITEM_YEAR;
    std::cin >> givenYear;
    if (!checkMonthInput(givenYear))
    {
      std::cout << "year entered was not a number";
      continue;
    }
    int month = std::stoi(givenYear);
    return month;
  }
}
