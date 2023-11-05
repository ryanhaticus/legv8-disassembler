#ifndef CB_INSTRUCTION
#define CB_INSTRUCTION

#include "../instruction.h"

#pragma pack(push, 1)
typedef struct {
  uint32_t Rt : 5;
  int32_t COND_BR_address : 19;
  uint32_t padding : 8;
} cb_instruction_t;
#pragma pack(pop)

std::string decode_cb_instruction(instruction_t instruction, uint32_t bits,
                                  uint32_t PC);

#endif