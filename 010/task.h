/* task.h
 * Class definition and function prototypes for a task object
 */
#ifndef _TASK_H_
#define _TASK_H_

#include <string>
#include <chrono>
#include "priority.h"

namespace todo
{
  class Task
  {
    public:
      Task(std::string _title);                     // base constructor
      Task(std::string _title, std::string _desc);
      Task(const Task& copy);                       // copy constructor
      Task& operator=(const Task& copy);            // copy assignment
        ~Task();                                    // destructor
      void UpdateTitle(std::string _title);
      void UpdateDescription(std::string _desc);
      void UpdateDueDate(std::chrono::time_point _date);
      void UpdatePriority(Priority _p);
      void CheckOff();
    protected:
      std::string title;
      std::string description;
      Priority priority;
      std::time_t creation_datetime =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
      std::time_t due_datetime;
      bool completed = false;
  };
}

#endif // _TASK_H_ 
