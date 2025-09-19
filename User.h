
#ifndef _USER_H_
#define _USER_H_
#include "Year.h"

class User
{
  private:
    /** mapping all years and their objects*/
    std::unordered_map<int, std::unique_ptr<Year> > allYears;
    /** the budget of the user*/
    size_t budget;
    /**
     * method that finds a year in the map
     * @param num the year
     * @return a year pointer if found, nullptr otherwise
     */
    Year* findYear(int num);

 public:
    /**
     * constructs a user object
     * @param userBudget the budget of the user
     */
    explicit User(size_t userBudget);
    /**
     * adds an item to the map
     * @param item   a pointer to the item that is being added
     * @param year   the year of the purchase
     * @param month  the month of the purchase
     */
    void addItem(std::unique_ptr<Item> item, int year, int month);
    /**
     * displays all items that were bought by the user
     */
    void display() const; // do for year and month
    /**
     * calculates how much the user spent in a certain month
     * @param monthNum the month
     * @param year     the year
     * @return teh sum if the year and month exist in the map, zero otherwise
     */
    double getMonthlyTotal(int monthNum, int year);
    /**
     * calculates the total amount the user spent in a certain year
     * @param year the year who's spending we are totaling
     * @return the sum if the year exists in the map, zero otherwise
     */
    double getYearlyTotal(int year);
    /**
     * checks if a year exists for the user
     * @param year the year that is being checked
     * @return true if the year exists, false otherwise
     */
    bool existYear(int year);
    /**
     * checks if a month exists in the system
     * @param monthNum the month number
     * @param year the year number
     * @return true if it does exist in the system, false otherwise
     */
    bool existMonth(int monthNum, int year);
    /**
     * checks if the system is empty
     * @return true if it's empty, false otherwise
     */
    bool isEmpty();
};
#endif //_USER_H_