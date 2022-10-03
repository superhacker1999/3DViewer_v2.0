#ifndef S21_MAIN_VIEW_H_
#define S21_MAIN_VIEW_H_
#include "ui_show.h"
#include "render.h"
#include "../controller/controller.h"
namespace s21 {
class main_view {

private:
  ui_show window_;
  render *render_;
  Controller* controller_;
  scene_data data_;

public:
  main_view();
  ~main_view();
  void window_show();
  scene_data GetData();

};
} // namespace s21

#endif // S21_MAIN_VIEW_H_
