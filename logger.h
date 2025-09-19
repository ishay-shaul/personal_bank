
#ifndef UNTITLED1_LOGGER_H
#define UNTITLED1_LOGGER_H
#include <string>

#include "User.h"

class Logger
{
  public:
    static void saveUser(User& user, const std::string& fileName);

    static std::unique_ptr<User> loadUser(const std::string& fileName);
};


#endif //UNTITLED1_LOGGER_H