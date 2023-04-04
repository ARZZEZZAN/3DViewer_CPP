#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODEL_PARSER_PARSER_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODEL_PARSER_PARSER_H_

#include <string.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace s21 {
class Parser {
 public:
  Parser();
  ~Parser();
  bool Parse(const std::string fileName);
  std::vector<double>& getVertexs();
  std::vector<int>& getFacets();
  int getCountV();
  int getCountE();
  int getCountP();
  double getMaxCoordinate();
  void Clear();

 private:
  std::vector<double> vertexs_;
  std::vector<int> facets_;
  int countV_;
  int countE_;
  int countP_;

  bool ParseConditions(std::string* fileLine, char type);
  void ParseVertexs(std::string fileLine);
  void ParseFacets(std::string fileLine);
  std::vector<double> ParseLine(std::string fileLine);
  void DelSpace(std::string& fileLine);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_MODEL_PARSER_PARSER_H_
