#include <spdlog/spdlog.h>

#include <iostream>
#include <optional>

#include "main/mainclass.h"
#include "mylibrary/libclass.h"

int use_after_free(int index);

int main() {
  // int i;
  int some_number = 1;

  auto logger = spdlog::default_logger();
  MainClass classA = {.value = 1};

  logger->info("stored in cache a copy of classA: {}", classA.stringify());
  classA.recompute_flag();
  logger->info("recomputed local classA: {}", classA.stringify());

  LibClass libclass;
  libclass.log();
  logger->info("libclass default values: count={}, active={}", libclass.count, libclass.active);

  some_number = use_after_free(1);

  return some_number;
}

// NOLINTBEGIN
int use_after_free(int index) {
  int *array = new int[100];
  delete[] array;
  return array[index];  // ASAN should find this
}
// NOLINTEND
