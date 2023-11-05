#include "i_instruction.h"

std::string decode_i_instruction(instruction_t instruction, uint32_t bits) {
  i_instruction_t *i_instruction = reinterpret_cast<i_instruction_t *>(&bits);

  std::string decoded_instruction = instruction.mnemonic + " " +
                                    decode_register(i_instruction->Rd) + ", " +
                                    decode_register(i_instruction->Rn) + ", " +
                                    decode_immediate(i_instruction->immediate);

  return decoded_instruction;
}