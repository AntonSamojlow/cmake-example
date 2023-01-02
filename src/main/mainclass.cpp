#include "mainclass.h"

#include <string>

void MainClass::recompute_flag() {
  is_odd = value_is_odd();
}

std::string MainClass::stringify() const {
  return "value=" + std::to_string(value) + ", is_odd=" + (is_odd ? "true" : "false");
}

bool MainClass::value_is_odd() const {
  return value % 2 == 1;
}
