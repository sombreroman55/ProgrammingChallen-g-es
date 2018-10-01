/* task.h
 * Class definition and function prototypes for a task object
 */
#ifndef _TASK_H_
#define _TASK_H_

#include <string>
#include <chrono>
#include "priority.h"

class Task
{
public:
  Task();                           // base constructor
  Task(const Task& copy);           // copy constructor
  Task& operator=(const Task& copy) // copy assignment
  ~Task();                          // destructor
  void updateTitle(std::string new_title);
  void updateDescription(std::string new_description);
  void updateDueDate(auto date);
  void checkOff();
  
private:
  std::string title;        // A short descriptive title for the task
  std::string description;  // An optional, more detailed description
  Priority priority; 
  bool complete = false;
  auto creation_datetime = std::chrono::system_clock::now();
  auto due_datetime;
};

#endif // _TASK_H_ 
