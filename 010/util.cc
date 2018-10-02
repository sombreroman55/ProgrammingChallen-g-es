/* util.c
 * Implementations of the helper functions defined in util.h header
 */

#include <string>
#include <iostream>

namespace todo
{
  void welcome()
  {
    std::cout << "tdterm - A terminal-based To-Do List Application" << std::endl;
    std::cout << "Welcome!" << std::endl;
  }

  void license()
  {
    std::cout << "This software is liscened under" << std::endl;
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
}
