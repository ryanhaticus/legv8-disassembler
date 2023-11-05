#include "d_instruction.h"

std::string decode_d_instruction(instruction_t instruction, uint32_t bits) {
  d_instruction_t *d_instruction = reinterpret_cast<d_instruction_t *>(&bits);

  std::string decoded_instruction = instruction.mnemonic + " ";

  decoded_instruction += decode_register(d_instruction->Rt) + ", [" +
                         decode_register(d_instruction->Rn) + ", " +
                         decode_immediate(d_instruction->DT_address) + "]";

  return decoded_instruction;
}