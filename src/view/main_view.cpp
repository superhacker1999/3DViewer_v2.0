#include "main_view.h"

s21::main_view::main_view() {
  controller_ = s21::Controller::GetInstance();
  // gonna add this method later
//  data_ = controller_->GetDefaultScene();
}

s21::main_view::~main_view() {
  ;
}

void s21::main_view::window_show() {
  window_.show();
}

s21::scene_data s21::main_view::GetData() {
  return data_;
}
