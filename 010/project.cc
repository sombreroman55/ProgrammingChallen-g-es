/* project.cc
 * Implementation of project object
 */

namespace todo
{
  Project::Project() {}

  Project::~Project() {}

  Project::AddList(List l)
  {
    task_lists.push_back(l);
  }
}
