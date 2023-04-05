#include <gtest/gtest.h>

#include "../Controller/controller.h"
#define cube "Test/cube.obj"
#define accuracy 1e-7

TEST(Parser, parser1) {
  s21::Controller f;
  f.Parse(cube);
  EXPECT_EQ(f.getCountVertexes(), 8);
  EXPECT_EQ(f.getCountEdges(), 12);
  EXPECT_EQ(f.getCountPolygons(), 6);
  EXPECT_EQ(f.getMaxCoordinate(), 1);
}

TEST(Parser, parser2) {
  s21::Controller f;
  f.Parse(cube);
  f.Remove();

  EXPECT_EQ(f.getCountVertexes(), 0);
  EXPECT_EQ(f.getCountEdges(), 0);
  EXPECT_EQ(f.getCountPolygons(), 0);
}

TEST(Affine, affine_move_plus_x) {
  coordinate_t coor = kX;
  std::vector<double> v_copy;
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Move(value, coor);
  v_orig = f.getVertexes();
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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Move(value, coor);
  v_orig = f.getVertexes();
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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Move(value, coor);
  v_orig = f.getVertexes();
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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Move(value, coor);
  v_orig = f.getVertexes();
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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Move(value, coor);
  v_orig = f.getVertexes();
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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Move(value, coor);
  v_orig = f.getVertexes();
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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Transform(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Transform(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Transform(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Transform(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Transform(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Transform(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = 2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
  s21::Controller f;
  double value = -2;
  bool res = true;

  f.Parse(cube);
  std::vector<double> v_orig = f.getVertexes();
  for (size_t i = 0; i < v_orig.size(); i++) {
    v_copy.push_back(v_orig.at(i));
  }
  f.Scale(value, coor);
  v_orig = f.getVertexes();

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
