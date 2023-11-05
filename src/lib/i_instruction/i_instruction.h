#ifndef I_INSTRUCTION
#define I_INSTRUCTION

#include "../instruction.h"

#pragma pack(push, 1)
typedef struct {
  uint32_t Rd : 5;
  uint32_t Rn : 5;
  int32_t immediate : 12;
  uint32_t padding : 10;
} i_instruction_t;
#pragma pack(pop)

std::string decode_i_instruction(instruction_t instruction, uint32_t bits);

#endif