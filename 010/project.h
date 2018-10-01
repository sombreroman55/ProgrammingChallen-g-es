/* project.h
 * Representation of a project object
 */

#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <string>
#include <vector>
#include <chrono>
#include "list.h"

class Project
{
public:
  Project();
  ~Project();
private:
  std::vector<List> task_lists;
};

#endif // _PROJECT_H_
