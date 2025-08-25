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
    /**maps each item to its name*/
  std::unordered_map< std::string, std::unique_ptr<Item>> monthlyPurchases;
    /** the month number(1 for january, 12 for december)*/
    int month;

  public:
    /**
     * constructs a month object
     * @param num the month number
     */
    Month(int num);
    /**
     * method that adds an item to the map of purchases
     * @param item the item that is added to the map
     */
    void addItem(std::unique_ptr<Item> item);
    /**
     * displays all items that were purchased by the user by the following format:
     * (name of the item)    (price of object)
     */
    void display() const;
    /**
     * method that checks if a certain item name exists in the map
     * @param name of the item we would like to know if exists in the map
     * @return in case the item exists it will return the item, nullptr otherwise
     */
    Item* getItem(const std::string& name);
    /**
     * getter for the month number
     * @return the month number
     */
    int getMonthNumber() const;
    /**
     * getter for the Month object itself
     * @return the method returns: *this
     */
    Month* getMonth();
    /**
     * method that calculates how much the user spent this month
     * @return the sum of all item prices
     */
    double getTotal() const;
};

#endif //UNTITLED1_MONTH_H