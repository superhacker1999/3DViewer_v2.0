#include "parser.h"

s21::Parser* s21::Parser::p_parser_ = nullptr;

s21::Parser::instance s21::Parser::GetInstance() {
  if (p_parser_ == nullptr)
    p_parser_ = new Parser();
  return p_parser_;
}

/*
Основной метод парсинга
Принимает путь к .obj файлу
Возвращает пару из векторов
точек и полигонов
*/
s21::Parser::scene_data s21::Parser::GetSceneFromFile(const std::string file_path) {
  std::ifstream file;
  file.open(file_path);
  if (!file) {
    std::cout<<"file does not exist\n";
  } else {
    ParseCycle_(file);
    OutPutData();
    file.close();
  }
  
  return data_;
}

/*
Основной цикл парсинга
Принимает путь к .obj файлу
Построчно парсит строки из файла
и заполняет векторы данными
*/
void s21::Parser::ParseCycle_(std::ifstream& file) {
  std::string buffer;
  while (!file.eof()) {
    getline(file, buffer);
    ParseLine_(buffer);
  }
  dots_->shrink_to_fit();
  polygons_->shrink_to_fit();
}

/*
Метод для парсинга строки приходящей
из основного цикла парсинга
*/
void s21::Parser::ParseLine_(std::string& string) {
    auto it = string.begin();
    auto it_end = string.end();
    if (*it == 'v' && *(it + 1) == ' ') {
      VProcessing_(it);
    } else if (*it == 'f' && *(it + 1) == ' ') {
      FProcessing_(it, it_end);
    }
}

/*
Метод обработки точек,
принимает итератор на строку из ParseLine
*/
void s21::Parser::VProcessing_(parse_it &iterator) {
  for (int i = 0; i < 3; i++)
    dots_->push_back(GetNextNumber_(iterator));
}

/*
Метод обработки полигонов,
принимает итераторы на начало и конец
строки из ParseLine
*/
void s21::Parser::FProcessing_(parse_it &start_it, parse_it& end_it) {
  int spaces_count = GetSpacesCount_(start_it, end_it);
  int number = 0, iterator = spaces_count;
  int first_number = 0;
  while (iterator > 0) {
    number = GetNextNumber_(start_it) - 1;
    if (iterator == spaces_count) {
      polygons_->push_back(number);
      first_number = number;
    } else if (iterator == 1) {
      polygons_->push_back(number);
      polygons_->push_back(number);
      polygons_->push_back(first_number);
    } else {
      polygons_->push_back(number);
      polygons_->push_back(number);
    }
    iterator--;
  }
}

double s21::Parser::GetNextNumber_(s21::Parser::parse_it &it) {
  std::string number;
  while (!IsNum_(*it)) {
    if (*it == '/')
      SkipSlashes_(it);
    else
      it++;
  }
  while (IsNum_(*it)) {
    number.push_back(*(it++));
  }
  return atof(number.c_str());
}

bool s21::Parser::IsNum_(char symbol) {
  return ((symbol >= '0' && symbol <= '9') || symbol == '-' || symbol == '.') ? true : false;
}

void s21::Parser::SkipSlashes_(parse_it &iterator) {
  while (*iterator != ' ')
    iterator++;
  iterator++;
}

void s21::Parser::OutPutData() {
  std::cout<<"Точки:\n";
  int i = 1;
  for (auto it = dots_->begin(); it != dots_->end(); it++, i++) {
    std::cout<<*it<<' ';
    if (i % 3 == 0)
      std::cout<<std::endl;
  }
  std::cout<<"Полигоны:\n";
  i = 1;
  for (auto it = polygons_->begin(); it != polygons_->end(); it++, i++) {
    std::cout<<*it<<' ';
    if (i % 6 == 0)
      std::cout<<std::endl;
  }
}

int s21::Parser::GetSpacesCount_(s21::Parser::parse_it start, s21::Parser::parse_it end) {
  int count = 0;
  for (; start != end; start++)
    if (*start == ' ')
      count++;
  return count;
}