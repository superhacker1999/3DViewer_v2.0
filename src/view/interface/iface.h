#ifndef S21_IFACE_H
#define S21_IFACE_H

#include <QColorDialog>
#include <QDialog>
#include <QFileDialog>
#include <QWidget>

#include "ui_iface.h"

namespace s21 {
namespace Ui {
class iface;
}

class iface : public QWidget {
  Q_OBJECT

 private:
  Ui::iface *ui;
  QString filepath_;
  QVector<QPushButton *> shift_buttons_;
  QVector<QPushButton *> spin_buttons_;
  QColor background_color_;
  QColor lines_color_;
  QColor dots_color_;
  QString screenshot_path_;

 public:
  explicit iface(QWidget *parent = nullptr);
  ~iface();
  QString GetFilePath() { return filepath_; }
  void SetFilePathLabel(QString filepath);
  QColor GetBackgroundColor() { return background_color_; }
  QColor GetLinesColor() { return lines_color_; }
  QColor GetDotsColor() { return dots_color_; }
  bool GetLineType() {
    return ui->line_type->currentText() == "пунктирная" ? true : false;
  }
  int GetLineWidth() { return ui->line_thickness->value(); }
  int GetDotType() {
    return ui->tops_type->currentText() == "отсутствуют"  ? 0
           : ui->tops_type->currentText() == "квадратные" ? 1
                                                          : 2;
  }
  float GetDotsSize() { return ui->tops_size->value(); }
  QString GetScreenshotPath() { return screenshot_path_; }

 private:
  void ConnectButtons_();
  void BringLabelsToZero_();

 private slots:
  void ChooseFile_();
  void ShiftScene_();
  void SpinScene_();
  void ZoomChange_();
  void ChangeColor_();
  void ChangeLineType_();
  void ChangeLineWidth_();
  void ChangeDotsType_();
  void ChangeDotsSize_();
  void MakeScreenshot_();

 signals:
  void onFileChanged();
  void onXAdd();
  void onXSub();
  void onYAdd();
  void onYSub();
  void onZAdd();
  void onZSub();
  void onOXAdd();
  void onOXSub();
  void onOYAdd();
  void onOYSub();
  void onOZAdd();
  void onOZSub();
  void onZoomIn();
  void onZoomOut();
  void onColorChanged();
  void onLineSettingsChanged();
  void onDotsSettingsChanged();
  void onScreenshotButtonclicked();
};
}  // namespace s21
#endif  // S21_IFACE_H
