#ifndef LABEL_H
#define LABEL_H

#include <cstdint>
#include <map>
#include <string>

extern std::map<int, std::string> labelMap;

std::string generateLabel(int32_t instructionNum);

#endif