#include "ui_show.h"
#include "ui_ui_show.h"

namespace s21 {

  ui_show::ui_show(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ui_show)
  {
    ui->setupUi(this);
  }

  ui_show::~ui_show()
  {
    delete ui;
  }


} // namespace s21
