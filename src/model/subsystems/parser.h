#ifndef SRC_MODEL_SUBSYSTEMS_PARSER_H_
#define SRC_MODEL_SUBSYSTEMS_PARSER_H_

#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <vector>

namespace s21 {
class Parser {
  public:
    using instance = Parser*;
    using scene_data = std::pair<std::vector<double>, std::vector<int>>;
    using parse_it = std::string::iterator;

  private:
    static Parser* p_parser_;
    scene_data data_;
    std::vector<double>* dots_ = &(data_.first);
    std::vector<int>* polygons_ = &(data_.second);

  private:
    Parser() {}
    // Parser(const Parser&) = default;
    // Parser(Parser&&) = default;
    // Parser& operator=(Parser&) = default;
    
  public:
    static instance GetInstance();
    scene_data GetSceneFromFile(const std::string file_path);
    ~Parser() { 
      delete p_parser_;
    }

  private:
    // trash
    void OutPutData();

    void ParseCycle_(std::ifstream& file);
    void ParseLine_(std::string& string);
    double GetNextNumber_(parse_it &iterator);
    bool IsNum_(char symbol);
    void SkipSlashes_(parse_it &iterator);
    void VProcessing_(parse_it &iterator);
    void FProcessing_(parse_it &start_it, parse_it &end_it);
    int GetSpacesCount_(parse_it start, parse_it end);
  

};  // class Parser
}  // namespace s21

#endif  // SRC_MODEL_SUBSYSTEMS_PARSER_H_