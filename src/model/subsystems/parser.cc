#include "parser.h"

/*
Класс парсинга вызываемый из главного фасадного класса Model
Используется паттерн проектирования singletone
Парсит файл .obj и подготавливает данные для
рендера
*/

s21::Parser* s21::Parser::p_parser_ = nullptr;

/*
Метод для получения экземпляра класса
*/
s21::Parser::instance s21::Parser::GetInstance() {
  if (p_parser_ == nullptr) p_parser_ = new Parser();
  return p_parser_;
}

/*
Основной метод парсинга
Принимает путь к .obj файлу
возвращает данные о точках, полигонах и мин. макс.
значения точек с коэффициентом
*/
s21::full_scene_data s21::Parser::GetSceneFromFile(
    const std::string file_path) {
  std::ifstream file;
  file.open(file_path);
  if (!file) {
    std::cout << "file does not exist\n";
  } else {
    data_.first.clear();
    data_.second.clear();
    ParseCycle_(file);
    //  OutPutData();
    file.close();
  }
  auto min_and_max = GetMinAndMax_();
  full_scene_data data = {data_, min_and_max};
  return data;
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
отсюда вызываются методы обработки
V строк и F строк
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
закидывает в вектор три точки найденные в строке
*/
void s21::Parser::VProcessing_(parse_it& iterator) {
  for (int i = 0; i < 3; i++) dots_->push_back(GetNextNumber_(iterator));
}

/*
Метод обработки полигонов,
принимает итераторы на начало и конец
строки из ParseLine
закидывает индексы точек, которые нужно соединить в полигон
в вектор, предварительно вычитая из каждого индекса единицу
и редактируя индексы точек в верной последовательности,
которую переваривает OpenGL
f 1 2 3 4 превращается в
  0 1 1 2 2 3 3 0
*/
void s21::Parser::FProcessing_(parse_it& start_it, parse_it& end_it) {
  int f_count = GetFCount_(start_it, end_it);
  int number = 0, iterator = f_count;
  int first_number = 0;
  while (iterator > 0) {
    number = GetNextNumber_(start_it) - 1;
    if (iterator == f_count) {
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

/*
Метод для получения числа из строки
Принимает указатель на итератор парсера
вовзвращает найденное число
*/
double s21::Parser::GetNextNumber_(parse_it& it) {
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

/*
Метод для определения символа как число
принимает char (разыменование итератора парсера)
вовзращает true - число, false - другой символ
*/
bool s21::Parser::IsNum_(char symbol) {
  return ((symbol >= '0' && symbol <= '9') || symbol == '-' || symbol == '.')
             ? true
             : false;
}

/*
Метод для перемещения итератора
при встрече слэшей
например:
v 1/2/2 3/3/1 4/3/1
*/
void s21::Parser::SkipSlashes_(parse_it& iterator) {
  while (*iterator != ' ') iterator++;
  iterator++;
}

void s21::Parser::OutPutData() {
  std::cout << "Точки:\n";
  int i = 1;
  for (auto it = dots_->begin(); it != dots_->end(); it++, i++) {
    std::cout << *it << ' ';
    if (i % 3 == 0) std::cout << std::endl;
  }
  std::cout << "Полигоны:\n";
  i = 1;
  for (auto it = polygons_->begin(); it != polygons_->end(); it++, i++) {
    std::cout << *it << ' ';
    if (i % 6 == 0) std::cout << std::endl;
  }
}

/*
Метод для определения
кол-ва чисел в строке f
так как полигоны могут быть
из трех либо четырех точек
*/
int s21::Parser::GetFCount_(s21::Parser::parse_it start,
                            s21::Parser::parse_it end) {
  int count = 0;
  for (; start != end; start++) {
    if (*start == ' ' && IsNum_(*(start + 1))) count++;
  }
  return count;
}

/*
Метод для определения
максимальных и минимальных точек
для корректного отображения сцены
*/
std::pair<double, double> s21::Parser::GetMinAndMax_() {
  max_dot_val_ = min_dot_val_ = data_.first.at(0);
  for (auto it = data_.first.begin(); it != data_.first.end(); it++) {
    if (*it > max_dot_val_) max_dot_val_ = *it;
    if (*it < min_dot_val_) min_dot_val_ = *it;
  }
  min_dot_val_ *= 1.4;
  max_dot_val_ *= 1.4;
  return {min_dot_val_, max_dot_val_};
}
