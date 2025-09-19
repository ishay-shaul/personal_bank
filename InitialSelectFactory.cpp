//
// Created by ishay on 22/08/2025.
//
#define EXIT "exit"
#define ADD "add"
#define SUM "get sum"
#define DECIDE "month or year? (please enter month or year)"
#define MONTH "month"
#define YEAR "year"
#define ERROR "month or year not selected. Please pick again"
#include "InitialSelectFactory.h"
#include <iostream>


InitialSelectFactory::InitialSelectFactory (UserInput *input)
{
  this->input = input;
}

bool InitialSelectFactory::monthOrYear ()
{
  std::string selection;
  std::cout << DECIDE << std::endl;
  std::getline(std::cin, selection);   // <-- instead of std::cin >>
  // return input;
  if(selection == MONTH){
    input->getMonthSum();
    return true;
  }
  if(selection == YEAR){
    input->getYearSum();
    return true;
  }
  std::cout << ERROR;
  return false;
}

bool InitialSelectFactory::getSelection (std::string command)
{
  if(command == ADD){
      input->add();
      return true;
  }
  else if(command == SUM){
    return monthOrYear();
  }
  else if(command == EXIT){
    input->exit();
    return true;
  }
  else{
    return false;
  }
}