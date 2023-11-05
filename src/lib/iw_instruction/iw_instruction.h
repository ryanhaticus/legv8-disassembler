#ifndef IW_INSTRUCTION
#define IW_INSTRUCTION

#include "../instruction.h"

#pragma pack(push, 1)
typedef struct {
  uint32_t Rd : 5;
  int32_t MOV_immediate : 16;
  uint32_t padding : 11;
} iw_instruction_t;
#pragma pack(pop)

std::string decode_iw_instruction(instruction_t instruction, uint32_t bits);

#endif