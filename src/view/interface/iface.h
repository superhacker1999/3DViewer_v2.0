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

  private:
    Ui::iface *ui;
    QString filepath_;

  private slots:
    void ChooseFile_();

  signals:
    void onFileChanged();

};
} // namespace s21
#endif // S21_IFACE_H
