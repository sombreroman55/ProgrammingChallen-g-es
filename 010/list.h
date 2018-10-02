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
      List(std::string _title);
      List(std::string _title, std::string _desc);
      ~List();
      void addTask(Task t);
      void removeTask();
    private:
      std::vector<Task> tasks;  // The tasks associated with this list
      std::string title;        // A short title describing the list
      std::string description;  // An optional, detailed description of the list
      auto creation_datetime = std::chrono::system_clock::now();
      auto due_datetime;
      bool completed = false;
      Priority priority;
  };
}

#endif // _LIST_H_
