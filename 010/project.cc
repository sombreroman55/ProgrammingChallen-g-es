/* project.cc
 * Implementation of project object
 */

#include "project.h"

namespace todo
{
  Project::Project() {}

  Project::~Project() {}

  void Project::AddList(List l)
  {
    task_lists.push_back(l);
  }
}
