/* tash.cc
 * Implementation of task object
 */

#include "task.h"
#include <sstream>

// TODO: Add time support for creation and due dates

namespace todo
{
  Task::Task() { }
  Task::Task(std::string serialized)
  {
  }

  Task::Task(const Task& copy)
  {
  }

  Task& Task::operator=(const Task& copy)
  {
    return *this;
  }

  Task::~Task()
  {
  }

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
    std::ostringstream os;
    os << "<task>\n" <<
      "<title>" << title << "</title>\n" << 
      "<description>" << description << "</description>\n" << 
      "<priority>" << (int)priority << "</priority>\n" << 
      "<completed>" << completed << "</completed>\n" << 
      "</task>\n";
    return os.str();
  }
}
