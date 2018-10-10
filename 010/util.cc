/* util.c
 * Implementations of the helper functions defined in util.h header
 */

#include <string>
#include <iostream>
#include "util.h"

namespace todo
{
  void programTitle()
  {
    std::cout << "tdterm - A terminal-based To-Do List Application" << std::endl;
  }

  void license()
  {
    std::string license_string = 
          "This software is liscened under GNU GPL3 and comes with "
          "ABSOLUTELY NO WARRANTY!";
    prettyPrint(license_string);
  }

  void version()
  {
    std::cout << "Version 0.0.1" << std::endl;
  }

  void credits()
  {
    std::cout << "Written and maintained by Andrew Roberts" << std::endl;
    std::cout << "Email: sombreroman55@gmail.com" << std::endl;
  }

  void welcome()
  {
    std::string welcome_string = 
          "Welcome! If at any time you need help, enter the command "
          "\"help\", or \"h\" for short to see the available commands.";
    prettyPrint(welcome_string);
  }

  void prettyPrint(std::string to_print)
  {
    if (to_print.length() < 81)
    {
      std::cout << to_print << std::endl;
      return;
    }
    unsigned int i = 0;
    unsigned int last_i = i;
    while (i < to_print.length())
    {
      if (to_print.length() - i < 81)
      {
        std::cout << to_print.substr(i+1) << std::endl;
        return;
      }
      i += 81;
      while (to_print[--i] != ' ') ; 
      std::cout << to_print.substr(last_i, i) << std::endl;
      last_i = i+1;
    }
  }
}
