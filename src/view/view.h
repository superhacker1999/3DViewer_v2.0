#ifndef S21_VIEW_H
#define S21_VIEW_H

#include <QMainWindow>
#include "../controller/controller.h"
#include "render/render.h"
#include "interface/iface.h"

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
    Controller* controller_;
    scene_data data_;

  private slots:
    void SetSceneFromFile_();

};
} // namespace s21
#endif // S21_VIEW_H
