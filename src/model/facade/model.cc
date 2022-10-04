#include "model.h"

s21::Model* s21::Model::p_model_ = nullptr;

s21::Model::instance s21::Model::GetInstance() {
  if (p_model_ == nullptr)
    p_model_ = new Model();
  return p_model_;
}

s21::scene_data s21::Model::GetDefaultScene() {
  scene_data def_data;
  def_data.first = { 1.00, 2.00, 2.00, 1.00, 1.00, 2.00, 2.00, 1.00, \
  2.00, 2.00, 2.00, 2.00, 1.00, 2.00, 1.00, 1.00, 1.00, \
  1.00, 2.00, 1.00, 1.00, 2.00, 2.00, 1.00 };
  def_data.second = { 0, 1, 1, 2, 2, 3, 3, 0, 7, 6, 6, 5, 5, 4, 4, 7,
  3, 2, 2, 6, 6, 7, 7, 3, 4, 0, 0, 3, 3, 7, 7, 4, 4, 5, 5, 1, 1, 0,
  0, 4, 1, 5, 5, 6, 6, 2, 2, 1 };
  return def_data;
}

s21::scene_data s21::Model::GetSceneFromFile(std::string file_path) {
  return parser_->GetSceneFromFile(file_path);
}

// void s21::Model::SpinSceneBy(scene_data& data, uint8_t direction, double angle) {
//   // changing arrays
// }

// void s21::Model::ShiftSceneTo(scene_data& data, uint8_t direction, int shift_size) {
//   // changing arrays
// }
