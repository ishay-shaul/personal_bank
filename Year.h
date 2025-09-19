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
    /**mapping the months to their Month object*/
    std::unordered_map<int, std::unique_ptr<Month>> allMonths;
    /**the year(e.g. 2025)*/
    int year;

    public:
    /**
     * constructor for a Year object
     * @param num the year itself
     */
    explicit Year(int num);
    /**
     * getter for the year number
     * @return the year number
     */
    int getYear() const;
    /**
     * adds a month to the map. If it exists, then nothing happens
     * @param month Month object we want to add to the map
     */
    void addMonth(std::unique_ptr<Month> month);
    /**
     * finding a month in the map
     * @param num the month number rather than the object
     * @return a pointer to a Month object if found, nullptr otherwise
     */
    Month* findMonth(int num) const;
    /**
     * adding an item to the year
     * @param item  item object that the user bought
     * @param month the month the item was bought
     */
    void addItem(std::unique_ptr<Item> item, int month);
    /**
     * displays all items the user bought in said year. same format as the month
     */
    void display() const;
    /**
     * method to get a pointer to a month object in the map
     * @param num the month number
     * @return Month* if the month was found, nullptr otherwise
     */
    Month* getMonth(int num);
    /**
     * method that calculates how much the user spent in the year
     * @return the sum of the spending
     */
    double getTotal() const;
};

#endif //UNTITLED1_YEAR_H