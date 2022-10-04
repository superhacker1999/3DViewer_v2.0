#include "view.h"
#include "ui_view.h"


s21::view::view(QWidget *parent) : QMainWindow(parent) , ui(new s21::Ui::view) {
  ui->setupUi(this);
  controller_ = s21::Controller::GetInstance();
  data_ = controller_->GetDefaultScene();
  ui->render->SetData(&data_);

  connect(ui->iface, SIGNAL(onFileChanged()), this, SLOT(SetSceneFromFile_()));
}

s21::view::~view() {
  delete ui;
}

void s21::view::SetSceneFromFile_() {
  data_ =  controller_->GetSceneFromFile(ui->iface->GetFilePath().toStdString());
}
