#include "spinner.h"

s21::Spinner* s21::Spinner::p_spinner_ = nullptr;

s21::Spinner::instance s21::Spinner::GetInstance() {
  if (p_spinner_ == nullptr)
    p_spinner_ = new Spinner();
  return p_spinner_;
}

void s21::Spinner::SpinSceneBy(scene_data& data, uint8_t direction) {
  dots_ = data.first;
  double angle = 15.0f * M_PI / 180;
  if (direction == kOXMINUS || direction == kOYMINUS || direction == kOZMINUS)
    angle *= -1;
  if (direction == kOXMINUS || direction == kOXPLUS)
    RotationOX_(angle);
  else if (direction == kOYMINUS || direction == kOYPLUS)
    RotationOY_(angle);
  else
    RotationOZ_(angle);
  data.first = dots_;
}

void s21::Spinner::RotationOX_(double angle) {
  S21Matrix dots_matrix = S21Matrix::VectorToMatrix(dots_);
  for (int i = 0; i < dots_matrix.GetRows(); i++) {
    double temp_y = dots_matrix(i, 1);
    double temp_z = dots_matrix(i, 2);
    dots_matrix(i, 1) = cos(angle) * temp_y + sin(angle) * temp_z;
    dots_matrix(i, 2) = sin(angle) * (-temp_y) + cos(angle) * temp_z;
  }
  std::vector<double> res_vector = S21Matrix::MatrixToVector(dots_matrix);
  dots_ = std::move(res_vector);
}

void s21::Spinner::RotationOY_(double angle) {
  S21Matrix dots_matrix = S21Matrix::VectorToMatrix(dots_);
  for (int i = 0; i < dots_matrix.GetRows(); i++) {
    double temp_x = dots_matrix(i, 0);
    double temp_z = dots_matrix(i, 2);
    dots_matrix(i, 0) = cos(angle) * temp_x + sin(angle) * temp_z;
    dots_matrix(i, 2) = sin(angle) * (-temp_x) + cos(angle) * temp_z;
  }
  std::vector<double> res_vector = S21Matrix::MatrixToVector(dots_matrix);
  dots_ = std::move(res_vector);
}

void s21::Spinner::RotationOZ_(double angle) {
  S21Matrix dots_matrix = S21Matrix::VectorToMatrix(dots_);
  for (int i = 0; i < dots_matrix.GetRows(); i++) {
    double temp_x = dots_matrix(i, 0);
    double temp_y = dots_matrix(i, 1);
    dots_matrix(i, 0) = cos(angle) * temp_x + sin(angle) * temp_y;
    dots_matrix(i, 1) = sin(angle) * (-temp_x) + cos(angle) * temp_y;
  }
  std::vector<double> res_vector = S21Matrix::MatrixToVector(dots_matrix);
  dots_ = std::move(res_vector);
}