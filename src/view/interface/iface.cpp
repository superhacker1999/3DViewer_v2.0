#include "iface.h"

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
    BringLabelsToZero_();
    emit onFileChanged();
  }
}

void s21::iface::SetFilePathLabel(QString filepath) {
  ui->filepath_dots->setText(filepath);
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
      ui->x_rot_value->setText(QString::number(ui->x_rot_value->text().toInt() + 1));
      emit onOXAdd();
  } else if (button == ui->x_rot_sub) {
      ui->x_rot_value->setText(QString::number(ui->x_rot_value->text().toInt() - 1));
      emit onOXSub();
  } else if (button == ui->y_rot_add) {
      ui->y_rot_value->setText(QString::number(ui->y_rot_value->text().toInt() + 1));
      emit onOYAdd();
  } else if (button == ui->y_rot_sub) {
      ui->y_rot_value->setText(QString::number(ui->y_rot_value->text().toInt() - 1));
      emit onOYSub();
  } else if (button == ui->z_rot_add) {
      ui->z_rot_value->setText(QString::number(ui->z_rot_value->text().toInt() + 1));
      emit onOZAdd();
  } else {
      ui->z_rot_value->setText(QString::number(ui->z_rot_value->text().toInt() - 1));
      emit onOZSub();
  }
}

void s21::iface::ZoomChange_() {
  QPushButton* button = (QPushButton*)sender();
  if (button == ui->zoom_add) {
      ui->zoom_value->setText(QString::number(ui->zoom_value->text().toInt() + 10));
      emit onZoomIn();
  } else {
      ui->zoom_value->setText(QString::number(ui->zoom_value->text().toInt() - 10));
      emit onZoomOut();
    }
}

void s21::iface::ConnectButtons_() {
  connect(ui->get_file_button, SIGNAL(clicked()), this, SLOT(ChooseFile_()));
  connect(ui->zoom_add, SIGNAL(clicked()), this, SLOT(ZoomChange_()));
  connect(ui->zoom_sub, SIGNAL(clicked()), this, SLOT(ZoomChange_()));
  connect(ui->back_colour, SIGNAL(clicked()), this, SLOT(ChangeColor_()));
  connect(ui->lines_colour, SIGNAL(clicked()), this, SLOT(ChangeColor_()));
  connect(ui->tops_colour, SIGNAL(clicked()), this, SLOT(ChangeColor_()));
  connect(ui->line_type, SIGNAL(currentTextChanged(QString)), this, SLOT(ChangeLineType_()));
  connect(ui->line_thickness, SIGNAL(valueChanged(int)), this, SLOT(ChangeLineWidth_()));
  connect(ui->tops_type, SIGNAL(currentTextChanged(QString)), this, SLOT(ChangeDotsType_()));
  connect(ui->tops_size, SIGNAL(valueChanged(int)), this, SLOT(ChangeDotsSize_()));
  connect(ui->get_screen, SIGNAL(clicked()), this, SLOT(MakeScreenshot_()));
  for (auto it = shift_buttons_.begin(); it != shift_buttons_.end(); it++)
      connect(*it, SIGNAL(clicked()), this, SLOT(ShiftScene_()));
  for (auto it = spin_buttons_.begin(); it != spin_buttons_.end(); it++)
      connect(*it, SIGNAL(clicked()), this, SLOT(SpinScene_()));
}

void s21::iface::ChangeColor_() {
  QPushButton *button = (QPushButton *)sender();
  if (button == ui->lines_colour) {
      lines_color_ = QColorDialog::getColor(Qt::red, this, tr("colors"));
  } else if (button == ui->back_colour) {
      background_color_ = QColorDialog::getColor(Qt::red, this, tr("colors"));
  } else {
      dots_color_ = QColorDialog::getColor(Qt::red, this, tr("colors"));
  }
  emit onColorChanged();
}

void s21::iface::ChangeLineType_() {
  emit onLineSettingsChanged();
}

void s21::iface::ChangeLineWidth_() {
  emit onLineSettingsChanged();
}

void s21::iface::ChangeDotsType_() {
  emit onDotsSettingsChanged();
}

void s21::iface::ChangeDotsSize_() {
  emit onDotsSettingsChanged();
}

void s21::iface::MakeScreenshot_() {
  QString format;
  if (ui->format->currentText() == ".jpeg")
    format = "*.jpeg";
  else
    format = "*.bmp";
  screenshot_path_ = QFileDialog::getSaveFileName(0, "Сохранить файл как", "", format);
  emit onScreenshotButtonclicked();
}

void s21::iface::BringLabelsToZero_() {
  ui->x_value->setText("0");
  ui->y_value->setText("0");
  ui->z_value->setText("0");
  ui->x_rot_value->setText("0");
  ui->y_rot_value->setText("0");
  ui->z_rot_value->setText("0");
  ui->zoom_value->setText("0");
}
