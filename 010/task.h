/* task.h
 * Class definition and function prototypes for a task object
 */
#ifndef _TASK_H_
#define _TASK_H_

#include <string>
#include <ctime>
#include "priority.h"

// TODO: Add time support for creation and due dates

namespace todo
{
  class Task
  {
    public:
      Task(std::string _title);                     // base constructor
      Task(std::string _title, std::string _desc);
      Task(std::string serialized);
      Task(const Task& copy);                       // copy constructor
      Task& operator=(const Task& copy);            // copy assignment
        ~Task();                                    // destructor
      void UpdateTitle(std::string _title);
      void UpdateDescription(std::string _desc);
      void UpdatePriority(Priority _p);
      void CheckOff();
      std::string serialize();
    protected:
      std::string title;
      std::string description;
      Priority priority;
      bool completed = false;
  };
}

#endif // _TASK_H_ 
