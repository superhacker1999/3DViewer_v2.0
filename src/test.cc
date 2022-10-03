#include "controller/controller.h"


int main() {
  s21::Controller* controller_ = s21::Controller::GetInstance();
  s21::Controller::scene_data data = controller_->GetSceneFromFile("/Users/padmemur/Desktop/3DViewer_v2_0/src/objects/mersedes.obj");
  std::cout<<std::endl<<data.first.size()<<"  "<<data.second.size();
  return 0;
}