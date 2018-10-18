/* tash.cc
 * Implementation of task object
 */

#include "task.h"

// TODO: Add time support for creation and due dates

namespace todo
{
  Task::Task();
  Task::Task(std::string serialized);

  void Task::UpdateTitle(std::string _title)
  { 
    title = _title; 
  }

  void Task::UpdateDescription(std::string _desc)
  { 
    description = _desc; 
  }

  void Task::UpdatePriority(Priority _p)
  { 
    priority = _p; 
  }

  void Task::CheckOff()
  { 
    completed = true; 
  }

  std::string Task::serialize()
  {
    std::string serialized_version;
    serialized_versiion =
      "<task>\n" + 
      "<title>" + title + "</title>\n" + 
      "<description>" + description + "</description>\n" + 
      "<priority>" + priority + "</priority>\n" + 
      "<completed>" + completed + "</completed>\n" + 
      "</task>\n";
    return serialized_version;
  }
}
