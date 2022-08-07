#include "Control.h"

Control::Control(std::string nombre)
{
  archivoEntrada.open(nombre);
  parametro = "";
  numeroMediciones = 0;
}
Control::~Control()
{
  archivoEntrada.close();
}

void Control::setMediciones()
{
  Leer::leerValor(archivoEntrada, numeroMediciones);
}

void Control::setParametro()
{
  Leer::leerValor(archivoEntrada, parametro);
}

void Control::setStrDatos()
{
  std::string datos;
  Leer::leerLinea(archivoEntrada, datos);
  strDatos.str(datos);
}

void Control::toVector()
{
  int idx;
  while(strDatos >> idx)
  {
    vectDatos.push_back(idx);
  }
}

void Control::calcularParametro()
{
  if (parametro == "OA"){objEst.OA(vectDatos);}
  else if (parametro == "OD"){objEst.OD(vectDatos);}
  else if (parametro == "MN"){objEst.MN(vectDatos);}
  else if (parametro == "MY"){objEst.MY(vectDatos);}
  else if (parametro == "MO"){objEst.MO(vectDatos);}
  else if (parametro == "MD"){objEst.MD(vectDatos);}
  else if (parametro == "MA"){objEst.MA(vectDatos);}
}

void Control::llamarPersistencia(std::string nombre)
{
  Persistencia::llenar(objEst.getResultado(), nombre);
}

void Control::reset()
{
  parametro.clear();
  vectDatos.clear();
  strDatos.clear();
  objEst.resetResultado();
}

int Control::getMediciones()
{
  return numeroMediciones;
}

void Control::getVector()
{
  for (auto i:vectDatos)
  {
    std::cout<< i << std::endl;
  }
}

void Control::getStrDatos()
{
  std::cout << strDatos.str() << std::endl;
}

void Control::getParametro()
{
  std::cout << parametro << std::endl;
}