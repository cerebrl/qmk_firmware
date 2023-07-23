#include "quantum.h"
#include <stdio.h>

#define L_INSERT 0
#define L_NORMAL 1
#define L_SHFT_NORMAL 2
#define L_VISUAL 3
#define L_MOVE_TOP  4
#define L_FUNCTION 5
#define L_QUICK_MOVE 6
#define L_PAGE_SCROLL 7

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (get_highest_layer(layer_state)) {
    case L_INSERT:
      snprintf(layer_state_str, sizeof(layer_state_str), "INSERT");
      break;
    case L_NORMAL:
      snprintf(layer_state_str, sizeof(layer_state_str), "NORMAL");
      break;
    case L_SHFT_NORMAL:
      snprintf(layer_state_str, sizeof(layer_state_str), "SFT NORMAL");
      break;
    case L_VISUAL:
      snprintf(layer_state_str, sizeof(layer_state_str), "VISUAL");
      break;
    case L_MOVE_TOP:
      snprintf(layer_state_str, sizeof(layer_state_str), "MOVE TOP");
      break;
    case L_FUNCTION:
      snprintf(layer_state_str, sizeof(layer_state_str), "FUNCTION");
      break;
    case L_QUICK_MOVE:
      snprintf(layer_state_str, sizeof(layer_state_str), "QUICK MOVE");
      break;
    case L_PAGE_SCROLL:
      snprintf(layer_state_str, sizeof(layer_state_str), "PAGE SCROLL");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "%u", get_highest_layer(layer_state));
  }

  return layer_state_str;
}
