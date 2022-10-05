#include "view.h"
#include "ui_view.h"

/*
Главный класс GUI
содержащий в себе два виджета
с UI и рендером (OpenGL)
*/

s21::view::view(QWidget *parent) : QMainWindow(parent) , ui(new s21::Ui::view) {
  ui->setupUi(this);
  controller_ = s21::Controller::GetInstance();

  full_scene_data full_data = controller_->GetDefaultScene();
  data_ = full_data.data;
  dot_min_ = full_data.min_and_max.first;
  dot_max_ = full_data.min_and_max.second;

  ui->render->SetData(&data_, &dot_min_, &dot_max_);

  connect(ui->iface, SIGNAL(onFileChanged()), this, SLOT(SetSceneFromFile_()));

  connect(ui->iface, SIGNAL(onXAdd()), this, SLOT(XAdd_()));
  connect(ui->iface, SIGNAL(onXSub()), this, SLOT(XSub_()));
  connect(ui->iface, SIGNAL(onYAdd()), this, SLOT(YAdd_()));
  connect(ui->iface, SIGNAL(onYSub()), this, SLOT(YSub_()));
  connect(ui->iface, SIGNAL(onZAdd()), this, SLOT(ZAdd_()));
  connect(ui->iface, SIGNAL(onZSub()), this, SLOT(ZSub_()));

  connect(ui->iface, SIGNAL(onOXAdd()), this, SLOT(OXAdd_()));
  connect(ui->iface, SIGNAL(onOXSub()), this, SLOT(OXSub_()));
  connect(ui->iface, SIGNAL(onOYAdd()), this, SLOT(OYAdd_()));
  connect(ui->iface, SIGNAL(onOYSub()), this, SLOT(OYSub_()));
  connect(ui->iface, SIGNAL(onOZAdd()), this, SLOT(OZAdd_()));
  connect(ui->iface, SIGNAL(onOZSub()), this, SLOT(OZSub_()));

}

s21::view::~view() {
  delete ui;
}

void s21::view::SetSceneFromFile_() {
  full_scene_data full_data = controller_->GetSceneFromFile(ui->iface->GetFilePath().toStdString());
  data_ = full_data.data;
  dot_min_ = full_data.min_and_max.first;
  dot_max_ = full_data.min_and_max.second;
}

void s21::view::XAdd_() {
  controller_->ShiftSceneTo(data_, kXPLUS);
}

void s21::view::XSub_() {
  controller_->ShiftSceneTo(data_, kXMINUS);
}

void s21::view::YAdd_() {
  controller_->ShiftSceneTo(data_, kYPLUS);
}

void s21::view::YSub_() {
  controller_->ShiftSceneTo(data_, kYMINUS);
}

void s21::view::ZAdd_() {
  controller_->ShiftSceneTo(data_, kZPLUS);
}

void s21::view::ZSub_() {
  controller_->ShiftSceneTo(data_, kZMINUS);
}

void s21::view::OXAdd_() {
  controller_->SpinSceneBy(data_, kOXPLUS);
}

void s21::view::OXSub_() {
  controller_->SpinSceneBy(data_, kOXMINUS);
}

void s21::view::OYAdd_() {
  controller_->SpinSceneBy(data_, kOYPLUS);
}

void s21::view::OYSub_() {
  controller_->SpinSceneBy(data_, kOYMINUS);
}

void s21::view::OZAdd_() {
  controller_->SpinSceneBy(data_, kOZPLUS);
}

void s21::view::OZSub_() {
  controller_->SpinSceneBy(data_, kOZMINUS);
}
