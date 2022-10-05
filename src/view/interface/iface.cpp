#include "iface.h"
#include "ui_iface.h"

/*
Класс интерфейса
Обрабатывает нажатие на кнопки
*/

s21::iface::iface(QWidget *parent) : QWidget(parent), ui(new s21::Ui::iface) {
  ui->setupUi(this);

  shift_buttons_ = {
    ui->x_add, ui->x_sub, ui->y_add,
    ui->y_sub, ui->z_add, ui->z_sub
  };

  spin_buttons_ = {
    ui->x_rot_add, ui->x_rot_sub, ui->y_rot_add,
    ui->y_rot_sub, ui->z_rot_add, ui->z_rot_sub
  };

  ConnectButtons_();
}

s21::iface::~iface() {
  delete ui;
}

void s21::iface::ChooseFile_() {
  filepath_ = QFileDialog::getOpenFileName(0, "Выбрать файл", "", "*.obj");

  if (filepath_ == "") {
      ui->filepath_dots->setText("Выберите файл.");
  } else {
//      ui->filepath_dots->setText("Файл: " + filepath_ + "\nКоличество вершин: " + \
//      QString::number(ui->widget->dots_counter) + "\nКоличество ребер: " + QString::number(ui->widget->edges_counter / ui->widget->f_counter));
    emit onFileChanged();
    }

}

void s21::iface::ShiftScene_() {
  QPushButton* button = (QPushButton*)sender();
  if (button == ui->x_add) {
      emit onXAdd();
      ui->x_value->setText(QString::number(ui->x_value->text().toInt() + 1));
  } else if (button == ui->x_sub) {
      emit onXSub();
      ui->x_value->setText(QString::number(ui->x_value->text().toInt() - 1));
  } else if (button == ui->y_add) {
      emit onYAdd();
      ui->y_value->setText(QString::number(ui->y_value->text().toInt() + 1));
  } else if (button == ui->y_sub) {
      emit onYSub();
      ui->y_value->setText(QString::number(ui->y_value->text().toInt() - 1));
  } else if (button == ui->z_add) {
      emit onZAdd();
      ui->z_value->setText(QString::number(ui->z_value->text().toInt() + 1));
  } else {
      emit onZSub();
      ui->z_value->setText(QString::number(ui->z_value->text().toInt() - 1));
  }
}

void s21::iface::SpinScene_() {
  QPushButton* button = (QPushButton*)sender();
  if (button == ui->x_rot_add) {
      emit onOXAdd();
      ui->x_rot_value->setText(QString::number(ui->x_rot_value->text().toInt() + 1));
  } else if (button == ui->x_rot_sub) {
      emit onOXSub();
      ui->x_rot_value->setText(QString::number(ui->x_rot_value->text().toInt() - 1));
  } else if (button == ui->y_rot_add) {
      emit onOYAdd();
      ui->y_rot_value->setText(QString::number(ui->y_rot_value->text().toInt() + 1));
  } else if (button == ui->y_rot_sub) {
      emit onOYSub();
      ui->y_rot_value->setText(QString::number(ui->y_rot_value->text().toInt() - 1));
  } else if (button == ui->z_rot_add) {
      emit onOZAdd();
      ui->z_rot_value->setText(QString::number(ui->z_rot_value->text().toInt() + 1));
  } else {
      emit onOZSub();
      ui->z_rot_value->setText(QString::number(ui->z_rot_value->text().toInt() - 1));
  }
}

void s21::iface::ConnectButtons_() {
  connect(ui->get_file_button, SIGNAL(clicked()), this, SLOT(ChooseFile_()));

  for (auto it = shift_buttons_.begin(); it != shift_buttons_.end(); it++)
      connect(*it, SIGNAL(clicked()), this, SLOT(ShiftScene_()));

  for (auto it = spin_buttons_.begin(); it != spin_buttons_.end(); it++)
      connect(*it, SIGNAL(clicked()), this, SLOT(SpinScene_()));
}
