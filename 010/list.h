/* list.h
 * Representation of a list object
 */

#ifndef _LIST_H_
#define _LIST_H_

#include <string>
#include <vector>
#include <chrono>
#include "task.h"

class List
{
public:
  List();
  ~List();
private:
  std::vector<Task> tasks;
};

#endif // _LIST_H_
