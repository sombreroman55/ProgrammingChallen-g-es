/* tash.cc
 * Implementation of task object
 */

#include "task.h"

// TODO: Add time support for creation and due dates

namespace todo
{
  Task::Task();

  void Task::UpdateTitle(std::string _title)              { title = _title; }
  void Task::UpdateDescription(std::string _desc)         { description = _desc; }
  void Task::UpdatePriority(Priority _p)                  { priority = _p; }
  void Task::CheckOff()                                   { completed = true; }
}
