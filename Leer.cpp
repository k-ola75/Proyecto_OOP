#include "Leer.h"

void Leer::leerValor(std::ifstream &entrada, int &intInput)
{
  intInput = 0;
  entrada >> intInput;
}
void Leer::leerValor(std::ifstream &entrada, std::string &strInput)
{
  strInput = "";
  entrada >> strInput; 
}

void Leer::leerLinea(std::ifstream &entrada, std::string &strInput)
{
  strInput = "";
  std::getline(entrada >> std::ws, strInput, '\n');
}