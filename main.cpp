#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include "UserInput.h"
#include "User.h"

int main()
{
  User* user = new User(10000);
//  std::cout << "here" << std::endl;
  Item* item1 = new Item ("meat", 20);
  Item* item2 = new Item("car", 1000);
//  std::cout << "here" << std::endl;
  user->addItem (item1, 2023, 6);
  user->addItem (item2, 2025, 1);
  std::cout << "here" << std::endl;
  user->display();
}