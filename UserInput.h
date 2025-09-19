//
// Created by ishay on 22/08/2025.
//

#ifndef _USERINPUT_H_
#define _USERINPUT_H_
#include <string>
#include "User.h"
// turn class into a singleton
/**
 * class which takes charge of validating and performing the user commands
 */
class UserInput{
 private:
  /** the file where the user map will be saved*/
  std::string file;
  /** a pointer to the user*/
  std::unique_ptr<User> user;
  /** when true, the program ends. is set in the exit method*/
  bool finish = false;
  /** instance of the UserInput*/
  static UserInput* instance;
  /**
   * constructs a UserInput object.
   * @param user a pointer to the user
   */
  explicit UserInput(std::unique_ptr<User> user);
  /**
   * method that requests a price from the user in order to create an item.
   * @return the valid price of the item
   */
  double acceptPrice();
  /**
   * requests and validates the month input from the user. will run until a
   * valid month was entered
   * @return a valid month
   */
  int acceptMonth();
  /**
   * requests and validates the year input from the user. will run until a
   * valid year was given
   * @return the valid year
   */
  int acceptYear();
  /**
   * checks if the price input was valid. Used in acceptPrice method
   * @param str the user input
   * @return true if the input was a valid price, false otherwise
   */
  bool checkPriceInput(std::string& str);
  /**
   * checks if the month input was valid. Used in the acceptMonth method
   * @param str the user input
   * @return true if the input is valid, false otherwise
   */
  bool checkMonthInput(std::string& str);
  /**
   * validates the year that was given by the user. Used in acceptYear
   * @param str the user input
   * @return true if valid, false otherwise
   */
  bool checkYearInput(std::string& str);
  /**
   * in the beggining of the options method, the user will pick between some
   * options they can run. This method gives us what the user wants( to add an
   * item, exit, etc.).
   * @return the command of the user
   */
  static std::string firstInput();

 public:
  /**
   * If the userInput already exists, then nothing happens, else a
   * new instance is created and returned
   * @return UserInput
   */
  static UserInput* getInstance(std::unique_ptr<User> user);
  /**

   */
  static void getFile();
  /**
   * the father method. Meaning, the whole class is implemented here.
   * The user will be asked what he/she wants to do and will perform it
   */
  void options();
  /**
   * method which ends the program
   */
  void exit();
  /**
   * method that will add an item to the user
   */
  void add();
  /**
   * method that will return the total the user spent in a
   * certain year of the user's choosing
   * @return the total
   */
  double getYearSum();
  /**
   * method that will return the total the user spent in a
   * certain month of the user's choosing
   * @return the total
   */
  double getMonthSum();
  /**
   * checks if the user decided to terminate the program
   * @return
   */
  bool isFinished() const;
  /**
   * getter for the user
   * @return a pointer to the user
   */
  User* getUser() const;
};

#endif //_USERINPUT_H_
