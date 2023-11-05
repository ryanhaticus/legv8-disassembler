#ifndef R_INSTRUCTION
#define R_INSTRUCTION

#include "../instruction.h"

#pragma pack(push, 1)
typedef struct {
  uint32_t Rd : 5;
  uint32_t Rn : 5;
  uint32_t shamt : 6;
  uint32_t Rm : 5;
  uint32_t padding : 11;
} r_instruction_t;
#pragma pack(pop)

std::string decode_r_instruction(instruction_t instruction, uint32_t bits);

#endif