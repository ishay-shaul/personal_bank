
#ifndef _USER_H_
#define _USER_H_
#include "Year.h"

class User{
 private:
    std::unordered_map<int, Year*> allYears;
//    std::vector<Year*> years;
    size_t budget;
    Year* findYear(int num);

 public:
    User(size_t userBudget);
    bool addItem(Item* item, int year, int month);
    void display();
    ~User();
    User(const User& other);
    User& operator= (const User& other);
//    Year* getYear(int num);
//    Item* getItem();
    size_t getMonthlyTotal(int monthNum, int year);
    size_t getYearlyTotal(int year);
};
#endif //_USER_H_