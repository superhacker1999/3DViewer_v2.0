#include "render.h"

/*
Класс рендера наследуемый от OpenGL
занимается исключительно отображением сцены
*/

s21::render::render(QWidget *parent) : QOpenGLWidget(parent) {
  ;
}

void s21::render::SetData(s21::scene_data* data, double* min, double* max) {
  data_ = data;
  dot_min_ = min;
  dot_max_ = max;
  is_settings_loaded_ = true;
}

void s21::render::initializeGL() {
  if (is_settings_loaded_) {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-*(dot_max_), *dot_max_, -*(dot_max_), *dot_max_, *dot_max_, -*(dot_max_));
    glLineWidth(1);
  }
}

void s21::render::resizeGL(int w, int h) {
  if (is_settings_loaded_)
    glViewport(0, 0, w, h);
}

void s21::render::paintGL() {
  if (is_settings_loaded_) {
      //back color
      QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
      f->glClearColor(255, 0, 0, 1);
      f->glClear(GL_COLOR_BUFFER_BIT);

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-*(dot_max_), *dot_max_, -*(dot_max_), *dot_max_, *dot_max_, -*(dot_max_));
      glBegin(GL_DEPTH_TEST);
      glEnableClientState(GL_VERTEX_ARRAY);

      //lines color
      glColor3d(255, 255, 255);

      glVertexPointer(3, GL_DOUBLE, 0, data_->first.data());
      glLineWidth(2);
      glDrawElements(GL_LINES, data_->second.size(), GL_UNSIGNED_INT, data_->second.data());
      glDisableClientState(GL_VERTEX_ARRAY);
      glEnd();
    }
  update();
}
