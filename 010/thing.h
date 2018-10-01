/* thing.h
 * Abstract interface class from which each level of to-do hierarchy inherits.
 */

#ifndef _THING_H_
#define _THING_H_

#include <string>
#include <chrono>

namespace Todo
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

  // "Thing" to do interface
  class Thing
  {
  public:
    virtual ~Thing();
    virtual void updateTitle(std::string _title)      = 0;
    virtual void updateDescription(std::string _desc) = 0;
    virtual void updateDueDate(auto _date)            = 0;
    virtual void updatePriority(Priority _p)          = 0;
    virtual void checkOff()                           = 0;
  protected:
    std::string title;
    std::string description;
    Priotory priority;
    auto creation_datetime = std::chrono::system_clock::now();
    auto due_datetime;
    bool completed = false;
  }
}

#endif // _THING_H_
