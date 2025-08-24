//
// Created by ishay on 21/08/2025.
//

#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H
#include <string>
/**
 * this class represents an item that the user has bought. it contains a name and price.
 */
class Item
{
  private:
    /**will help the user remember what he/she bought*/
    std::string name;
    /** the price will help later on determine if we crossed the budget*/
    double price;

  public:
    /**
    * full constructor for an Item object, which receives both a name and a price
    * @param name  name of the item that was bought
    * @param price price of the item
    */
    Item(const std::string& name, double price);
    /**
     * secondary constructor in case no name is given
     * @param price the item price
     */
    Item(double price);
    /**
     * getter for the name of the item
     * @return the item name
     */
    std::string getName() const;
    /**
     * getter for the price of the item
     * @return the item price
     */
    double getPrice() const ;
};

#endif //UNTITLED1_ITEM_H