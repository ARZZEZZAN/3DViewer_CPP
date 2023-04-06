#ifndef CPP4_3DVIEWER_V2_0_3_SRC_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_3_SRC_MODEL_MODEL_H_
#include <string.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "../Command/command.h"
#include "../Parser/parser.h"

namespace s21 {
class Facade {
 public:
  Facade();
  ~Facade();

  void Parse(const std::string& fileName);
  void Move(double move, Operation role);
  void Transform(double angle, Operation role);
  void Scale(double scale, Operation role);
  void Clear();

  const std::vector<double>& getVertexes();
  const std::vector<int>& getFacets();
  int getCountVertexes() const;
  int getCountEdges() const;
  int getCountPolygons() const;
  double getMaxCoordinate() const;

  void setVertexes(std::vector<double>& vertexes);
  void setFacets(std::vector<int>& facets);
  void setCountVertexes(int countVertexes);
  void setCountEdges(int countEdges);
  void setCountPolygons(int countPolygons);
  void setMaxCoordinate(double maxCoordinate);

 private:
  Parser parser_;
  Affine affine_;
  Figure figure_;
  Invoker invoker_;
  std::vector<Strategy*> strategies_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_3_SRC_MODEL_MODEL_H_
