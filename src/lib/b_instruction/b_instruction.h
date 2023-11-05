#ifndef B_INSTRUCTION
#define B_INSTRUCTION

#include "../instruction.h"

#pragma pack(push, 1)
typedef struct {
  int32_t BR_address : 26;
  uint32_t padding : 6;
} b_instruction_t;
#pragma pack(pop)

std::string decode_b_instruction(instruction_t instruction, uint32_t bits,
                                 uint32_t PC);

#endif