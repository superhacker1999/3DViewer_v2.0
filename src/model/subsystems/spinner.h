#ifndef SRC_MODEL_SUBSYSTEMS_SPINNER_H_
#define SRC_MODEL_SUBSYSTEMS_SPINNER_H_


#include "../helpers/using.h"
#include "../helpers/s21_matrix.h"

#include <cstdint>

namespace s21 {
class Spinner {
  public:
    using instance = Spinner*;
    using dots_vec = std::vector<double>;

  private:
    static Spinner* p_spinner_;
    dots_vec dots_;

    Spinner() {
      ;
    }
    ~Spinner() {
      ;
    }
    Spinner(const Spinner&) = delete;
    Spinner(Spinner&&) = delete;
    Spinner& operator=(Spinner&) = delete;

  public:
    static instance GetInstance();
    void SpinSceneBy(scene_data& data, uint8_t direction);

  private:
    void RotationOX_(double angle);
    void RotationOY_(double angle);
    void RotationOZ_(double angle);


};  // class Spinner
}  // namespace s21

#endif  // SRC_MODEL_SUBSYSTEMS_SPINNER_H_
