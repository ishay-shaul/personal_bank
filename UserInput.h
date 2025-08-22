//
// Created by ishay on 22/08/2025.
//

#ifndef _USERINPUT_H_
#define _USERINPUT_H_
#include <string>

class UserInput{
 private:
  std::string file;


 public:
  void getFile();
  void options();
  void exit();
  void add();
  size_t getYearSum();
  size_t getMonthSum();
  std::string firstInput();

};

#endif //_USERINPUT_H_
