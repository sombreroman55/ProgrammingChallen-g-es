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
      ~Project();
      void AddList(List l);
    private:
      std::vector<List> task_lists;
  };
}

#endif // _PROJECT_H_
