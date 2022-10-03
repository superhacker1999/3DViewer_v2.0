#ifndef S21_RENDER_H_
#define S21_RENDER_H_

#define GL_SILENCE_DEPRECATION

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QColorDialog>
#include <QOpenGLFunctions>
#include "../model/helpers/using.h"

namespace s21 {
class render : public QOpenGLWidget {
public:
  render(QWidget *parent = nullptr);
  void SetData();

};
} // namespace s21

#endif // S21_RENDER_H_
