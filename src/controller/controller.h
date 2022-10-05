#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include <utility>
#include <vector>
#include "../model/facade/model.h"
#include "../model/helpers/using.h"

namespace s21 {
class Controller {
  public:
    using instance = Controller*;

  private:
    static Controller* p_controller_;
    Model* model_;

    Controller() {
      model_ = s21::Model::GetInstance();
    }
    Controller(const Controller&) = delete;
    Controller(Controller&&) = delete;
    Controller& operator=(Controller&) = delete;
    ~Controller() {
      ;
    }
  public:
    static instance GetInstance();
    scene_data GetDefaultScene();
    scene_data GetSceneFromFile(std::string file_path);
    // void SpinSceneBy(scene_data& data, uint8_t direction);
    void ShiftSceneTo(scene_data& data, uint8_t direction);


};  // class Controller
}  // namespace s21

#endif  // SRC_CONTROLLER_H_