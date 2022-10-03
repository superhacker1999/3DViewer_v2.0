#ifndef SRC_MODEL_FACADE_MODEL_H
#define SRC_MODEL_FACADE_MODEL_H_

#include <utility>
#include <vector>
#include <string>

#include "../subsystems/subsystems.h"

/* 
This class has the only one instance
so that we use the singletone pattern
*/

namespace s21 {
class Model {
  public:
    using instance = Model*;
    using scene_data = std::pair<std::vector<double>, std::vector<int>>;

  private:
    static Model* p_model_;
    Parser* parser_;
    // Shifter* shifter_;
    // Spinner* spinner_;
  private:
    Model() {
      parser_ = s21::Parser::GetInstance();
    }
    // Model(const Model&) = default;
    // Model(Model&&) = default;
    // Model& operator=(Model&) = default;
    ~Model() {
      delete p_model_;
    }
  public:
    static instance GetInstance();
    // scene_data GetDefaultScene();
    scene_data GetSceneFromFile(std::string file_path);
    // void SpinSceneBy(scene_data& data, uint8_t direction);
    // void ShiftSceneTo(scene_data& data, uint8_t direction);
};
}  // namespace s21
#endif  // SRC_MODEL_FACADE_MODEL_H_