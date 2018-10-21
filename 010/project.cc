/* project.cc
 * Implementation of project object
 */

#include "project.h"
#include <sstream>

namespace todo
{
  Project::Project() {}
      
  Project::Project(std::string serialized_project) {}

  Project::Project(const Project& copy)
  {
    // don't implement
  }

  Project& Project::operator=(const Project& copy)
  {
    task_lists = copy.task_lists;
    return *this;
  }

  Project::~Project() {}

  void Project::AddList(List l)
  {
    task_lists.push_back(l);
  }

  std::string Project::serialize()
  {
    std::ostringstream os;
    os << "<project>\n" <<
      "<title>" << title << "</title>\n" << 
      "<description>" << description << "</description>\n" << 
      "<priority>" << (int)priority << "</priority>\n" << 
      "<completed>" << completed << "</completed>\n" << 
      "<projectlists>\n" << serializeLists() << "</projectlists>\n" <<
      "</project>\n";
    return os.str();
  }

  std::string Project::serializeLists()
  {
    std::ostringstream os;
    for (unsigned int i = 0; i < task_lists.size(); i++)
    {
      os << task_lists[i].serialize();
    }
    return os.str();
  }
}
