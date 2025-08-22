//
// Created by ishay on 21/08/2025.
//

#ifndef UNTITLED1_MONTH_H
#define UNTITLED1_MONTH_H
#include <unordered_map>
#include <vector>
#include "Item.h"

class Month
{
  private:
    std::unordered_map< std::string, Item*> monthlyPurchases;
    std::vector<Item*> purchasesOrdered;
    int month;

  public:
    Month(int num);
    void addItem(Item* item);
    void display();
    Item* getItem(std::string name);
    Item* getLastItem();
    int getMonthNumber();
    Month* getMonth();
    size_t getTotal();
};

#endif //UNTITLED1_MONTH_H