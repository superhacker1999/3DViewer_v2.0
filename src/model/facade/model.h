#ifndef SRC_MODEL_FACADE_MODEL_H_
#define SRC_MODEL_FACADE_MODEL_H_

#include <utility>
#include <vector>
#include <string>

#include "../subsystems/subsystems.h"
#include "../helpers/using.h"

/* 
This class has the only one instance
so that we use the singletone pattern
*/

namespace s21 {
class Model {
  public:
    using instance = Model*;

  private:
    static Model* p_model_;
    Parser* parser_;
    Shifter* shifter_;
    Spinner* spinner_;

  private:
    Model() {
      parser_ = s21::Parser::GetInstance();
      shifter_ = s21::Shifter::GetInstance();
      spinner_ = s21::Spinner::GetInstance();
    }
    Model(const Model&) = delete;
    Model(Model&&) = delete;
    Model& operator=(Model&) = delete;
    ~Model() {
      ;
    }
  public:
    static instance GetInstance();
    full_scene_data GetDefaultScene();
    full_scene_data GetSceneFromFile(std::string file_path);
    scene_data SpinSceneBy(scene_data& data, uint8_t direction);
    scene_data ShiftSceneTo(scene_data& data, uint8_t direction);
};
}  // namespace s21
#endif  // SRC_MODEL_FACADE_MODEL_H_
