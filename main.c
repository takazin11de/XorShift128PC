
#include <stdio.h>

#include "xorshift128pc.h"

int main() {
  XorShift128PCS state;

  XorShift128PCSeed(&state, 0, 0);

  for (int i = 0; i < 1000; i++) {
    printf("%llu\n", XorShift128PC(&state));
  }

  return 0;
}
