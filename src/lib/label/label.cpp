#include "label.h"

std::map<int, std::string> labelMap;

std::string generateLabel(int32_t instructionNum) {
  if (labelMap.count(instructionNum) > 0) {
    return labelMap[instructionNum];
  }

  std::string label = "label_" + std::to_string(instructionNum);
  labelMap[instructionNum] = label;

  return label;
}