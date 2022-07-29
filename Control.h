#ifndef CONTROL_H
#define CONTROL_H
#include "Estadisticos.h"
#include "Persistencia.h"
#include "Leer.h"
#include <map>

class Control
{
private:
  std::ifstream archivoEntrada;
  std::string parametro;
  std::istringstream strDatos;
  int numeroMediciones;
  std::vector<int> vectDatos;
  Estadisticos objEst;

public:
  Control(std::string nombre);
  ~Control();
  void setMediciones();
  void setParametro();
  void setStrDatos();
  void toVector();
  void calcularParametro();
  void llamarPersistencia(std::string nombre);
  void reset();
  int getMediciones();
  std::string getParametro(); //quizas innecesario
  std::string getStrDatos(); //quizas innecesario
  std::vector<int> getVector(); //quizas innecesario

};

#endif