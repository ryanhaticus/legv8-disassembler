#include "r_instruction.h"

std::string decode_r_instruction(instruction_t instruction, uint32_t bits) {
  r_instruction_t *r_instruction = reinterpret_cast<r_instruction_t *>(&bits);

  std::string decoded_instruction = instruction.mnemonic;

  switch (instruction.wide_opcode) {
    case HALT:
    case DUMP:
    case PRNL:
      return decoded_instruction;
    case PRNT:
      decoded_instruction += " " + decode_register(r_instruction->Rd);
      return decoded_instruction;
    case BR:
      decoded_instruction += " " + decode_register(r_instruction->Rn);
      return decoded_instruction;
    case LSL:
    case LSR:
      decoded_instruction += " " + decode_register(r_instruction->Rd) + ", " +
                             decode_register(r_instruction->Rn) + ", #" +
                             std::to_string(r_instruction->shamt);
      return decoded_instruction;
  }

  decoded_instruction += " " + decode_register(r_instruction->Rd) + ", " +
                         decode_register(r_instruction->Rn) + ", " +
                         decode_register(r_instruction->Rm);

  return decoded_instruction;
}