//
// Created by ishay on 21/08/2025.
//

#ifndef UNTITLED1_MONTH_H
#define UNTITLED1_MONTH_H
#include <unordered_map>
#include "Item.h"

class Month
{
  private:
    std::unordered_map< std::string, Item*> monthlyPurchases;
    int month;

  public:
    Month(int num);
    void addItem(Item* item);
    void display();
    Item* getItem(std::string name);
    int getMonth();
};

#endif //UNTITLED1_MONTH_H