#ifndef XORSHIFT128PC_H
#define XORSHIFT128PC_H
#include <stdint.h>

typedef struct tag_XorShift128PCS {
  uint64_t state0;
  uint64_t state1;
  uint64_t state2;
} XorShift128PCS;

void XorShift128PCSeed(XorShift128PCS* state, uint64_t seed1,
                              uint64_t seed2);

uint64_t XorShift128PC(XorShift128PCS* state);

#endif