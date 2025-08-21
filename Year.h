//
// Created by ishay on 21/08/2025.
//

#ifndef UNTITLED1_YEAR_H
#define UNTITLED1_YEAR_H
#include <unordered_map>
#include "Month.h"

class Year
{
  private:
    std::unordered_map<int, Month*> yearlyPurchases; // maybe should be linked list
    int year;
    public:
    Year(int num);
    ~Year();
    int getYear();
    void addMonth(Month* month);
    void addItem(Item* item);
    void display();
    Month* getMonth(std::string name);
};

#endif //UNTITLED1_YEAR_H