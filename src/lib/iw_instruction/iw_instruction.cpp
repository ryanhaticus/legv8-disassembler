#include "iw_instruction.h"

std::string decode_iw_instruction(instruction_t instruction, uint32_t bits) {
  iw_instruction_t *iw_instruction =
      reinterpret_cast<iw_instruction_t *>(&bits);

  std::string decoded_instruction =
      instruction.mnemonic + " " + decode_register(iw_instruction->Rd) + ", " +
      decode_immediate(iw_instruction->MOV_immediate);

  return decoded_instruction;
}