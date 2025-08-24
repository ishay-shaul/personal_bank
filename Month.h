//
// Created by ishay on 21/08/2025.
//

#ifndef UNTITLED1_MONTH_H
#define UNTITLED1_MONTH_H
#include <unordered_map>
#include <vector>
#include <memory>
#include "Item.h"

class Month
{
  private:
//    std::unordered_map< std::string, Item*> monthlyPurchases;
  std::unordered_map< std::string, std::unique_ptr<Item>> monthlyPurchases;
    // std::vector<std::unique_ptr<Item>> purchasesOrdered;
    int month;

  public:
    Month(int num);
    void addItem(std::unique_ptr<Item> item);
    void display() const;
//    ~Month();
//    Month(const Month& other);
//    Month& operator= (const Month& other);
  Item* getItem(const std::string& name);
  // Item* getLastItem();
    int getMonthNumber() const;
    Month* getMonth();
    size_t getTotal() const;
};

#endif //UNTITLED1_MONTH_H