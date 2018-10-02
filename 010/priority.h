/* priority.h
 * Defines the priority levels available to program objects
 */

#ifndef _PRIORITY_H_
#define _PRIORITY_H_

namespace todo
{
  // Priority for things to do
  enum class Priority
  {
    NA,
    Lowest,
    Low,
    Normal,
    High,
    Urgent,
    Immediate
  };
}

#endif // _PRIORITY_H_
