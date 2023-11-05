#include "immediate.h"

std::string decode_immediate(int32_t immediate) {
  std::string decoded_immediate = "#";

  decoded_immediate += std::to_string(immediate);

  return decoded_immediate;
}