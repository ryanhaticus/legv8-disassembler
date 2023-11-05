#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "./lib/b_instruction/b_instruction.h"
#include "./lib/cb_instruction/cb_instruction.h"
#include "./lib/d_instruction/d_instruction.h"
#include "./lib/i_instruction/i_instruction.h"
#include "./lib/instruction.h"
#include "./lib/iw_instruction/iw_instruction.h"
#include "./lib/label/label.h"
#include "./lib/r_instruction/r_instruction.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  // Convert char* fileName to std::string
  std::string fileName = std::string(argv[1]);

  // Open file stream to the binary
  std::ifstream binary(fileName, std::ios::binary);

  // Report an error if the file could not be opened.
  if (!binary.is_open()) {
    std::cout << "Could not open file " << fileName << std::endl;
    return 1;
  }

  // Create vector of 32 bit instructions
  std::vector<uint32_t> instructions;

  // Read the binary file one instruction at a time and add it to the vector
  while (!binary.eof()) {
    uint32_t instruction;

    // Read instruction
    binary.read(reinterpret_cast<char *>(&instruction), sizeof(instruction));

    // Handle endianness (little endian to big endian)
    instruction = __builtin_bswap32(instruction);

    // Add instruction to vector
    instructions.push_back(instruction);
  }

  // Close the file stream to the binary
  binary.close();

  // Dispose of the last entry, this isn't an instruction
  instructions.pop_back();

  // Create a stream of decoded instructions without labels
  std::stringstream legv8asm_no_labels;

  // Iterate through the 32 bit instructions one at a time
  for (uint32_t PC = 0; PC < instructions.size(); PC++) {
    uint32_t bits = instructions[PC];
    instruction_t instruction;

    // Decipher the instruction via. its opcode
    for (instruction_t possibleInstruction : instructionMap) {
      for (int i = 11; i >= 6; i--) {
        uint32_t opcode = (bits >> (32 - i));
        if (!(opcode ^ possibleInstruction.wide_opcode)) {
          instruction = possibleInstruction;
          // Since we can't break out of two nested loops, we use goto
          goto found_instruction;
        }
      }
    }

  found_instruction:
    // Decode the instruction based on its type
    switch (instruction.type) {
      case INSTRUCTION_TYPE_B: {
        legv8asm_no_labels << decode_b_instruction(instruction, bits, PC)
                           << std::endl;
        break;
      }
      case INSTRUCTION_TYPE_CB: {
        legv8asm_no_labels << decode_cb_instruction(instruction, bits, PC)
                           << std::endl;
        break;
      }
      case INSTRUCTION_TYPE_D: {
        legv8asm_no_labels << decode_d_instruction(instruction, bits)
                           << std::endl;
        break;
      }
      case INSTRUCTION_TYPE_I: {
        legv8asm_no_labels << decode_i_instruction(instruction, bits)
                           << std::endl;
        break;
      }
      case INSTRUCTION_TYPE_IW: {
        legv8asm_no_labels << decode_iw_instruction(instruction, bits)
                           << std::endl;
        break;
      }
      case INSTRUCTION_TYPE_R: {
        legv8asm_no_labels << decode_r_instruction(instruction, bits)
                           << std::endl;
        break;
      }
    }
  }

  // Prepare to iterate through the stream of decoded instructions
  std::string line;
  legv8asm_no_labels.seekg(0, std::ios::beg);

  // Iterate through the stream of decoded instructions one at a time
  for (int PC = 0; std::getline(legv8asm_no_labels, line); PC++) {
    // If a label exists pointing to this instruction, add the respective label
    if (labelMap.count(PC)) {
      std::cout << labelMap[PC] << ":" << std::endl;
    }

    // Print instruction to standard output
    std::cout << line << std::endl;
  }

  return 0;
}