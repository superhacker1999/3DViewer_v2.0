#ifndef S21_IFACE_H
#define S21_IFACE_H

#include <QWidget>
#include <QFileDialog>

namespace s21 {
namespace Ui {
    class iface;
}

class iface : public QWidget {
  Q_OBJECT

  public:
    explicit iface(QWidget *parent = nullptr);
    ~iface();
  QString GetFilePath() {return filepath_; }
  void SetFilePathLabel(QString filepath);

  private:
    Ui::iface *ui;
    QString filepath_;
    QVector<QPushButton*> shift_buttons_;
    QVector<QPushButton*> spin_buttons_;

    void ConnectButtons_();

  private slots:
    void ChooseFile_();
    void ShiftScene_();
    void SpinScene_();
    void ZoomChange_();

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

};
} // namespace s21
#endif // S21_IFACE_H
