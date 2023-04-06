#include "figure.h"
namespace s21 {
Figure::Figure()
    : vertexes_(std::vector<double>()),
      facets_(std::vector<int>()),
      countVertexes_(0),
      countEdges_(0),
      countPolygons_(0),
      maxCoordinate_(0) {}

void Figure::Clear() {
  vertexes_.clear();
  facets_.clear();
  countVertexes_ = 0;
  countEdges_ = 0;
  countPolygons_ = 0;
  maxCoordinate_ = 0;
}

const std::vector<double>& Figure::getVertexes() { return vertexes_; }
const std::vector<int>& Figure::getFacets() { return facets_; }
int Figure::getCountVertexes() const { return countVertexes_; }
int Figure::getCountEdges() const { return countEdges_; }
int Figure::getCountPolygons() const { return countPolygons_; }
double Figure::getMaxCoordinate() const { return maxCoordinate_; }

void Figure::setVertexes(std::vector<double>& vertexes) {
  vertexes_ = vertexes;
}
void Figure::setFacets(std::vector<int>& facets) { facets_ = facets; }
void Figure::setCountVertexes(int countVertexes) {
  countVertexes_ = countVertexes;
}
void Figure::setCountEdges(int countEdges) { countEdges_ = countEdges; }
void Figure::setCountPolygons(int countPolygons) {
  countPolygons_ = countPolygons;
}
void Figure::setMaxCoordinate(double maxCoordinate) {
  maxCoordinate_ = maxCoordinate;
}
}  // namespace s21