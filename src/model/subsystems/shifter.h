#ifndef SRC_MODEL_SUBSYSTEMS_SHIFTER_H_
#define SRC_MODEL_SUBSYSTEMS_SHIFTER_H_

#include "../helpers/using.h"
#include "../helpers/s21_matrix.h"

#include <cstdint>

namespace s21 {
class Shifter {
  public:
    using instance = Shifter*;
    using dots_vec = std::vector<double>*;
    struct mins_and_maxes {
      double x_min;
      double x_max;
      double y_min;
      double y_max;
      double z_min;
      double z_max;
    };

  private:
    static Shifter* p_shifter_;
    dots_vec dots_;

    Shifter() {
      ;
    }
    ~Shifter() {
      ;
    }
    Shifter(const Shifter&) = delete;
    Shifter(Shifter&&) = delete;
    Shifter& operator=(Shifter&) = delete;

  public:
    static instance GetInstance();
    void ShiftSceneTo(scene_data& data, uint8_t direction);

  private:
    double GetShiftSize_(uint8_t direction);
    size_t GetStartPos_(uint8_t direction);

};  // class Shifter
}  // namespace s21

#endif  // SRC_MODEL_SUBSYSTEMS_SHIFTER_H_