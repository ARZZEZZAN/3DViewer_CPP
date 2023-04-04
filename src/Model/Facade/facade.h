#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODEL_MODEL_H_
#include <string.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "../Affine/affine.h"
#include "../Parser/parser.h"
namespace s21 {
class Facade {
 public:
  //  Parser
  void Parse(const std::string& fileName);

  // Affine
  void Move(double move, int coordinate);
  void Transform(double angle, int coordinate);
  void Scale(double scale, int coordinate);

  // Figure
  void Clear();

  std::vector<double> getVertexes() const;
  std::vector<size_t> getFacets() const;
  size_t getCountVertexes() const;
  size_t getCountEdges() const;
  size_t getCountPolygons() const;
  double getMaxCoordinate() const;

  void setVertexes(std::vector<double>& vertexes);
  void setFacets(std::vector<size_t>& facets);
  void setCountVertexes(size_t countVertexes);
  void setCountEdges(size_t countEdges);
  void setCountPolygons(size_t countPolygons);
  void setMaxCoordinate(double maxCoordinate);

 private:
  Parser parser_;
  Affine affine_;
  Figure figure_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_2_SRC_MODEL_MODEL_H_
