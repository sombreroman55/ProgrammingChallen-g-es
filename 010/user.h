/* user.h
 * Representation of a user of this program
 */

#ifndef _USER_H_
#define _USER_H_

#include <string>
#include <vector>
#include "project.h"

class User
{
public:
  User();
  ~User();
  void setDefaultProject(Project pro);
  void addProject(Project pro);
private:
  std::string name;
  std::string password;
  std::vector<Project> projects;
  Project defaultProject;
};

#endif // _USER_H_
