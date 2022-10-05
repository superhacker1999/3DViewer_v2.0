#include "shifter.h"

s21::Shifter* s21::Shifter::p_shifter_ = nullptr;

s21::Shifter::instance s21::Shifter::GetInstance() {
  if (p_shifter_ == nullptr)
    p_shifter_ = new Shifter();
  return p_shifter_;
}

void s21::Shifter::ShiftSceneTo(scene_data& data, uint8_t direction) {
  dots_ = &(data.first);
  double shift_size = GetShiftSize_(direction);
  size_t start = GetStartPos_(direction);
  for (size_t i = start; i < dots_->size(); i+=3)
    dots_->at(i) = dots_->at(i) + shift_size;
}

double s21::Shifter::GetShiftSize_(uint8_t direction) {
  double min = dots_->at(0);
  double max = dots_->at(0);
  for (auto it = dots_->begin(); it != dots_->end(); it++) {
    if (*it > max) max = *it;
    if (*it < min) min = *it;
  }
  double result = 0.05f * fabs(max - min);
  if (direction == kXMINUS || direction ==  kYMINUS || direction == kZMINUS)
    result *= -1;
  return result;
}

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
