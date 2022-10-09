#include "render.h"

/*
Класс рендера наследуемый от OpenGL
занимается исключительно отображением сцены
*/

s21::render::render(QWidget *parent) : QOpenGLWidget(parent) {
  ;
}

void s21::render::SetData(s21::scene_data* data, double* min, double* max,
             QColor* back, QColor* line, QColor* dots,
                    bool* line_striple, int* line_width, int* display_dots, float* dots_size) {
  data_ = data;
  dot_min_ = min;
  dot_max_ = max;
  background_color_ = back;
  lines_color_ = line;
  dots_color_ = dots;
  is_settings_loaded_ = true;
  is_line_striple_ = line_striple;
  line_width_ = line_width;
  display_dots_ = display_dots;
  dots_size_ = dots_size;
}

void s21::render::ChangeLinesColor_() {
  float* colors = new float[3];
  if (lines_color_->isValid()) {
    lines_color_->getRgbF(&colors[0], &colors[1], &colors[2]);
    glColor3d(colors[0], colors[1], colors[2]);
  }
  delete []colors;
}

void s21::render::ChangeBackgroundColor_() {
  float* colors = new float[4];
  if (background_color_->isValid()) {
    background_color_->getRgbF(&colors[0], &colors[1], &colors[2], &colors[3]);
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(colors[0], colors[1], colors[2], colors[3]);
    f->glClear(GL_COLOR_BUFFER_BIT);
  }
  delete []colors;
}

void s21::render::ChooseLinesType_() {
  if (*is_line_striple_) {
    glLineStipple(1, 0x3F07);
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
}

void s21::render::ChangeDots_() {
  float* colors = new float[4];
  if (*display_dots_ > 0) {
    glPointSize(*dots_size_);
    if (*display_dots_ == 2)
      glEnable(GL_POINT_SMOOTH);
    if (dots_color_->isValid()) {
      dots_color_->getRgbF(&colors[0], &colors[1], &colors[2], &colors[3]);
      glColor3d(colors[0], colors[1], colors[2]);
    }
    glDrawElements(GL_POINTS, data_->second.size(), GL_UNSIGNED_INT, data_->second.data());
  }
  delete [] colors;
}

void s21::render::initializeGL() {
  if (is_settings_loaded_) {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-*(dot_max_), *dot_max_, -*(dot_max_), *dot_max_, *dot_max_, -*(dot_max_));
    glLineWidth(*line_width_);
  }
}

void s21::render::resizeGL(int w, int h) {
  if (is_settings_loaded_)
    glViewport(0, 0, w, h);
}

void s21::render::paintGL() {
  if (is_settings_loaded_) {
      //back color
      ChangeBackgroundColor_();

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-*(dot_max_), *dot_max_, -*(dot_max_), *dot_max_, *dot_max_, -*(dot_max_));
      glBegin(GL_DEPTH_TEST);
      glEnableClientState(GL_VERTEX_ARRAY);

      //lines
      ChangeLinesColor_();
      glVertexPointer(3, GL_DOUBLE, 0, data_->first.data());
      ChooseLinesType_();
      glLineWidth(*line_width_);
      glDrawElements(GL_LINES, data_->second.size(), GL_UNSIGNED_INT, data_->second.data());

      //dots
      ChangeDots_();

      glDisableClientState(GL_VERTEX_ARRAY);
      glEnd();
    }
  update();
}
