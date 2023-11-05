#include "b_instruction.h"

#include "../label/label.h"

std::string decode_b_instruction(instruction_t instruction, uint32_t bits,
                                 uint32_t PC) {
  b_instruction_t *b_instruction = reinterpret_cast<b_instruction_t *>(&bits);

  std::string label = generateLabel(b_instruction->BR_address + PC);
  std::string decoded_instruction = instruction.mnemonic + " " + label;

  return decoded_instruction;
}