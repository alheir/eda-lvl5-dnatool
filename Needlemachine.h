#ifndef NEEDLEMACHINE_H
#define NEEDLEMACHINE_H

#include <string>
#include <vector>
#include <array>

long getGlobalAlignment(const std::string &seq1, const std::string &seq2, std::array<std::string, 3> &alignment);

#endif