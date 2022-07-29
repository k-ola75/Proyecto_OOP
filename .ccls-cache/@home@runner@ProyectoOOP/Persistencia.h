#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include <fstream>>

class Persistencia{
public:
  static void llenar(std::string texto, std::string nombreArchivo);
};

#endif