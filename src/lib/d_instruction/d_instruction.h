#ifndef D_INSTRUCTION
#define D_INSTRUCTION

#include "../instruction.h"

#pragma pack(push, 1)
typedef struct {
  uint32_t Rt : 5;
  uint32_t Rn : 5;
  uint32_t op : 2;
  uint32_t DT_address : 9;
  uint32_t padding : 11;
} d_instruction_t;
#pragma pack(pop)

std::string decode_d_instruction(instruction_t instruction, uint32_t bits);

#endif