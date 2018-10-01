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
  Task();
  ~Task();
private:
  std::string task;         // The actual task itself
  std::string description;  // An optional, longer, detailed description
  Priority pri; 
  bool complete = false;
  auto creation_datetime = std::chrono::system_clock::now();
  auto due_datetime;
};

#endif // _TASK_H_ 
