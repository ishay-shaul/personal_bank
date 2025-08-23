
#ifndef _USER_H_
#define _USER_H_
#include "Year.h"

class User
{
  private:
    std::unordered_map<int, std::unique_ptr<Year> > allYears;
    //    std::vector<Year*> years;
    size_t budget;
    Year* findYear(int num);

 public:
    User(size_t userBudget);
    void addItem(std::unique_ptr<Item> item, int year, int month);
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