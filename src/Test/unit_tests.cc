#include <gtest/gtest.h>

#include "../Model/model.h"
#define cube "Test/cube.obj"
#define accuracy 1e-7

TEST(Parser, parser1) {
  s21::Model m;
  m.getParser().Parse(cube);
  EXPECT_EQ(m.getParser().getCountV(), 8);
  EXPECT_EQ(m.getParser().getCountE(), 30);
  EXPECT_EQ(m.getParser().getCountP(), 10);
}

TEST(Parser, parser2) {
  s21::Model m;
  m.getParser().Parse(cube);
  m.getParser().Clear();

  EXPECT_EQ(m.getParser().getCountV(), 0);
  EXPECT_EQ(m.getParser().getCountE(), 0);
  EXPECT_EQ(m.getParser().getCountP(), 0);
}

TEST(Affine, affine_move_plus_x) {
  coordinate_t coor = kX;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Move(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    v_copy.at(i * 3 + coor) += value;
  }
  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }

  EXPECT_EQ(res, true);
}

TEST(Affine, affine_move_plus_y) {
  coordinate_t coor = kY;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Move(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    v_copy.at(i * 3 + coor) += value;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_move_plus_z) {
  coordinate_t coor = kZ;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Move(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    v_copy.at(i * 3 + coor) += value;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_move_minus_x) {
  coordinate_t coor = kX;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Move(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    v_copy.at(i * 3 + coor) += value;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_move_minus_y) {
  coordinate_t coor = kY;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Move(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    v_copy.at(i * 3 + coor) += value;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_move_minus_z) {
  coordinate_t coor = kZ;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Move(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    v_copy.at(i * 3 + coor) += value;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_tansform_plus_x) {
  coordinate_t coor = kX;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Transform(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    double y = v_copy.at(i * 3 + 1);
    double z = v_copy.at(i * 3 + 2);
    v_copy.at(i * 3 + 1) = cos(value) * y - sin(value) * z;
    v_copy.at(i * 3 + 2) = sin(value) * y + cos(value) * z;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_tansform_plus_y) {
  coordinate_t coor = kY;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Transform(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    double x = v_copy.at(i * 3);
    double z = v_copy.at(i * 3 + 2);
    v_copy.at(i * 3) = cos(value) * x + sin(value) * z;
    v_copy.at(i * 3 + 2) = (-sin(value)) * x + cos(value) * z;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_tansform_plus_z) {
  coordinate_t coor = kZ;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Transform(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    double x = v_copy.at(i * 3);
    double y = v_copy.at(i * 3 + 1);

    v_copy.at(i * 3) = cos(value) * x - sin(value) * y;
    v_copy.at(i * 3 + 1) = sin(value) * x + cos(value) * y;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_tansform_minus_x) {
  coordinate_t coor = kX;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Transform(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    double y = v_copy.at(i * 3 + 1);
    double z = v_copy.at(i * 3 + 2);
    v_copy.at(i * 3 + 1) = cos(value) * y - sin(value) * z;
    v_copy.at(i * 3 + 2) = sin(value) * y + cos(value) * z;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_tansform_minus_y) {
  coordinate_t coor = kY;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Transform(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    double x = v_copy.at(i * 3);
    double z = v_copy.at(i * 3 + 2);
    v_copy.at(i * 3) = cos(value) * x + sin(value) * z;
    v_copy.at(i * 3 + 2) = (-sin(value)) * x + cos(value) * z;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_tansform_minus_z) {
  coordinate_t coor = kZ;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Transform(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  for (size_t i = 0; i < (v_copy.size() / 3); i++) {
    double x = v_copy.at(i * 3);
    double y = v_copy.at(i * 3 + 1);
    v_copy.at(i * 3) = cos(value) * x - sin(value) * y;
    v_copy.at(i * 3 + 1) = sin(value) * x + cos(value) * y;
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_plus_all) {
  coordinate_t coor = kAll;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_minus_all) {
  coordinate_t coor = kAll;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_plus_x) {
  coordinate_t coor = kX;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_plus_y) {
  coordinate_t coor = kY;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_plus_z) {
  coordinate_t coor = kZ;
  std::vector<double> v_copy;
  s21::Model m;
  double value = 2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_minus_x) {
  coordinate_t coor = kX;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_minus_y) {
  coordinate_t coor = kY;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

TEST(Affine, affine_scaling_minus_z) {
  coordinate_t coor = kZ;
  std::vector<double> v_copy;
  s21::Model m;
  double value = -2;
  bool res = true;

  m.getParser().Parse(cube);
  std::vector<double> v_orig = m.getParser().getVertexs();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  m.getAffine().Scaling(&m.getParser(), value, coor);
  v_orig = m.getParser().getVertexs();

  size_t i = coor;
  if (coor == kAll) {
    i = 0;
  }
  while (i < v_orig.size()) {
    v_copy.at(i) *= value;
    if (coor == kAll) {
      i++;
    } else {
      i += 3;
    }
  }

  for (size_t i = 0; i < v_copy.size(); i++) {
    if (fabs((v_orig.at(i) - v_copy.at(i))) > accuracy) {
      res = false;
    }
  }
  EXPECT_EQ(res, true);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
