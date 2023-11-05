#include "cb_instruction.h"

#include "../label/label.h"

#define EQ 0
#define NE 1
#define HS 2
#define LO 3
#define MI 4
#define PL 5
#define VS 6
#define VC 7
#define HI 8
#define LS 9
#define GE 10
#define LT 11
#define GT 12
#define LE 13

std::string decode_cb_instruction(instruction_t instruction, uint32_t bits,
                                  uint32_t PC) {
  cb_instruction_t *cb_instruction =
      reinterpret_cast<cb_instruction_t *>(&bits);

  std::string decoded_instruction = "B.";

  switch (cb_instruction->Rt) {
    case EQ:
      decoded_instruction += "EQ ";
      break;
    case NE:
      decoded_instruction += "NE ";
      break;
    case HS:
      decoded_instruction += "HS ";
      break;
    case LO:
      decoded_instruction += "LO ";
      break;
    case MI:
      decoded_instruction += "MI ";
      break;
    case PL:
      decoded_instruction += "PL ";
      break;
    case VS:
      decoded_instruction += "VS ";
      break;
    case VC:
      decoded_instruction += "VC ";
      break;
    case HI:
      decoded_instruction += "HI ";
      break;
    case LS:
      decoded_instruction += "LS ";
      break;
    case GE:
      decoded_instruction += "GE ";
      break;
    case LT:
      decoded_instruction += "LT ";
      break;
    case GT:
      decoded_instruction += "GT ";
      break;
    case LE:
      decoded_instruction += "LE ";
      break;
  }

  std::string label = generateLabel(cb_instruction->COND_BR_address + PC);
  decoded_instruction += label;

  return decoded_instruction;
}