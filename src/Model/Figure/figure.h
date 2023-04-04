#ifndef CPP4_3DVIEWER_V2_0_2_SRC_MODEL_FIGURE_FIGURE_H_
#define CPP4_3DVIEWER_V2_0_2_SRC_MODEL_FIGURE_FIGURE_H_

#include <vector>

namespace s21 {
class Figure {
 public:
  Figure();
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
  std::vector<double> vertexes_;
  std::vector<size_t> facets_;
  size_t countVertexes_;
  size_t countEdges_;
  size_t countPolygons_;
  double maxCoordinate_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_SRC_MODEL_FIGURE_FIGURE_H_
