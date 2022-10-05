#include "controller.h"

s21::Controller* s21::Controller::p_controller_ = nullptr;

s21::Controller::instance s21::Controller::GetInstance() {
  if (p_controller_ == nullptr)
    p_controller_ = new Controller();
  return p_controller_;
}

s21::full_scene_data s21::Controller::GetSceneFromFile(std::string file_path) {
  return model_->GetSceneFromFile(file_path);
}

s21::full_scene_data s21::Controller::GetDefaultScene() {
  return model_->GetDefaultScene();
}

void s21::Controller::ShiftSceneTo(scene_data& data, uint8_t direction) {
  model_->ShiftSceneTo(data, direction);
}

void s21::Controller::SpinSceneBy(scene_data& data, uint8_t direction) {
  model_->SpinSceneBy(data, direction);
}
