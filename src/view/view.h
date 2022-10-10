#ifndef S21_VIEW_H
#define S21_VIEW_H

#include <QMainWindow>

#include "../controller/controller.h"
#include "../model/helpers/using.h"
#include "interface/iface.h"
#include "render/render.h"

namespace s21 {
namespace Ui {
class view;
}

class view : public QMainWindow {
  Q_OBJECT

 public:
  view(QWidget *parent = nullptr);
  ~view();

 private:
  Ui::view *ui;
  Controller *controller_;
  scene_data data_;
  double dot_min_;
  double dot_max_;
  QColor background_color_ = QColor::fromRgbF(0.0f, 0.0f, 0.0f);
  QColor lines_color_ = QColor::fromRgbF(0.13f, 0.545f, 0.13f);
  QColor dots_color_ = QColor::fromRgbF(0.13f, 0.545f, 0.13f);
  int line_width_ = 1;
  bool is_line_stripple_ = false;
  int display_dots_ = 0;
  float dots_size_ = 0.0f;

  void ConnectButtons_();

 private slots:
  void SetSceneFromFile_();
  void XAdd_() { controller_->ShiftSceneTo(data_, kXPLUS); }
  void XSub_() { controller_->ShiftSceneTo(data_, kXMINUS); }
  void YAdd_() { controller_->ShiftSceneTo(data_, kYPLUS); }
  void YSub_() { controller_->ShiftSceneTo(data_, kYMINUS); }
  void ZAdd_() { controller_->ShiftSceneTo(data_, kZPLUS); }
  void ZSub_() { controller_->ShiftSceneTo(data_, kZMINUS); }
  void OXAdd_() { controller_->SpinSceneBy(data_, kOXPLUS); }
  void OXSub_() { controller_->SpinSceneBy(data_, kOXMINUS); }
  void OYAdd_() { controller_->SpinSceneBy(data_, kOYPLUS); }
  void OYSub_() { controller_->SpinSceneBy(data_, kOYMINUS); }
  void OZAdd_() { controller_->SpinSceneBy(data_, kOZPLUS); }
  void OZSub_() { controller_->SpinSceneBy(data_, kOZMINUS); }
  void ZoomIn_() { controller_->ShiftSceneTo(data_, kZOOMIN); }
  void ZoomOut_() { controller_->ShiftSceneTo(data_, kZOOMOUT); }
  void ChangeColor_();
  void ChangeLineSettings_();
  void ChangeDotsSettings_();
  void MakeScreenshot_();
};
}  // namespace s21
#endif  // S21_VIEW_H
