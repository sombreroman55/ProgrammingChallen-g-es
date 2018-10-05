/* util.h
 * General purpose utility functions, other miscellaneous helper
 * functions, and constants used throughout the program
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <map>
#include <string>
#include "user.h"

namespace todo
{
  // Program capability contants
  // Functionality code levels
  const int PROGRAM_BASE      = 0x000;
  const int TASK_BASE         = 0x100;
  const int LIST_BASE         = 0x200;
  const int PROJECT_BASE      = 0x300;
  const int MISC_BASE         = 0x400;

  // User commands
  const int PROGRAM_QUIT      = PROGRAM_BASE + 0;
  const int PROGRAM_LOGIN     = PROGRAM_BASE + 1;
  const int PROGRAM_ADD_USER  = PROGRAM_BASE + 2;

  // Task commands
  const int TASK_ADD          = TASK_BASE + 0;
  const int TASK_REMOVE       = TASK_BASE + 1;
  const int TASK_UPDATE       = TASK_BASE + 2;
  const int TASK_CHECK_OFF    = TASK_BASE + 3;

  // List commands

  // Project commands

  // Miscellaneous commands

  // Opening messages
  void programTitle(void);
  void license(void);
  void version(void);
  void credits(void);
  void welcome(void);

  // Program data
  std::map<std::string, user>
}

#endif // _UTIL_H_
