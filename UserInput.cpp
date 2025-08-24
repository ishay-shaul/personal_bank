//
// Created by ishay on 22/08/2025.
//
#include "UserInput.h"
#include <iostream>
#include "InitialSelectFactory.h"
#define GET_FILE "please enter a file path: "
#define INTRODUCE "what would you like to do?"
#define SELECT "please select one of the options: "
#define GET_SUM "get total spending of a year/month (enter: get sum)."
#define EXIT "exit (enter: exit)."
#define ADD "add a purchase (enter: add)."
#define ITEM_NAME "please enter a name: "
#define ITEM_PRICE "please enter a price: "


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

bool UserInput::checkItemInput(std::string& str)
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
    if (c < '0' || c > '9')
    {
      return false;
    }
  }
  return true;
}


void UserInput::add()
{
  std::string& givenName;
  std::string& givenPrice;
  double price;
  std::cout << ITEM_NAME;
  std::cin >> givenName;
  std::cout << ITEM_PRICE;
  std::cin >> givenPrice;
  // need to check price, year and month
  if (checkItemInput(givenPrice))
  {
    price = float(givenPrice);
  }
}

