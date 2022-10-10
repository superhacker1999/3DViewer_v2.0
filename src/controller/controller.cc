#include "controller.h"

/*Класс контроллера вызываемый из главного класса View
Используется паттерн проектирования singletone
Вызывает необходимые методы из главного класса Model*/

s21::Controller* s21::Controller::p_controller_ = nullptr;

/*Метод для получения экземпляра класса*/
s21::Controller::instance s21::Controller::GetInstance() {
  if (p_controller_ == nullptr) p_controller_ = new Controller();
  return p_controller_;
}

/*Метод для получения точек и полигонов
из файла
Принимает путь к файлу
Возвращает экземпляр структуры full_scene_data
Содержащий в себе пару из векторов с точками и полигонами
и пару <double, double> содержащую в себе макс. и мин. точки
для правильного определения области определения сцены*/
s21::full_scene_data s21::Controller::GetSceneFromFile(std::string file_path) {
  return model_->GetSceneFromFile(file_path);
}

/*Метод для получения точек и полигонов
стандартной сцены (куб)
Возвращает экземпляр структуры full_scene_data
Содержащий в себе пару из векторов с точками и полигонами
и пару <double, double> содержащую в себе макс. и мин. точки
для правильного определения области определения сцены*/
s21::full_scene_data s21::Controller::GetDefaultScene() {
  return model_->GetDefaultScene();
}

/*Метод для сдвига сцены
Принимает пару scene_data, содержащую
в себе точки и полигоны, и кодировку направления описанную в
../model/helpers/using.h в enum directions
Изменяет саму scene_data по адресу*/
void s21::Controller::ShiftSceneTo(scene_data& data, uint8_t direction) {
  model_->ShiftSceneTo(data, direction);
}

/*Метод для поворота сцены (ox, oy, oz)
Принимает пару scene_data, содержащую
в себе точки и полигоны, и кодировку направления описанную в
../model/helpers/using.h в enum directions
Изменяет саму scene_data по адресу*/
void s21::Controller::SpinSceneBy(scene_data& data, uint8_t direction) {
  model_->SpinSceneBy(data, direction);
}
