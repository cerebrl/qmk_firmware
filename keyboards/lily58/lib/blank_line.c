#include "quantum.h"
#include <stdio.h>

char empty_str[24];

const char *read_blank_line(void) {
  snprintf(empty_str, sizeof(empty_str), " ");
  return empty_str;
}