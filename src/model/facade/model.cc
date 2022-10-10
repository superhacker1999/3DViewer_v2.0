#include "model.h"

/*Класс model вызываемый из класса Controller
Используется паттерн проектирования singletone
является фасадом для вспомогательных подклассов
Вызывает необходимые методы из классов:
parser, spinner, shifter*/

s21::Model* s21::Model::p_model_ = nullptr;

/*Метод для получения экземпляра класса*/
s21::Model::instance s21::Model::GetInstance() {
  if (p_model_ == nullptr) p_model_ = new Model();
  return p_model_;
}

/*Метод создания стандартной сцены
возвращает данные о точках, полигонах и мин. макс.
значения точек с коэффициентом*/
s21::full_scene_data s21::Model::GetDefaultScene() {
  scene_data def_data;
  def_data.first = {1.00, 2.00, 2.00, 1.00, 1.00, 2.00, 2.00, 1.00,
                    2.00, 2.00, 2.00, 2.00, 1.00, 2.00, 1.00, 1.00,
                    1.00, 1.00, 2.00, 1.00, 1.00, 2.00, 2.00, 1.00};
  def_data.second = {0, 1, 1, 2, 2, 3, 3, 0, 7, 6, 6, 5, 5, 4, 4, 7,
                     3, 2, 2, 6, 6, 7, 7, 3, 4, 0, 0, 3, 3, 7, 7, 4,
                     4, 5, 5, 1, 1, 0, 0, 4, 1, 5, 5, 6, 6, 2, 2, 1};
  full_scene_data data = {def_data, {1.4, 2.8}};
  return data;
}

/*Метод создания сцены из файла
возвращает данные о точках, полигонах и мин. макс.
значения точек с коэффициентом*/
s21::full_scene_data s21::Model::GetSceneFromFile(std::string file_path) {
  return parser_->GetSceneFromFile(file_path);
}

/*Метод для поворота сцены (ox, oy, oz)
Принимает пару scene_data, содержащую
в себе точки и полигоны, и кодировку направления описанную в
../model/helpers/using.h в enum directions
Изменяет саму scene_data по адресу*/
s21::scene_data s21::Model::SpinSceneBy(scene_data& data, uint8_t direction) {
  spinner_->SpinSceneBy(data, direction);
  return data;
}

/*Метод для сдвига сцены
Принимает пару scene_data, содержащую
в себе точки и полигоны, и кодировку направления описанную в
../model/helpers/using.h в enum directions
Изменяет саму scene_data по адресу*/
s21::scene_data s21::Model::ShiftSceneTo(scene_data& data, uint8_t direction) {
  shifter_->ShiftSceneTo(data, direction);
  return data;
}
