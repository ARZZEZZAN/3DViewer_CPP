#include "controller.h"

namespace s21 {
// Parser
void Controller::Parse(const std::string& fileName) { facade_.Parse(fileName); }

// Affine
void Controller::Move(double move, int coordinate) {
  facade_.Move(move, coordinate);
}
void Controller::Transform(double angle, int coordinate) {
  facade_.Transform(angle, coordinate);
}
void Controller::Scale(double scale, int coordinate) {
  facade_.Scale(scale, coordinate);
}

// Figure
void Controller::Remove() { facade_.Clear(); }

std::vector<double> Controller::getVertexes() const {
  return facade_.getVertexes();
}
std::vector<int> Controller::getFacets() const { return facade_.getFacets(); }
int Controller::getCountVertexes() const { return facade_.getCountVertexes(); }
int Controller::getCountEdges() const { return facade_.getCountEdges(); }
int Controller::getCountPolygons() const { return facade_.getCountPolygons(); }
double Controller::getMaxCoordinate() const {
  return facade_.getMaxCoordinate();
}
}  // namespace s21
