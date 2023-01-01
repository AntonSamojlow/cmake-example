#include "libclass.h"

#include <spdlog/spdlog.h>

int LibClass::id() const {
  return count * (-1 + 2 * int(active));
}

void LibClass::log() const {
  spdlog::default_logger()->info("LibClass::log (count={}, active={})", count, active);
}
