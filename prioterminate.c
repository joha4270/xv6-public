#include "types.h"
#include "user.h"

int main(void)
{
  //Spawn 4 processes with decreasing priority.
  //Since there are only 2 CPU's only 2 should get to run
  for(int pri = 4; pri > 0; pri--)
    if(!fork())
    {
      priority(pid(), 10 - pri);

      for(;;)
      { }
    }

  wait(); //never returns, as children never exits
}
