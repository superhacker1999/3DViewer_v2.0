#include "model.h"

s21::Model* s21::Model::p_model_ = nullptr;

s21::Model::instance s21::Model::GetInstance() {
  if (p_model_ == nullptr)
    p_model_ = new Model();
  return p_model_;
}

// s21::Model::scene_data s21::Model::GetDefaultScene() {
//   scene_data def_data;
//   // default scene
//   return def_data;
// }

s21::Model::scene_data s21::Model::GetSceneFromFile(std::string file_path) {
  return parser_->GetSceneFromFile(file_path);
}

// void s21::Model::SpinSceneBy(scene_data& data, uint8_t direction) {
//   // changing arrays
// }

// void s21::Model::ShiftSceneTo(scene_data& data, uint8_t direction) {
//   // changing arrays
// }