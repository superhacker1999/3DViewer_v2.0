#ifndef SRC_MODEL_SUBSYSTEMS_SHIFTER_H_
#define SRC_MODEL_SUBSYSTEMS_SHIFTER_H_

#include <math.h>

#include <cstdint>

#include "../helpers/using.h"

namespace s21 {
class Shifter {
 public:
  using instance = Shifter*;
  using dots_vec = std::vector<double>*;

 private:
  static Shifter* p_shifter_;
  dots_vec dots_;

  Shifter() { ; }
  ~Shifter() { ; }
  Shifter(const Shifter&) = delete;
  Shifter(Shifter&&) = delete;
  Shifter& operator=(Shifter&) = delete;

 public:
  static instance GetInstance();
  void ShiftSceneTo(scene_data& data, uint8_t direction);

 private:
  double GetShiftSize_(uint8_t direction);
  size_t GetStartPos_(uint8_t direction);
  void ZoomChange_(uint8_t direction);

};  // class Shifter
}  // namespace s21

#endif  // SRC_MODEL_SUBSYSTEMS_SHIFTER_H_
