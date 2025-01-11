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
  y *= 0xa09e667fb67ae859;
  y += 0xe3779b972a7fa9d2;
  y ^= (y >> 5) ^ (y >> 11);
  y *= 0x887293fdd82b4461;
  y += 0x7e0f66af6f833464;
  y ^= (y >> 17) ^ (y >> 23);
  y *= 0x2eee75778a68a4a9;
  y += 0x4564056854bfb363;
  y ^= (y >> 29) ^ (y >> 37);
  return y;
}

void XorShift128PCSeed(XorShift128PCS* state, uint64_t seed1, uint64_t seed2) {
  state->state0 = seed1;
  state->state1 = 0x21fb5444bf0a8b14;
  state->state2 = seed2;
}

uint64_t XorShift128PC(XorShift128PCS* state) {
  XorShift128(&state->state0, &state->state1);
  return shuffle_bijection(state->state0 + 0x5555555555555555) +
         shuffle_bijection(state->state1 + 0xaaaaaaaaaaaaaaaa) +
         shuffle_bijection(state->state2++);
}