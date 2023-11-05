#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>
#include <iostream>
#include <string>

#include "./immediate/immediate.h"
#include "./register/register.h"

typedef enum {
  INSTRUCTION_TYPE_B,
  INSTRUCTION_TYPE_CB,
  INSTRUCTION_TYPE_D,
  INSTRUCTION_TYPE_I,
  INSTRUCTION_TYPE_IW,
  INSTRUCTION_TYPE_R
} instruction_type_t;

typedef struct {
  uint32_t wide_opcode : 11;
  std::string mnemonic;
  instruction_type_t type;
} instruction_t;

#define ADD 0b10001011000
#define ADDI 0b1001000100
#define ADDIS 0b1011000100
#define ADDS 0b10101011000
#define AND 0b10001010000
#define ANDI 0b1001001000
#define ANDIS 0b1111001000
#define ANDS 0b11101010000
#define B 0b000101
#define BL 0b100101
#define BR 0b11010110000
#define CBNZ 0b10110101
#define CBZ 0b10110100
#define DUMP 0b11111111110
#define EOR 0b11001010000
#define EORI 0b1101001000
#define FADDD 0b00011110011
#define FADDS 0b00011110001
#define FCMPD 0b00011110011
#define FCMPS 0b00011110001
#define FDIVD 0b00011110011
#define FDIVS 0b00011110001
#define FMULD 0b00011110011
#define FMULS 0b00011110001
#define FSUBD 0b00011110011
#define FSUBS 0b00011110001
#define HALT 0b11111111111
#define LDUR 0b11111000010
#define LDURB 0b00111000010
#define LDURD 0b11111100010
#define LDURH 0b01111000010
#define LDURS 0b10111100010
#define LDURSW 0b10111000100
#define LSL 0b11010011011
#define LSR 0b11010011010
#define MUL 0b10011011000
#define ORR 0b10101010000
#define ORRI 0b1011001000
#define PRNL 0b11111111100
#define PRNT 0b11111111101
#define SDIV 0b10011010110
#define SMULH 0b10011011010
#define STUR 0b11111000000
#define STURB 0b00111000000
#define STURD 0b11111100000
#define STURH 0b01111000000
#define STURS 0b10111100000
#define STURW 0b10111000000
#define SUB 0b11001011000
#define SUBI 0b1101000100
#define SUBIS 0b1111000100
#define SUBS 0b11101011000
#define UDIV 0b10011010110
#define UMULH 0b10011011110
#define CB 0b01010100

const instruction_t instructionMap[] = {{ADD, "ADD", INSTRUCTION_TYPE_R},
                                        {ADDI, "ADDI", INSTRUCTION_TYPE_I},
                                        {ADDIS, "ADDIS", INSTRUCTION_TYPE_I},
                                        {ADDS, "ADDS", INSTRUCTION_TYPE_R},
                                        {AND, "AND", INSTRUCTION_TYPE_R},
                                        {ANDI, "ANDI", INSTRUCTION_TYPE_I},
                                        {ANDIS, "ANDIS", INSTRUCTION_TYPE_I},
                                        {ANDS, "ANDS", INSTRUCTION_TYPE_R},
                                        {B, "B", INSTRUCTION_TYPE_B},
                                        {BL, "BL", INSTRUCTION_TYPE_B},
                                        {BR, "BR", INSTRUCTION_TYPE_R},
                                        {CBNZ, "CBNZ", INSTRUCTION_TYPE_CB},
                                        {CBZ, "CBZ", INSTRUCTION_TYPE_CB},
                                        {DUMP, "DUMP", INSTRUCTION_TYPE_R},
                                        {EOR, "EOR", INSTRUCTION_TYPE_R},
                                        {EORI, "EORI", INSTRUCTION_TYPE_I},
                                        {FADDD, "FADDD", INSTRUCTION_TYPE_D},
                                        {FADDS, "FADDS", INSTRUCTION_TYPE_D},
                                        {FCMPD, "FCMPD", INSTRUCTION_TYPE_D},
                                        {FCMPS, "FCMPS", INSTRUCTION_TYPE_D},
                                        {FDIVD, "FDIVD", INSTRUCTION_TYPE_D},
                                        {FDIVS, "FDIVS", INSTRUCTION_TYPE_D},
                                        {FMULD, "FMULD", INSTRUCTION_TYPE_D},
                                        {FMULS, "FMULS", INSTRUCTION_TYPE_D},
                                        {FSUBD, "FSUBD", INSTRUCTION_TYPE_D},
                                        {FSUBS, "FSUBS", INSTRUCTION_TYPE_D},
                                        {HALT, "HALT", INSTRUCTION_TYPE_R},
                                        {LDUR, "LDUR", INSTRUCTION_TYPE_D},
                                        {LDURB, "LDURB", INSTRUCTION_TYPE_D},
                                        {LDURD, "LDURD", INSTRUCTION_TYPE_D},
                                        {LDURH, "LDURH", INSTRUCTION_TYPE_D},
                                        {LDURS, "LDURS", INSTRUCTION_TYPE_D},
                                        {LDURSW, "LDURSW", INSTRUCTION_TYPE_D},
                                        {LSL, "LSL", INSTRUCTION_TYPE_R},
                                        {LSR, "LSR", INSTRUCTION_TYPE_R},
                                        {MUL, "MUL", INSTRUCTION_TYPE_R},
                                        {ORR, "ORR", INSTRUCTION_TYPE_R},
                                        {ORRI, "ORRI", INSTRUCTION_TYPE_I},
                                        {PRNL, "PRNL", INSTRUCTION_TYPE_R},
                                        {PRNT, "PRNT", INSTRUCTION_TYPE_R},
                                        {SDIV, "SDIV", INSTRUCTION_TYPE_R},
                                        {SMULH, "SMULH", INSTRUCTION_TYPE_R},
                                        {STUR, "STUR", INSTRUCTION_TYPE_D},
                                        {STURB, "STURB", INSTRUCTION_TYPE_D},
                                        {STURD, "STURD", INSTRUCTION_TYPE_D},
                                        {STURH, "STURH", INSTRUCTION_TYPE_D},
                                        {STURS, "STURS", INSTRUCTION_TYPE_D},
                                        {STURW, "STURW", INSTRUCTION_TYPE_D},
                                        {SUB, "SUB", INSTRUCTION_TYPE_R},
                                        {SUBI, "SUBI", INSTRUCTION_TYPE_I},
                                        {SUBIS, "SUBIS", INSTRUCTION_TYPE_I},
                                        {SUBS, "SUBS", INSTRUCTION_TYPE_R},
                                        {UDIV, "UDIV", INSTRUCTION_TYPE_R},
                                        {UMULH, "UMULH", INSTRUCTION_TYPE_R},
                                        {CB, "CB", INSTRUCTION_TYPE_CB}};

#endif