#pragma once
#include <string>

struct MainClass {
  int value = 0;
  bool is_odd = false;
  void recompute_flag();
  std::string stringify() const;

 private:
  bool value_is_odd() const;
};
