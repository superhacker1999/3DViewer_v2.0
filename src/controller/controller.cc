#include "controller.h"

s21::Controller* s21::Controller::p_controller_ = nullptr;

s21::Controller::instance s21::Controller::GetInstance() {
  if (p_controller_ == nullptr)
    p_controller_ = new Controller();
  return p_controller_;
}

s21::scene_data s21::Controller::GetSceneFromFile(std::string file_path) {
  return model_->GetSceneFromFile(file_path);
}