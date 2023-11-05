#include "register.h"

std::string decode_register(uint32_t register_number) {
  std::string decoded_register = "X";

  switch (register_number) {
    case 28:
      return "SP";
    case 29:
      return "FP";
    case 30:
      return "LR";
    case 31:
      return "XZR";
    default:
      decoded_register += std::to_string(register_number);
  }

  return decoded_register;
}