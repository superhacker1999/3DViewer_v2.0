#include "model/facade/model.h"
#include "model/subsystems/parser.h"


int main() {
  s21::Model* model_ = s21::Model::GetInstance();
  s21::Model::scene_data data = model_->GetSceneFromFile("/Users/padmemur/Desktop/3DViewer_v2_0/src/objects/mersedes.obj");
  std::cout<<std::endl<<data.first.size()<<"  "<<data.second.size();
  model_ = s21::Model::GetInstance();
  return 0;
}