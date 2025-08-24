#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include "UserInput.h"
#include "User.h"
#include "Year.h"
#include <memory>

int main()
{
  auto user = std::make_unique<User>(10000);
  auto userInput = std::make_unique<UserInput>(std::move(user));
  while (true)
  {
    userInput->options();
    if (userInput->isFinished())
    {
      std::cout << "see you next time" << std::endl;
      break;
    }
  }
}