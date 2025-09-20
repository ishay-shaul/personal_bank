#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include "UserInput.h"
#include "User.h"
#include "Year.h"
#include <memory>
#include "Logger.h"
#define NUM_ARGS 2

/**
 * checks if the correct command argument was given
 * @param argc the number of arguments the program received
 * @return true if correct, false otherwise
 */
bool checkArguments(int argc)
{
  if (argc != NUM_ARGS)
  {
    std::cout << "number of arguments is invalid" << std::endl;
    return false;
  }
  return true;
}

/**
 * the main method that runs the whole program
 * @param argc the number of arguments
 * @param argv the arguments themselves
 * @return exit success if the program ran, exit failure otherwise
 */
int main(int argc, char *argv[])
{
  if (!checkArguments(argc))
  {
    return EXIT_FAILURE;
  }
  std::string fileName = argv[1];
  std::unique_ptr<User> user = Logger::loadUser(fileName);
  auto userInput = UserInput::getInstance(std::move(user));
  while (true)
  {
    userInput->options();
    if (userInput->isFinished())
    {
      std::cout << "see you next time" << std::endl;
      Logger::saveUser(*user, fileName);
      break;
    }
  }
  return EXIT_SUCCESS;
}