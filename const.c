#include <math.h>
#include <stdint.h>
#include <stdio.h>

typedef union {
  struct {
    uint64_t : 16;
    uint64_t data : 32;
    uint64_t : 16;
  };
  double value;
} A;

int main() {
  A a;
  printf("0x%x", (a.value = sqrt(2), a.data));
  printf("%x\n", (a.value = sqrt(3), a.data));
  printf("0x%x", (a.value = sqrt(5), a.data));
  printf("%x\n", (a.value = sqrt(7), a.data));
  printf("0x%x", (a.value = sqrt(11), a.data));
  printf("%x\n", (a.value = sqrt(13), a.data));
  printf("0x%x", (a.value = sqrt(17), a.data));
  printf("%x\n", (a.value = sqrt(19), a.data));
  printf("0x%x", (a.value = sqrt(23), a.data));
  printf("%x\n", (a.value = sqrt(29), a.data));
  printf("0x%x", (a.value = sqrt(31), a.data));
  printf("%x\n", (a.value = sqrt(37), a.data));
  printf("0x%x", (a.value = M_PI, a.data));
  printf("%x\n", (a.value = M_E, a.data));
  return 0;
}
