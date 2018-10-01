/* task.h
 * Class definition and function prototypes for a task object
 */
#ifndef _TASK_H_
#define _TASK_H_

#include <string>
#include <chrono>
#include "priority.h"

namespace Todo
{
  class Task : public Thing
  {
    public:
      Task(std::string _title) : title(_title);           // base constructor
      Task(std::string _title, std::string _desc) 
        : title(_title), description(_desc);
      Task(const Task& copy);                             // copy constructor
      Task& operator=(const Task& copy)                   // copy assignment
        ~Task();                                          // destructor
      void updateTitle(std::string _title);
      void updateDescription(std::string _desc);
      void updateDueDate(auto _date);
      void updatePriority(Priority _p);
      void checkOff();
  };
}

#endif // _TASK_H_ 
