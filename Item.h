//
// Created by ishay on 21/08/2025.
//

#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H
#include <string>

class Item
{
  private:
    std::string name;
    double price;

  public:
    Item(const std::string& name, double price);
    Item(double price);
    std::string getName() const;
    double getPrice() const ;
    // void setPrice(int price);
};

#endif //UNTITLED1_ITEM_H