#include "model/facade/model.h"
#include "model/subsystems/parser.h"

int main() {
  s21::Model* model_ = new s21::Model();
  auto data =  model_->GetSceneFromFile("/Users/padmemur/Desktop/3DViewer_v2_0/src/objects/CUB.obj");
  delete model_;
  // model_ = s21::Model::GetInstance();
  // s21::Model::scene_data data = model_->GetSceneFromFile("/Users/padmemur/Desktop/3DViewer_v2_0/src/objects/CUB.obj");

  // s21::Parser* parser_;
  // parser_ = s21::Parser::GetInstance();
  // s21::Parser::scene_data data = parser_->GetSceneFromFile("/Users/padmemur/Desktop/3DViewer_v2_0/src/objects/CUB.obj");
  return 0;
}