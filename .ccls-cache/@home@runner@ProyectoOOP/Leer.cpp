#include "Leer.h"

/**
 * Lee un valor de un archivo y lo almacena en una variable tipo int
 * @param entrada objeto tipo ifstream correspondiente al archivo de entrada
 * @param intInput variable int donde se almacena el valor leído
 */
void Leer::leerValor(std::ifstream &entrada, int &intInput)
{
  intInput = 0;
  entrada >> intInput;
}

/**
 * Lee un valor de un archivo y lo almacena en una variable tipo string
 * @param entrada objeto tipo ifstream correspondiente al archivo de entrada
 * @param strInput variable string donde se almacena el valor leído
 */
void Leer::leerValor(std::ifstream &entrada, std::string &strInput)
{
  strInput = "";
  entrada >> strInput; 
}

/**
 * Lee línea de un archivo y lo almacena en una variable tipo string
 * @param entrada objeto tipo ifstream correspondiente al archivo de entrada
 * @param strInput variable string donde se almacena la línea leída
 */
void Leer::leerLinea(std::ifstream &entrada, std::string &strInput)
{
  strInput = "";
  std::getline(entrada >> std::ws, strInput, '\n');
}