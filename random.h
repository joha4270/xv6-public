#ifndef RANDOM_H

struct random
{
  uint a, b, c, d;
  uint counter;
};

void
random_init(struct random *state);

uint
random_uint(struct random *state);

#endif //RANDOM_H
