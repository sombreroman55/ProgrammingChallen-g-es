/* user.h
 * Representation of a user of this program
 */

#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include "project.h"

namespace todo
{
  class User
  {
    public:
      User();
      User(std::string _username, std::string _password);
      User(std::string serialized_user);
      User(const User& copy);             // copy constructor
      User& operator=(const User& copy);  // copy assignment
      ~User();
      void SetDefaultProject(Project pro);
      void AddProject(Project pro);
      std::string serialize();
      std::string serializeProjects();
    private:
      std::string name;
      std::string password;
      std::vector<Project> projects;
      Project defaultProject;
  };
}

#endif // _USER_H_
