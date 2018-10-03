/* list.cc
 * Implementation of list object
 */

#include "list.h"

namespace todo
{
    List::List() { }

    List::~List() { }

    void List::AddTask(Task t)
    {
        tasks.push_back(t);
    }
}
