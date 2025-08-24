#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include "UserInput.h"
#include "User.h"
#include "Year.h"
#include <memory>

int main()
{
  using std::unique_ptr;
//  User* user = new User(10000);
//  auto item1 = std::make_unique<Item>("meat", 20);
//  Item* item2 = new Item("car", 1000);
  auto item1 = std::make_unique<Item>("meat", 20);
  auto item2 = std::make_unique<Item>("car", 1000);
  auto item3 = std::make_unique<Item>("milk", 500);
  auto item4 = std::make_unique<Item>("purse", 100);
  auto year = std::make_unique<Year>(2025);
  auto user = new User(10000);
  // std::cout << "created everything" << std::endl;
  // year->addItem(std::move(item1), 12);
  // year->addItem(std::move(item2), 12);
  // year->addItem(std::move(item3), 5);
  // year->addItem(std::move(item4), 5);
  // std::cout << "added items" << std::endl;
  user->addItem(std::move(item1), 2025, 4);
  user->addItem(std::move(item2), 2025, 4);
  user->addItem(std::move(item3), 2025, 12);
  user->addItem(std::move(item4), 2025, 12);
  std::cout << user->getYearlyTotal(2020) << std::endl;
}