//
// Created by ishay on 21/08/2025.
//

#ifndef UNTITLED1_YEAR_H
#define UNTITLED1_YEAR_H
#include <unordered_map>
#include <vector>
#include "Month.h"

class Year
{
  private:
    std::unordered_map<int, std::unique_ptr<Month>> allMonths; // maybe should be linked list
//    std::vector<Month*> allMonths;
    int year{};
    public:
    Year(int num);
    // ~Year();
    // Year(const Year& other);
    // Year& operator= (const Year& other);
    int getYear() const;
    void addMonth(std::unique_ptr<Month> month);
    Month* findMonth(int num);
    void addItem(std::unique_ptr<Item> item, int month);
    void display();
    Month* getMonth(int num);
    size_t getTotal();
};

#endif //UNTITLED1_YEAR_H