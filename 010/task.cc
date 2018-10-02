/* tash.cc
 * Implementation of task object
 */

#include "task.h"

namespace todo
{
  Task::Task();

  void Task::UpdateTitle(std::string _title)      { title = _title; }
  void Task::UpdateDescription(std::string _desc) { description = _desc; }
  void Task::UpdateDueDate(auto _date)            { due_datetime = _date; }
  void Task::UpdatePriority(Priority _p)          { priority = _p; }
  void Task::CheckOff()                           { completed = true; }
}
