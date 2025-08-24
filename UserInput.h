//
// Created by ishay on 22/08/2025.
//

#ifndef _USERINPUT_H_
#define _USERINPUT_H_
#include <string>
#include "User.h"

class UserInput{
 private:
  std::string file;
  std::unique_ptr<User> user;
  bool finish = false;


 public:
  UserInput(std::unique_ptr<User> user);
  void getFile();
  void options();
  void exit();
  void add();
  size_t getYearSum();
  size_t getMonthSum();
  std::string firstInput();
  double acceptPrice();
  int acceptMonth();
  int acceptYear();
  bool checkPriceInput(std::string& str);
  bool checkMonthInput(std::string& str);
  bool checkYearInput(std::string& str);
  bool isFinished() const;

};

#endif //_USERINPUT_H_
