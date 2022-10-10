#include "shifter.h"

/*
Класс сдвига вызываемый из фасадного класса Model
Используется паттерн проектирования singletone
сдвигает сцену по оси X, Y, Z
*/

s21::Shifter* s21::Shifter::p_shifter_ = nullptr;

/*
Метод для получения экземпляра класса
*/
s21::Shifter::instance s21::Shifter::GetInstance() {
  if (p_shifter_ == nullptr) p_shifter_ = new Shifter();
  return p_shifter_;
}

/*
Метод для сдвига сцены
Принимает пару scene_data, содержащую
в себе точки и полигоны, и кодировку направления описанную в
../model/helpers/using.h в enum directions
Изменяет саму scene_data по адресу
*/
void s21::Shifter::ShiftSceneTo(scene_data& data, uint8_t direction) {
  dots_ = &(data.first);
  if (direction == kZOOMIN || direction == kZOOMOUT) {
    ZoomChange_(direction);
  } else {
    double shift_size = GetShiftSize_(direction);
    size_t start = GetStartPos_(direction);
    for (size_t i = start; i < dots_->size(); i += 3)
      dots_->at(i) = dots_->at(i) + shift_size;
  }
}

/*
Метод для определения
размера сдвига
принимает кодировку направления
возвращает размер сдвига
*/
double s21::Shifter::GetShiftSize_(uint8_t direction) {
  double min = dots_->at(0);
  double max = dots_->at(0);
  for (auto it = dots_->begin(); it != dots_->end(); it++) {
    if (*it > max) max = *it;
    if (*it < min) min = *it;
  }
  double result = 0.05f * fabs(max - min);
  if (direction == kXMINUS || direction == kYMINUS || direction == kZMINUS)
    result *= -1;
  return result;
}

/*
Вспомогательный метод возвращающий
индекс для старта цикла изменения
данных с учетом сдвига
*/
size_t s21::Shifter::GetStartPos_(uint8_t direction) {
  size_t start_pos;
  if (direction == kXMINUS || direction == kXPLUS)
    start_pos = 0;
  else if (direction == kYMINUS || direction == kYPLUS)
    start_pos = 1;
  else
    start_pos = 2;
  return start_pos;
}

void s21::Shifter::ZoomChange_(uint8_t direction) {
  double zoom_percent = direction == kZOOMIN ? 1.1f : 0.9f;
  for (auto it = dots_->begin(); it != dots_->end(); it++)
    *it = *it * zoom_percent;
}
