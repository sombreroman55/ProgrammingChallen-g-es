/* user.cc
 * Implementation of a user object
 */

#include "user.h"
#include <sstream>

namespace todo
{
  User::User()
  {
  }

  User::User(std::string serialized_user)
  {
  }

  User::~User()
  {
  }

  void User::SetDefaultProject(Project pro)
  {
    defaultProject = pro;
  }

  void User::AddProject(Project pro)
  {
    projects.push_back(pro);
  }

  std::string User::serialize()
  {
    std::ostringstream os;
    os << "<user>\n" <<
      "<name>" << name << "</name>\n" << 
      "<password>" << password << "</password>\n" << 
      "<defaultproject>" << defaultProject.serialize() << "</defaultproject>\n" << 
      "<userprojects\n" << serializeProjects() << "</userprojects>\n" <<
      "</user>\n";
    return os.str();
  }

  std::string User::serializeProjects()
  {
    std::ostringstream os;
    for (unsigned int i = 0; i < projects.size(); i++)
    {
      os << projects[i].serialize();
    }
    return os.str();
  }
}
