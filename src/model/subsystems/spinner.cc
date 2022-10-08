#include "spinner.h"

/*
Класс поворота вызываемый из фасадного класса Model
Используется паттерн проектирования singletone
поровачивает сцену по оси OX, OY, OZ
*/

s21::Spinner* s21::Spinner::p_spinner_ = nullptr;

/*
Метод для получения экземпляра класса
*/
s21::Spinner::instance s21::Spinner::GetInstance() {
  if (p_spinner_ == nullptr)
    p_spinner_ = new Spinner();
  return p_spinner_;
}

/*
Метод для поворота сцены
Принимает пару scene_data, содержащую
в себе точки и полигоны, и кодировку направления описанную в
../model/helpers/using.h в enum directions
Изменяет саму scene_data по адресу
*/
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

/*
Метод для поворота сцены
по оси OX принимает значение угла
изменяет вектор
*/
void s21::Spinner::RotationOX_(double angle) {
  S21Matrix dots_matrix = S21Matrix::VectorToMatrix(dots_);
  for (int i = 0; i < dots_matrix.GetRows(); ++i) {
    double temp_y = dots_matrix(i, 1);
    double temp_z = dots_matrix(i, 2);
    dots_matrix(i, 1) = cos(angle) * temp_y + sin(angle) * temp_z;
    dots_matrix(i, 2) = sin(angle) * (-temp_y) + cos(angle) * temp_z;
  }
  std::vector<double> res_vector = S21Matrix::MatrixToVector(dots_matrix);
  dots_ = std::move(res_vector);
}

/*
Метод для поворота сцены
по оси OY принимает значение угла
изменяет вектор
*/
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

/*
Метод для поворота сцены
по оси OZ принимает значение угла
изменяет вектор
*/
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



// void s21::Spinner::RotationOX_(double angle) {
//   S21Matrix dots_matrix = S21Matrix::VectorToMatrix(dots_);
//   #pragma omp parallel
//   {
//     #pragma omp for
//     for (int i = 0; i < dots_matrix.GetRows(); ++i) {
//       double temp_y = dots_matrix(i, 1);
//       double temp_z = dots_matrix(i, 2);
//       dots_matrix(i, 1) = cos(angle) * temp_y + sin(angle) * temp_z;
//       dots_matrix(i, 2) = sin(angle) * (-temp_y) + cos(angle) * temp_z;
//     }
//   }
//   std::vector<double> res_vector = S21Matrix::MatrixToVector(dots_matrix);
//   dots_ = std::move(res_vector);
// }

