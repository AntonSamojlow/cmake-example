#include "mainclass.h"

#include <string>

void MainClass::recompute_flag() {
  is_odd = value_is_odd();
}

std::string MainClass::stringify() {
  return "value=" + std::to_string(value) + ", is_odd=" + std::to_string(is_odd);
}

bool MainClass::value_is_odd() {
  return value % 2 == 1;
}
