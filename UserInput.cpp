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
