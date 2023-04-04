#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODEL_PARSER_PARSER_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODEL_PARSER_PARSER_H_

#include <string.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "../Figure/figure.h"

typedef std::pair<int, int> Pairs;

namespace s21 {
class Parser {
 public:
  void Parse(const std::string& fileName, s21::Figure& figure);

 private:
  s21::Figure figure_;

  bool ParseConditions(std::string& fileLine, char type);
  void ParseVertexes(std::string& fileLine);
  void ParseFacets(std::string& fileLine);
  size_t ParseEdges(const std::vector<size_t>& vec);
  std::vector<double> ParseLine(std::string& fileLine);
  void DelSpace(std::string& fileLine);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_MODEL_PARSER_PARSER_H_
