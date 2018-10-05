/* tdterm.cc
 * Main entry point for terminal to-do list.
 * This is the CLI for the user to update their list.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <unistd.h>
#include "util.h"

using namespace todo;

int routeCommand(std::string comm);
std::vector<std::string> commandParser(std::string line)

int main (int argc, char** argv)
{
  programTitle();
  version();
  license();
  std::cout << std::endl;
  welcome();

  std::string commands;
  bool userQuit = false;
  // Keep prompting user for commands. This loop will break on "quit" command.
  while (!userQuit)
  {
    std::getline(std::cin, commands);
    std::vector<std::string> parsed_commands = commandParser(commands);
    int command_code = routeCommand(parsed_commands);
    switch(command_code)
    {
      case 0:   // quit
        userQuit = true;
        break;
      case 1:   // add
    }
  }
  return 0;
}

int routeCommand(std::vector<std::string> comm)
{
  if (comm == "q" || comm == "quit")
    return PROGRAM_QUIT;
  else if (comm == "a" || comm == "add")
    return 1;
  else if (comm == "r" || comm == "remove")
    return 2;
  return -1;
}

std::vector<std::string> commandParser(std::string line)
{
  std::vector<std::string> command_collection;

}
