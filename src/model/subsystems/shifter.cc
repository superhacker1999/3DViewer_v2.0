#include "shifter.h"

s21::Shifter* s21::Shifter::p_shifter_ = nullptr;

s21::Shifter::instance s21::Shifter::GetInstance() {
  if (p_shifter_ == nullptr)
    p_shifter_ = new Shifter();
  return p_shifter_;
}

void s21::Shifter::ShiftSceneTo(scene_data& data, uint8_t direction, double shift_size) {
  dots_ = &(data.first);
  int start = direction == kX ? 0 : direction == kY ? 1 : 2;
  for (int i = start; i < dots_->size() - start; i+=2)
    dots_->at(i) = dots_->at(i) + shift_size;
}