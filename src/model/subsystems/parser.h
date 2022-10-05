#ifndef SRC_MODEL_SUBSYSTEMS_PARSER_H_
#define SRC_MODEL_SUBSYSTEMS_PARSER_H_

#include <string>
#include <utility>
#include <fstream>
#include <iostream>
#include <vector>

#include "../helpers/using.h"

namespace s21 {
class Parser {
  public:
    using instance = Parser*;
    using parse_it = std::string::iterator;

  private:
    static Parser* p_parser_;
    scene_data data_;
    std::vector<double>* dots_ = &(data_.first);
    std::vector<int>* polygons_ = &(data_.second);
    double min_dot_val_;
    double max_dot_val_;

    Parser() {
      ;
    }
    ~Parser() {
      ;
    }
    Parser(const Parser&) = delete;
    Parser(Parser&&) = delete;
    Parser& operator=(Parser&) = delete;
    
  public:
    static instance GetInstance();
    full_scene_data GetSceneFromFile(const std::string file_path);
    

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
    int GetFCount_(parse_it start, parse_it end);
    std::pair<double, double> GetMinAndMax_();
  

};  // class Parser
}  // namespace s21

#endif  // SRC_MODEL_SUBSYSTEMS_PARSER_H_
