#include "types.h"
#include "user.h"

#define EVER (;;)

int main(void)
{
  for(int pri = 4; pri > 0; pri--)
    if(!fork())
    {
      priority(pid(), 10 - pri);

      for EVER
        ;
    }

  wait(); //never returns, as children never exits



}
