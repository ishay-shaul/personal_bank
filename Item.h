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
    int price;

  public:
    Item(const std::string& name, int price);
    Item(int price);
    std::string getName() const;
    int getPrice() const ;
    void setPrice(int price);
};

#endif //UNTITLED1_ITEM_H