/* tdterm.cc
 * Main entry point for terminal to-do list.
 * This is the CLI for the user to update their list.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unistd.h>
#include "util.h"

using namespace todo;

int routeCommand (std::vector<std::string> comm);
std::vector<std::string> commandParser (std::string line);
void displayHelp (bool usage_error = false);
void displayLogin (void);
void displayRegister (void);
void displayAdd (void);
static Screen currentScreen;

int main (int argc, char** argv)
{
  programTitle();
  version();
  license();
  credits();
  std::cout << std::endl;
  welcome();

  // Help prompts change depending on the screen.
  currentScreen = Screen::Welcome; 
  std::string commands;
  bool userQuit = false;

  // Keep prompting user for commands. This loop will break on "quit" command.
  // This is the main control loop of the program. It takes in commands and
  // prompts the user with the proper information when given a legal command.
  while (!userQuit)
  {
    std::cout << "td> ";
    std::getline(std::cin, commands);
    std::vector<std::string> parsed_commands = commandParser(commands);
    int command_code = routeCommand(parsed_commands);
    switch(command_code)
    {
      case PROGRAM_QUIT:
        userQuit = true;
        break;
      case PROGRAM_HELP:
        displayHelp();
        break;
      case PROGRAM_ERROR:
        displayHelp(true);
        break;
      case PROGRAM_LOGIN:
        displayLogin();
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
        displayHelp(true);
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
  if (commands[0] == "h" || commands[0] == "help")
    return PROGRAM_HELP;
  if (commands[0] == "q" || commands[0] == "quit")
    return PROGRAM_QUIT;
  if (currentScreen == Screen::Welcome)
  {
    if (commands[0] == "log" || commands[0] == "login")
      return PROGRAM_LOGIN;
    if (commands[0] == "reg" || commands[0] == "register")
      return PROGRAM_REGISTER;
  }
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
  return PROGRAM_ERROR;
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
void displayHelp(bool usage_error)
{
  if (usage_error)
  {
    std::string error_string = 
      "\nError: unrecognized command(s). See available commands and usage below.";
    prettyPrint(error_string);
  }
  std::cout << "\nProgram Help" << std::endl;
  std::cout << "----------------------------------------------------" << std::endl;
  std::string help_string = "\n";
  switch (currentScreen)
  {
    case Screen::Welcome:
      std::cout << "CURRENT SCREEN: Welcome" << std::endl;
      help_string += 
        "Available commands:\n"
        "\tlogin (log)    -- Log in to the program.\n"
        "\tregister (reg) -- Create a new user account.\n";
      std::cout << help_string << std::endl;
      break;
    case Screen::Home:
      std::cout << "Current Screen: Home" << std::endl;
      help_string += 
        "Available commands:\n"
        "\tadd (a) [identifier]       -- Create a new entry at the identified level.\n"
        "\tremove (r) [identifier]    -- Remove an entry at the identified level.\n"
        "\tupdate (u) [identifier]    -- Update an entry at the identified level.\n"
        "\tcheckoff (co) [identifier] -- Check off an entry at the identified level.\n"
        "Identifiers:\n"
        "\ttask (t)    -- Lowest level Task.\n"
        "\tlist (l)    -- A List of Tasks.\n"
        "\tproject (p) -- A collection of Lists of Tasks.\n";
      std::cout << help_string << std::endl;
      break;
    default:
      // If we reach this point something really went wrong!
      std::cout << "You shouldn't be here!" << std::endl;
      break;
  }
}

void displayLogin (void)
{
  // TODO: Track username/password pairs
  int tries = 3;
  std::string username;
  std::string password;
  std::cout << "td::login> Welcome back! Please enter the following informaton:" << std::endl;
  std::cout << "td::login> Username: ";
  std::cin >> username;
  while (tries--)
  {
    std::cout << "td::login> Password: ";
    std::cin >> password;
    // TODO: Try log in using username/password pair
  }
  std::cout << "td::login> Permission denied. Please try again." << std::endl;
}

void displayRegister (void)
{
  // TODO: Store secure versions of password, not plain text
  // TODO: Track username/password pairs
  std::string username;
  std::string password;
  std::cout << "td::register> Welcome new user! Please enter the following informaton:" << std::endl;
  std::cout << "td::register> Username: ";
  std::cin >> username;
  std::cout << "td::register> Password: ";
  std::cin >> password;
  std::string new_user_string = 
    "Welcome " + username + " to tdterm! Please take a look at the help prompts "
    "for help on how to use this program. Also take a look at the documentation "
    "available at: https://github.com/sombreroman55/ProgrammingChallen-g-es/010 "
    "or enter \"manual\" or \"man\" for short for a more in depth look at how to "
    "use this program. We hope you enjoy using tdterm!";
  // TODO: Make manual page of documentation with controls like that of man
  prettyPrint(new_user_string);
}

void displayAdd (void)
{
}
