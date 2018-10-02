/* project.h
 * Representation of a project object
 */

#ifndef _PROJECT_H_
#define _PROJECT_H_

#include <vector>
#include "task.h"

namespace todo
{
  class Project : public Task
  {
    public:
      Project();
      ~Project();
    private:
      std::vector<List> task_lists;
  };
}

#endif // _PROJECT_H_
