#include "facade.h"

namespace s21 {
//  Parser
void Facade::Parse(const std::string& fileName) {
  parser_.Parse(fileName, figure_);
}

// Affine
void Facade::Move(double move, int coordinate) {
  affine_.Move(figure_, move, coordinate);
}
void Facade::Transform(double angle, int coordinate) {
  affine_.Transform(figure_, angle, coordinate);
}
void Facade::Scale(double scale, int coordinate) {
  affine_.Scale(figure_, scale, coordinate);
}

// Figure
void Facade::Clear() { figure_.Clear(); }

std::vector<double> Facade::getVertexes() const {
  return figure_.getVertexes();
}
std::vector<int> Facade::getFacets() const { return figure_.getFacets(); }
int Facade::getCountVertexes() const { return figure_.getCountVertexes(); }
int Facade::getCountEdges() const { return figure_.getCountEdges(); }
int Facade::getCountPolygons() const { return figure_.getCountPolygons(); }
double Facade::getMaxCoordinate() const { return figure_.getMaxCoordinate(); }

void Facade::setVertexes(std::vector<double>& vertexes) {
  figure_.setVertexes(vertexes);
}
void Facade::setFacets(std::vector<int>& facets) { figure_.setFacets(facets); }
void Facade::setCountVertexes(int countVertexes) {
  figure_.setCountVertexes(countVertexes);
}
void Facade::setCountEdges(int countEdges) {
  figure_.setCountEdges(countEdges);
}
void Facade::setCountPolygons(int countPolygons) {
  figure_.setCountPolygons(countPolygons);
}
void Facade::setMaxCoordinate(double maxCoordinate) {
  figure_.setMaxCoordinate(maxCoordinate);
}

}  // namespace s21