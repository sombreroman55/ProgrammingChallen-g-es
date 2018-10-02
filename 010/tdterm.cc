/* tdterm.cc
 * Main entry point for terminal to-do list.
 * This is the CLI for the user to update their list.
 */

#include <stdio.h>
#include <unistd.h>
#include "util.h"

using namespace todo;

int main (int argc, char** argv)
{
  welcome();
  version();
  license();
  credits();
  return 0;
}
