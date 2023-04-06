#ifndef CPP4_3DVIEWER_V2_0_3_SRC_MODEL_PARSER_PARSER_H_
#define CPP4_3DVIEWER_V2_0_3_SRC_MODEL_PARSER_PARSER_H_

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
  Parser();
  void Parse(const std::string& fileName, Figure& figure);

 private:
  std::vector<double> vertexes_;
  std::vector<int> facets_;
  int countVertexes_;
  int countPolygons_;
  double maxCoordinate_;

  void setFigure(Figure& figure);

  bool ParseConditions(std::string& fileLine, char type);
  void ParseVertexes(std::string& fileLine);
  void ParseFacets(std::string& fileLine);
  int ParseEdges();
  std::vector<double> ParseLine(std::string& fileLine);
  void DelSpace(std::string& fileLine);
  void Clear();
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_3_SRC_MODEL_PARSER_PARSER_H_
