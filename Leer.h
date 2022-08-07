#ifndef LEER_H
#define LEER_H
#include <fstream>
#include <string>
//#include <sstream>
//#include <vector>
//#include <iostream>

class Leer
{
public:
  static void leerValor(std::ifstream &entrada, int &intInput);
  static void leerValor(std::ifstream &entrada, std::string &strInput);
  static void leerLinea(std::ifstream &entrada, std::string &strInput);
};

#endif