#ifndef SRC_MODEL_HELPERS_USING_H_
#define SRC_MODEL_HELPERS_USING_H_
#include <utility>
#include <vector>
namespace s21 {
  using scene_data = std::pair<std::vector<double>, std::vector<int>>;
  enum directions {
    kOX = 1,
    kOY = 2,
    kOZ = 3,
    kZOOMIN = 4,
    kZOOMOUT = 5,
    kX = 6,
    kY = 7,
    kZ = 8
  };
}
#endif  // SRC_MODEL_HELPERS_USING_H_
