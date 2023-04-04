#include "affine.h"
namespace s21 {
Affine::Affine() {}
Affine::~Affine() {}
void Affine::Move(Parser *p, double move, int coordinate) {
  for (int i = 0; i < int(p->getCountV()); i++) {
    p->getVertexs().at(i * 3 + coordinate) += move;
  }
}
void Affine::Transform(Parser *p, double angle, int coordinate) {
  for (int i = 0; i < int(p->getCountV()); i++) {
    double x = p->getVertexs().at(i * 3);
    double y = p->getVertexs().at(i * 3 + 1);
    double z = p->getVertexs().at(i * 3 + 2);
    if (coordinate == kX) {
      p->getVertexs().at(i * 3 + 1) = cos(angle) * y - sin(angle) * z;
      p->getVertexs().at(i * 3 + 2) = sin(angle) * y + cos(angle) * z;
    } else if (coordinate == kY) {
      p->getVertexs().at(i * 3) = cos(angle) * x + sin(angle) * z;
      p->getVertexs().at(i * 3 + 2) = (-sin(angle)) * x + cos(angle) * z;
    } else if (coordinate == kZ) {
      p->getVertexs().at(i * 3) = cos(angle) * x - sin(angle) * y;
      p->getVertexs().at(i * 3 + 1) = sin(angle) * x + cos(angle) * y;
    }
  }
}
void Affine::Scaling(Parser *p, double scale, int coordinate) {
  int i = coordinate;
  if (coordinate == kAll) {
    i = 0;
  }
  while (i < (int(p->getCountV()) * 3)) {
    p->getVertexs().at(i) *= scale;
    if (coordinate == kAll) {
      i++;
    } else {
      i += 3;
    }
  }
}
}  // namespace s21
