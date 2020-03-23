#include "types.h"

#include "random.h"

void
random_init(struct random *state)
{
  //chosen by a fair dice roll
  state->a = 0x12345678;
  state->b = 0x9ABCDEF0;
  state->c = 0xDEADDEAD;
  state->d = 0x5A5A5A5A;
  state->counter = 0;
}

uint
random_uint(struct random *state)
{
  //From wikipedia's page on Xorshift's xorwow implementation
  /* Algorithm "xorwow" from p. 5 of Marsaglia, "Xorshift RNGs" */
  uint t = state->d;

	uint const s = state->a;
	state->d = state->c;
	state->c = state->b;
	state->b = s;

	t ^= t >> 2;
	t ^= t << 1;
	t ^= s ^ (s << 4);
	state->a = t;

	state->counter += 362437;
	return t + state->counter;
}
