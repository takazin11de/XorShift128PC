#include "xorshift128pc.h"

static inline void XorShift128(uint64_t* state0, uint64_t* state1) {
  uint64_t s1 = *state0;
  uint64_t s0 = *state1;
  *state0 = s0;
  s1 ^= s1 << 23;
  s1 ^= s1 >> 17;
  s1 ^= s0;
  s1 ^= s0 >> 26;
  *state1 = s1;
}

static inline uint64_t shuffle_bijection(uint64_t x) {
  uint64_t y = x;
  y += y << 2;
  y += 0xa09e667fb67ae858;
  y ^= y >> 3;
  y += y << 5;
  y += 0xe3779b972a7fa9d2;
  y ^= y >> 7;
  y += y << 11;
  y += 0x887293fdd82b4461;
  y ^= y >> 13;
  y += y << 17;
  y += 0x7e0f66af6f833464;
  y ^= y >> 19;
  y += y << 23;
  y += 0x2eee75778a68a4a8;
  y ^= y >> 29;
  y += y << 31;
  y += 0x4564056854bfb363;
  y ^= y >> 37;
  return y;
}

void XorShift128PCSeed(XorShift128PCS* state, uint64_t seed1, uint64_t seed2) {
  state->state0 = seed1;
  state->state1 = 1;
  state->state2 = seed2;
}

uint64_t XorShift128PC(XorShift128PCS* state) {
  XorShift128(&state->state0, &state->state1);
  return shuffle_bijection(state->state0 + state->state2 + 0x21fb5444bf0a8b14) +
         shuffle_bijection(state->state1 + (state->state2++));
}