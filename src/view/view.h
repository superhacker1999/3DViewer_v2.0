#ifndef S21_VIEW_H
#define S21_VIEW_H

#include <QMainWindow>
#include "../controller/controller.h"
#include "../model/helpers/using.h"
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
    double dot_min_;
    double dot_max_;

  private slots:
    void SetSceneFromFile_();

    void XAdd_();
    void XSub_();
    void YAdd_();
    void YSub_();
    void ZAdd_();
    void ZSub_();

    void OXAdd_();
    void OXSub_();
    void OYAdd_();
    void OYSub_();
    void OZAdd_();
    void OZSub_();

};
} // namespace s21
#endif // S21_VIEW_H
