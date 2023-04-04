#include "controller.h"

namespace s21 {
std::vector<double> &Controller::getVertexs() { return parser_.getVertexs(); }
std::vector<int> &Controller::getFacets() { return parser_.getFacets(); }
double Controller::getMaxCoordinate() { return parser_.getMaxCoordinate(); }
bool Controller::Parse(const std::string fileName) {
  return parser_.Parse(fileName);
}
void Controller::Move(double move, int coordinate) {
  affine_.Move(&parser_, move, coordinate);
}
void Controller::Transform(double angle, int coordinate) {
  affine_.Transform(&parser_, angle, coordinate);
}
void Controller::Scaling(double scale, int coordinate) {
  affine_.Scaling(&parser_, scale, coordinate);
}
void Controller::Remove() { parser_.Clear(); }
int Controller::CountV() { return parser_.getCountV(); }
int Controller::CountE() { return parser_.getCountE(); }
int Controller::CountP() { return parser_.getCountP(); }
}  // namespace s21
