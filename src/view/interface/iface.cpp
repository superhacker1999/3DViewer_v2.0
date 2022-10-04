#include "iface.h"
#include "ui_iface.h"


s21::iface::iface(QWidget *parent) : QWidget(parent), ui(new s21::Ui::iface) {
  ui->setupUi(this);
  connect(ui->get_file_button, SIGNAL(clicked()), this, SLOT(ChooseFile_()));
}

s21::iface::~iface() {
  delete ui;
}

void s21::iface::ChooseFile_() {
  filepath_ = QFileDialog::getOpenFileName(0, "Выбрать файл", "", "*.obj");

  if (filepath_ == "") {
      ui->filepath_dots->setText("Выберите файл.");
  } else {
//      ui->filepath_dots->setText("Файл: " + filepath_ + "\nКоличество вершин: " + QString::number(ui->widget->dots_counter) + "\nКоличество ребер: " + QString::number(ui->widget->edges_counter / ui->widget->f_counter));
  }
  emit onFileChanged();
}

