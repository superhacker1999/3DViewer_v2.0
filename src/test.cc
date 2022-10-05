#include "controller/controller.h"
#include "model/helpers/using.h"
#include <iostream>

int main() {
  s21::Controller* controller_ = s21::Controller::GetInstance();
  s21::scene_data data = controller_->GetSceneFromFile("/Users/padmemur/Desktop/3DViewer_v2_0/src/objects/airplane.obj");
  // controller_->SpinSceneBy(data, s21::kOXPLUS);
  //   std::cout<<"Точки:\n";
  // int i = 1;
  // for (auto it = data.first.begin(); it != data.first.end(); it++, i++) {
  //   std::cout<<*it<<' ';
  //   if (i % 3 == 0)
  //     std::cout<<std::endl;
  // }
  // std::cout<<"Полигоны:\n";
  // i = 1;
  // for (auto it = data.second.begin(); it != data.second.end(); it++, i++) {
  //   std::cout<<*it<<' ';
  //   if (i % 8 == 0)
  //     std::cout<<std::endl;
  // }
  return 0;
}
