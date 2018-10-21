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
      List(std::string serialized_list);
      List(const List& copy);             // copy constructor
      List& operator=(const List& copy);  // copy assignment
      ~List();
      void AddTask(Task t);
      void RemoveTask();
      void PrintTasks();
      std::string serialize();
    private:
      std::vector<Task> tasks;  // The tasks associated with this list
      std::string serializeTasks();
  };
}

#endif // _LIST_H_
