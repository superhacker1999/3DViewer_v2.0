#ifndef S21_RENDER_H
#define S21_RENDER_H

#define GL_SILENCE_DEPRECATION

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QColorDialog>
#include <QOpenGLFunctions>

#include "../../model/helpers/using.h"

namespace s21 {
class render : public QOpenGLWidget {
  public:
    render(QWidget *parent = nullptr);

  private:
    scene_data* data_;
    bool is_settings_loaded_ = false;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    double* dot_min_;
    double* dot_max_;


  public:
    void SetData(scene_data*, double* min, double* max);


};
} // namespace s21

#endif // S21_RENDER_H
