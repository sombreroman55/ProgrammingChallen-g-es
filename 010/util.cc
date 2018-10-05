/* util.c
 * Implementations of the helper functions defined in util.h header
 */

#include <string>
#include <iostream>

namespace todo
{
  void programTitle()
  {
    std::cout << "tdterm - A terminal-based To-Do List Application" << std::endl;
  }

  void license()
  {
    std::cout << "This software is liscened under GNU GPL3." << std::endl;
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
    std::cout << "Welcome! If at any time you need help, enter" << std::endl;
    std::cout << "the command \"help\", or \"h\" for short to" << std::endl;
    std::cout << "see the available commands." << std::endl;
  }
}
