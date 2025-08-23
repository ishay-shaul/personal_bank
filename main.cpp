#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include "UserInput.h"
#include "User.h"
#include <memory>

int main()
{
  using std::unique_ptr;
//  User* user = new User(10000);
//  auto item1 = std::make_unique<Item>("meat", 20);
//  Item* item2 = new Item("car", 1000);
  auto item1 = std::make_unique<Item>("meat", 20);
  auto item2 = std::make_unique<Item>("car", 1000);
  auto month = new Month(5);
  month->addItem(std::move(item1));
  month->addItem(std::move(item2));
  month->display();


//  std::cout << "here" << std::endl;
//  user->addItem (item1, 2023, 6);
//  user->addItem (item2, 2025, 1);
//  std::cout << "here" << std::endl;
//  user->display();
}