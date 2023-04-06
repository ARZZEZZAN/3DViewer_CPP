#ifndef CPP4_3DVIEWER_V2_0_3_SRC_MODEL_FIGURE_FIGURE_H_
#define CPP4_3DVIEWER_V2_0_3_SRC_MODEL_FIGURE_FIGURE_H_

#include <vector>

namespace s21 {
class Figure {
 public:
  Figure();
  Figure& operator=(Figure&& other) noexcept;
  void Clear();

  std::vector<double>& getVertexes();
  std::vector<int>& getFacets();
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
  std::vector<double> vertexes_;
  std::vector<int> facets_;
  int countVertexes_;
  int countEdges_;
  int countPolygons_;
  double maxCoordinate_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_3_SRC_MODEL_FIGURE_FIGURE_H_
