/* list.h
 * Representation of a list object
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <vector>
#include "task.h"

namespace todo
{
  class List : public Task
  {
    public:
      List();
      ~List();
      void AddTask(Task t);
      void RemoveTask();
      void PrintTasks();
    private:
      std::vector<Task> tasks;  // The tasks associated with this list
  };
}

#endif // _LIST_H_
