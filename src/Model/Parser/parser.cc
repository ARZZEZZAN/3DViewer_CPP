#include "parser.h"
namespace s21 {
Parser::Parser() {
  countV_ = 0;
  countP_ = 0;
  countE_ = 0;
}
Parser::~Parser() {}
std::vector<double>& Parser::getVertexs() { return vertexs_; }
std::vector<int>& Parser::getFacets() { return facets_; }
int Parser::getCountV() { return countV_; }
int Parser::getCountE() { return countE_; }
int Parser::getCountP() { return countP_; }
double Parser::getMaxCoordinate() {
  double maxCoordinate = 0;
  for (size_t i = 0; i < vertexs_.size(); i++) {
    if (fabs(maxCoordinate) < fabs(vertexs_.at(i))) {
      maxCoordinate = vertexs_.at(i);
    }
  }
  return fabs(maxCoordinate);
}

void Parser::Clear() {
  vertexs_.clear();
  facets_.clear();
  countV_ = 0;
  countE_ = 0;
  countP_ = 0;
}
bool Parser::Parse(const std::string fileName) {
  bool success = true;
  std::ifstream file(fileName);
  if (file.is_open() && strcmp(&fileName[fileName.size() - 3], ".obj")) {
    Clear();
    std::string fileLine;
    while (std::getline(file, fileLine)) {
      if (ParseConditions(&fileLine, 'v')) {
        ParseVertexs(fileLine);
      } else if (ParseConditions(&fileLine, 'f')) {
        ParseFacets(fileLine);
      }
    }
  } else {
    success = false;
  }
  return success;
}
bool Parser::ParseConditions(std::string* fileLine, char type) {
  bool success = false;
  while (!fileLine->empty() && isspace(fileLine->at(0))) {
    fileLine->erase(fileLine->begin());
  }
  if (!fileLine->empty() && fileLine->at(0) == type) {
    fileLine->erase(fileLine->begin());
    if (!fileLine->empty() && fileLine->at(0) == ' ') {
      success = true;
    }
  }
  return success;
}
void Parser::ParseVertexs(std::string fileLine) {
  std::vector<double> vec = ParseLine(fileLine);
  for (size_t i = 0; i < 3; i++) {
    if (i < vec.size()) {
      vertexs_.push_back(vec.at(i));
    } else {
      vertexs_.push_back(0);
    }
  }
  if (!vec.empty()) {
    countV_++;
  }
}
void Parser::ParseFacets(std::string fileLine) {
  std::vector<double> vec = ParseLine(fileLine);
  if (!vec.empty()) {
    facets_.push_back(vec.at(0) - 1);
    for (size_t i = 1; i < vec.size(); i++) {
      facets_.push_back(vec.at(i) - 1);
      facets_.push_back(vec.at(i) - 1);
    }
    facets_.push_back(vec.at(0) - 1);
    countE_ += vec.size();
    countP_ += 1;
  }
}

std::vector<double> Parser::ParseLine(std::string fileLine) {
  std::vector<double> res;
  while (!fileLine.empty()) {
    double num = 0;
    sscanf(fileLine.c_str(), "%lf", &num);
    res.push_back(num);

    DelSpace(fileLine);

    while (!fileLine.empty() && !isspace(fileLine.at(0))) {
      fileLine.erase(fileLine.begin());
    }
    DelSpace(fileLine);
  }
  return res;
}

void Parser::DelSpace(std::string& fileLine) {
  while (!fileLine.empty() && isspace(fileLine.at(0))) {
    fileLine.erase(fileLine.begin());
  }
}
}  // namespace s21
