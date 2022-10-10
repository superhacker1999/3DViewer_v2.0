#ifndef S21_RENDER_H
#define S21_RENDER_H

#define GL_SILENCE_DEPRECATION

#include <QColorDialog>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>

#include "../../model/helpers/using.h"

namespace s21 {
class render : public QOpenGLWidget {
 public:
  render(QWidget* parent = nullptr);

 private:
  scene_data* data_;
  bool is_settings_loaded_ = false;
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;
  double* dot_min_;
  double* dot_max_;
  bool* is_line_striple_;
  int* line_width_;
  int* display_dots_;
  float* dots_size_;
  QColor* background_color_;
  QColor* lines_color_;
  QColor* dots_color_;

 public:
  void SetData(scene_data*, double*, double*, QColor*, QColor*, QColor*, bool*,
               int*, int*, float*);

 private:
  void ChangeLinesColor_();
  void ChangeBackgroundColor_();
  void ChooseLinesType_();
  void ChangeDots_();
};
}  // namespace s21

#endif  // S21_RENDER_H
