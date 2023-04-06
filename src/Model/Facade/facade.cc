#include "facade.h"

namespace s21 {
Facade::Facade() {
  strategies_ = {new RotateStrategy(figure_, affine_),
                 new MoveStrategy(figure_, affine_),
                 new ScaleStrategy(figure_, affine_)};
}
Facade::~Facade() {
  for (auto strategy : strategies_) {
    delete strategy;
  }
}

//  Parser
void Facade::Parse(const std::string& fileName) {
  parser_.Parse(fileName, figure_);
}

// Affine
void Facade::Move(double move, Operation role) {
  invoker_.Execute(new MoveCommand(strategies_[kMoveStrgy]), role, move);
}
void Facade::Transform(double angle, Operation role) {
  invoker_.Execute(new RotateCommand(strategies_[kRotateStrgy]), role, angle);
}
void Facade::Scale(double scale, Operation role) {
  invoker_.Execute(new ScaleCommand(strategies_[kScaleStrgy]), role, scale);
}

// Figure
void Facade::Clear() { figure_.Clear(); }

const std::vector<double>& Facade::getVertexes() {
  return figure_.getVertexes();
}
const std::vector<int>& Facade::getFacets() { return figure_.getFacets(); }
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
