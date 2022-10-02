#ifndef SRC_MODEL_FACADE_MODEL_CC_
#define SRC_MODEL_FACADE_MODEL_CC_
#include <utility>
#include <vector>
/* 
This class has the only one instance
so that we use the singletone pattern
*/

namespace s21 {
class Model {
  public:
    // using matrix = 
    using instance = Model*;
    using scene_data = std::pair<std::vector<double>, std::vector<int>>;

  private:
    static Model* p_model_;
    // static || net?
    // Parser* parser_;
    // Shifter* shifter_;
    // Spinner* spinner_;

    Model();
    Model(const Model&) = delete;
    Model(Model&&) = delete;
    Model& operator=(Model&) = delete;
    ~Model() {}
  public:
    static instance GetInstance() {
      if (p_model_ == nullptr)
        p_model_ = new Model();
      return p_model_;
    }
    scene_data GetDefaultScene();
};
}  // namespace s21
#endif  // SRC_MODEL_FACADE_MODEL_CC_