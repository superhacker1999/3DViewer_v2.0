#ifndef SRC_MODEL_HELPERS_USING_H_
#define SRC_MODEL_HELPERS_USING_H_
#include <utility>
#include <vector>
namespace s21 {
using scene_data = std::pair<std::vector<double>, std::vector<int>>;
enum directions {
  kOXPLUS = 1,
  kOXMINUS = 2,
  kOYPLUS = 3,
  kOYMINUS = 4,
  kOZPLUS = 5,
  kOZMINUS = 6,
  kZOOMIN = 7,
  kZOOMOUT = 8,
  kXPLUS = 9,
  kXMINUS = 10,
  kYPLUS = 11,
  kYMINUS = 12,
  kZPLUS = 13,
  kZMINUS = 14
};
struct full_scene_data {
  scene_data data;
  std::pair<double, double> min_and_max;
};
}  // namespace s21
#endif  // SRC_MODEL_HELPERS_USING_H_
