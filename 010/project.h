/* project.h
 * Representation of a project object
 */

#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <vector>
#include "list.h"

namespace todo
{
  class Project : public Task
  {
    public:
      Project();
      Project(std::string serialized_project);
      ~Project();
      void AddList(List l);
      std::string serialize();
    private:
      std::vector<List> task_lists;
      std::string serializeLists();
  };
}

#endif // _PROJECT_H_
