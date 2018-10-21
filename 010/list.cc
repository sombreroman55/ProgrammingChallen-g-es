/* list.cc
 * Implementation of list object
 */

#include "list.h"
#include <sstream>
#include <algorithm>

namespace todo
{
  List::List() { }

  List::List(std::string serialized_list) {}

  List::List(const List& copy)
  {
    // don't implement
  }

  List& List::operator=(const List& copy)
  {
    tasks = copy.tasks;
    return *this;
  }

  List::~List() { }

  void List::AddTask(Task t)
  {
    tasks.push_back(t);
  }

  std::string List::serialize()
  {
    std::ostringstream os;
    os << "<list>\n" <<
      "<title>" << title << "</title>\n" << 
      "<description>" << description << "</description>\n" << 
      "<priority>" << (int)priority << "</priority>\n" << 
      "<completed>" << completed << "</completed>\n" << 
      "<listtasks>\n" << serializeTasks() << "</listtasks>\n" <<
      "</list>\n";
    return os.str();
  }

  std::string List::serializeTasks()
  {
    std::ostringstream os;
    for (unsigned int i = 0; i < tasks.size(); i++)
    {
      os << tasks[i].serialize();
    }
    return os.str();
  }
}
