#include "view.h"
#include "ui_view.h"

/*Главный класс GUI
содержащий в себе два виджета
с UI и рендером (OpenGL)*/

s21::view::view(QWidget *parent) : QMainWindow(parent) , ui(new s21::Ui::view) {
  ui->setupUi(this);
  controller_ = s21::Controller::GetInstance();
  full_scene_data full_data = controller_->GetDefaultScene();
  data_ = full_data.data;
  dot_min_ = full_data.min_and_max.first;
  dot_max_ = full_data.min_and_max.second;
  ui->render->SetData(&data_, &dot_min_, &dot_max_, &background_color_, &lines_color_,
                      &dots_color_, &is_line_stripple_, &line_width_, &display_dots_, &dots_size_);
  ConnectButtons_();
}

s21::view::~view() {
  delete ui;
}

void s21::view::SetSceneFromFile_() {
  full_scene_data full_data = controller_->GetSceneFromFile(ui->iface->GetFilePath().toStdString());
  data_ = full_data.data;
  dot_min_ = full_data.min_and_max.first;
  dot_max_ = full_data.min_and_max.second;
  ui->iface->SetFilePathLabel("Файл: " + ui->iface->GetFilePath() + "\nКоличество вершин: " \
 + QString::number(data_.first.size()) + "\nКоличество ребер: " + QString::number(data_.second.size() / 3));
}

void s21::view::ChangeColor_() {
  background_color_ = ui->iface->GetBackgroundColor();
  lines_color_ = ui->iface->GetLinesColor();
  dots_color_ = ui->iface->GetDotsColor();
}

void s21::view::ChangeLineSettings_() {
  line_width_ = ui->iface->GetLineWidth();
  is_line_stripple_ = ui->iface->GetLineType();
}

void s21::view::ChangeDotsSettings_() {
  display_dots_ = ui->iface->GetDotType();
  dots_size_ = ui->iface->GetDotsSize();
}

void s21::view::MakeScreenshot_() {
  QString path = ui->iface->GetScreenshotPath();
  if (!path.isEmpty())
    ui->render->grab().save(path);
}

void s21::view::ConnectButtons_() {
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
  connect(ui->iface, SIGNAL(onZoomIn()), this, SLOT(ZoomIn_()));
  connect(ui->iface, SIGNAL(onZoomOut()), this, SLOT(ZoomOut_()));
  connect(ui->iface, SIGNAL(onColorChanged()), this, SLOT(ChangeColor_()));
  connect(ui->iface, SIGNAL(onLineSettingsChanged()), this, SLOT(ChangeLineSettings_()));
  connect(ui->iface, SIGNAL(onDotsSettingsChanged()), this, SLOT(ChangeDotsSettings_()));
  connect(ui->iface, SIGNAL(onScreenshotButtonclicked()), this, SLOT(MakeScreenshot_()));
}
