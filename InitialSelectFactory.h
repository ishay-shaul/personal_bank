//
// Created by ishay on 22/08/2025.
//

#ifndef _INITIALSELECTFACTORY_H_
#define _INITIALSELECTFACTORY_H_
#include "UserInput.h"

class InitialSelectFactory{
 private:
  UserInput* input;
 public:
  InitialSelectFactory(UserInput* input);
  bool monthOrYear();
  bool getSelection(std::string command);
};

#endif //_INITIALSELECTFACTORY_H_
