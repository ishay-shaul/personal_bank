#ifndef _USERPERSISTENCE_H_
#define _USERPERSISTENCE_H_
#include "Logger.h"
#include <fstream>
#include <sstream>

void Logger::saveUser(User &user, const std::string &fileName)
{
    std::ofstream out(fileName);
    if (!out)
    {
        throw std::runtime_error("Cannot open file " + fileName);
    }
    for (const auto& pair: user.getAllYears())
    {
        int year = pair.first;
        auto& years = pair.second;
        for (const auto& curYear: years->getAllMonths())
        {
            int month = curYear.first;
            auto& curMonth = curYear.second;
            for (const auto& item: curMonth->getAllItems())
            {
                out<< year << ", "
                << month << ", "
                << item.first << ", "
                << item.second->getPrice()
                << "\n";
            }
        }
    }
}

std::unique_ptr<User> Logger::loadUser(const std::string &fileName)
{
    std::ifstream in(fileName);
    if (!in)
    {
        throw std::runtime_error("Cannot open file " + fileName);
    }
    auto user = std::make_unique<User>(10000);
    std::string line;

    while (std::getline(in, line))
    {
        std::stringstream iss(line);
        std::string yearStr, monthStr, itemName, priceStr;

        if (!std::getline(iss, yearStr, ',')) continue;
        if (!std::getline(iss, monthStr, ',')) continue;
        if (!std::getline(iss, itemName, ',')) continue;
        if (!std::getline(iss, priceStr, ',')) continue;

        int year = std::stoi(yearStr);
        int month = std::stoi(monthStr);
        double price = std::stod(priceStr);

        auto newItem = std::make_unique<Item>(itemName, price);
        user->addItem(std::move(newItem), year, month);
    }
    return user;
}


#endif //_USERPERSISTENCE_H_