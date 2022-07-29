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
  int index = 0;
  vectDatos.resize(1048576);//preguntar Problema si no se "inicializa" un tamaño
  while(strDatos >> idx)
  {
    //vectDatos.assign(1,idx); //¿Usar iterador?
    vectDatos[index] = idx;
    ++index;
  }
  vectDatos.resize(index);
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
  objEst.resetResultado();
}

int Control::getMediciones()
{
  return numeroMediciones;
}