#include "controller.h"

namespace s21 {
// Parser
void Controller::Parse(const std::string& fileName) { facade_.Parse(fileName); }

// Affine
void Controller::Move(double move, Operation role) { facade_.Move(move, role); }
void Controller::Transform(double angle, Operation role) {
  facade_.Transform(angle, role);
}
void Controller::Scale(double scale, Operation role) {
  facade_.Scale(scale, role);
}

// Figure
void Controller::Remove() { facade_.Clear(); }

const std::vector<double>& Controller::getVertexes() {
  return facade_.getVertexes();
}
const std::vector<int>& Controller::getFacets() { return facade_.getFacets(); }
int Controller::getCountVertexes() const { return facade_.getCountVertexes(); }
int Controller::getCountEdges() const { return facade_.getCountEdges(); }
int Controller::getCountPolygons() const { return facade_.getCountPolygons(); }
double Controller::getMaxCoordinate() const {
  return facade_.getMaxCoordinate();
}
}  // namespace s21
