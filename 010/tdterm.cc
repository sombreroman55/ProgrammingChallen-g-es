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

int routeCommand(std::vector<std::string> comm);
std::vector<std::string> commandParser(std::string line);
void displayHelp(Screen scr);

int main (int argc, char** argv)
{
  programTitle();
  version();
  license();
  std::cout << std::endl;
  welcome();

  // Help prompts change depending on the screen.
  Screen currentScreen = Screen::Welcome; 
  std::string commands;
  bool userQuit = false;

  // Keep prompting user for commands. This loop will break on "quit" command.
  // This is the main control loop of the program. It takes in commands and
  // prompts the user with the proper information when given a legal command.
  while (!userQuit)
  {
    std::getline(std::cin, commands);
    std::vector<std::string> parsed_commands = commandParser(commands);
    int command_code = routeCommand(parsed_commands);
    switch(command_code)
    {
      case PROGRAM_QUIT:   // quit
        userQuit = true;
        break;
      case PROGRAM_HELP:
        displayHelp(currentScreen);
        break;
      case PROGRAM_LOGIN:
        break;
      case PROGRAM_REGISTER:
        break;
      case TASK_ADD:
        break;
      case TASK_REMOVE:
        break;
      case TASK_UPDATE:
        break;
      case TASK_CHECK_OFF:
        break;
      case LIST_ADD:
        break;
      case LIST_REMOVE:
        break;
      case LIST_UPDATE:
        break;
      case LIST_CHECK_OFF:
        break;
      case PROJECT_ADD:
        break;
      case PROJECT_REMOVE:
        break;
      case PROJECT_UPDATE:
        break;
      case PROJECT_CHECK_OFF:
        break;
      default:
        std::cout << "Error! Unrecognized or malformed command!" << std::endl;
        displayHelp(currentScreen);
        break;
    }
  }
  // TODO: Save user data before quitting/exiting
  return 0;
}

// Route the text command to the proper command code
// NOTE: This function is admittedly very ugly and should
// be cleaned up someday.
int routeCommand(std::vector<std::string> commands)
{
  //// First level commands ////
  if (commands[0] == "q" || commands[0] == "quit")
    return PROGRAM_QUIT;
  if (commands[0] == "a" || commands[0] == "add")
  {
    if (commands[1] == "t" || commands[1] == "task")
      return TASK_ADD;
    if (commands[1] == "l" || commands[1] == "list")
      return LIST_ADD;
    if (commands[1] == "p" || commands[1] == "project")
      return PROJECT_ADD;
  }
  if (commands[0] == "r" || commands[0] == "remove")
  {
    if (commands[1] == "t" || commands[1] == "task")
      return TASK_REMOVE;
    if (commands[1] == "l" || commands[1] == "list")
      return LIST_REMOVE;
    if (commands[1] == "p" || commands[1] == "project")
      return PROJECT_REMOVE;
  }
  if (commands[0] == "u" || commands[0] == "update")
  {
    if (commands[1] == "t" || commands[1] == "task")
      return TASK_UPDATE;
    if (commands[1] == "l" || commands[1] == "list")
      return LIST_UPDATE;
    if (commands[1] == "p" || commands[1] == "project")
      return PROJECT_UPDATE;
  }
  if (commands[0] == "co" || commands[0] == "checkoff")
  {
    if (commands[1] == "t" || commands[1] == "task")
      return TASK_CHECK_OFF;
    if (commands[1] == "l" || commands[1] == "list")
      return LIST_CHECK_OFF;
    if (commands[1] == "p" || commands[1] == "project")
      return PROJECT_CHECK_OFF;
  }
  return PROGRAM_HELP;
}

// Split out the spaces between commands and identifiers
// Inefficient string parsing function but good enough for
// our purposes.
std::vector<std::string> commandParser(std::string line)
{
  std::vector<std::string> command_collection;
  std::string comm = "";
  for (unsigned int i = 0; i < line.length(); i++)
  {
    if (line[i] == ' ')
    {
      command_collection.push_back(comm);
      comm.clear();
    }
    else
    {
      comm += line[i];
    }
  }
  command_collection.push_back(comm);
  return command_collection;
}

// Print help prompt for current screen
void displayHelp(Screen scr)
{
  switch (scr)
  {
    case Screen::Welcome:
      break;
    case Screen::Login:
      break;
    case Screen::Register:
      break;
    case Screen::Add:
      break;
    case Screen::Remove:
      break;
    case Screen::Update:
      break;
    default:
      // If we reach this point something really went wrong!
      std::cout << "You shouldn't be here!" << std::endl;
      break;
  }
}
