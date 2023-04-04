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
  facade_.Transform(scale, coordinate);
}

// Figure
void Controller::Remove() { facade_.Clear(); }
std::vector<double> Controller::getVertexes() const {
  return facade_.getVertexes();
}
std::vector<size_t> Controller::getFacets() const {
  return facade_.getFacets();
}
size_t Controller::getCountVertexes() const {
  return facade_.getCountVertexes();
}
size_t Controller::getCountEdges() const { return facade_.getCountEdges(); }
size_t Controller::getCountPolygons() const {
  return facade_.getCountPolygons();
}
double Controller::getMaxCoordinate() const {
  return facade_.getMaxCoordinate();
}

void Controller::setVertexes(std::vector<double>& vertexes) {
  facade_.setVertexes(vertexes);
}
void Controller::setFacets(std::vector<size_t>& facets) {
  facade_.setFacets(facets);
}
void Controller::setCountVertexes(size_t countVertexes) {
  facade_.setCountVertexes(countVertexes);
}
void Controller::setCountEdges(size_t countEdges) {
  facade_.setCountEdges(countEdges);
}
void Controller::setCountPolygons(size_t countPolygons) {
  facade_.setCountPolygons(countPolygons);
}
void Controller::setMaxCoordinate(double maxCoordinate) {
  facade_.setMaxCoordinate(maxCoordinate);
}
}  // namespace s21
