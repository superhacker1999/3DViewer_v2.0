#include "main_view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  s21::main_view view;
  view.window_show();
  return a.exec();
}
