#include "Estadisticos.h"

/**
 * Ordena datos de un vector en orden ascendente
 * @param vect vector que contiene los datos a ordenar
 */
void Estadisticos::OA(std::vector<int> &vect)
{
  sort(vect.begin(), vect.end());
  for(int idx = 0; idx < vect.size(); ++idx)
  {
    if (idx != 0){resultado << ',';}
    resultado << vect[idx];
  }
}

/**
 * Ordena datos de un vector en orden descendente
 * @param vect vector que contiene los datos a ordenar
 */
void Estadisticos::OD(std::vector<int>& vect)
{
  sort(vect.begin(), vect.end(), std::greater<int>());
  for(int idx = 0; idx < vect.size(); ++idx)
  {
    if (idx != 0){resultado << ',';}
    resultado << vect[idx];
  }
}

/**
 * Calcula valor mínimo de datos contenidos en un vector
 * @param vect vector que contiene los datos
 */
void Estadisticos::MN(std::vector<int>& vect)
{
  int index = 0;
  int minIndex;
  int min = *std::min_element(vect.begin(), vect.end());
  for(auto idx:vect)
  {
    if(idx == min){minIndex = index;}
    ++index;
  }
  resultado << "Valor minimo: " << min << ", Posicion: " << minIndex;
}

/**
 * Calcula valor máximo de datos contenidos en un vector
 * @param vect vector que contiene los datos
 */
void Estadisticos::MY(std::vector<int>& vect)
{
  int index = 0;
  int maxIndex;
  int max = *std::max_element(vect.begin(), vect.end());

  for(auto idx:vect)
  {
    if(idx == max){maxIndex = index;}
    ++index;
  }
  resultado << "Valor maximo: " << max << ", Posicion: " << maxIndex;
}

/**
 * Calcula la moda de datos contenidos en un vector
 * @param vect vector que contiene los datos
 */
void Estadisticos::MO(std::vector<int>& vect)
{
  int freq;
  int newFreq;
  int moda;
  sort(vect.begin(), vect.end());
  for(auto i: vect)
  {
    newFreq = count(vect.begin(), vect.end(), i);
    if (freq < newFreq){freq = newFreq; moda = i;}
    if(freq == 1){moda = 0;}
  }
  if(moda != 0)
  {
  resultado << "Moda: " << moda;
  }
  else{resultado << "Moda: N.A";}
}

/**
 * Calcula mediana de datos contenidos en un vector
 * @param vect vector que contiene los datos
 */
void Estadisticos::MD(std::vector<int>& vect)
{
  double mediana;
  int index1;
  int index2;

  sort(vect.begin(), vect.end());
  if(vect.size()%2 != 0)
  {
    index1 = ((vect.size()+1)/2)-1;
    mediana = vect[index1];
  }
  else
  {
    index1 =  ((vect.size()+1)/2);
    index2 =  ((vect.size()+1)/2)-1;
    mediana = ((double)vect[index1]+(double)vect[index2])/(double)2;
  }
  resultado << "Mediana: " << mediana;
}

/**
 * Calcula media de datos contenidos en un vector
 * @param vect vector que contiene los datos
 */
void Estadisticos::MA(std::vector<int>& vect)
{
  int idy = 0;
  for(auto i:vect)
  {
    idy += i;
  }
  std::cout << idy << std::endl;
  double media = (double)idy/(double)vect.size();
  resultado << "Media: " << media;
}

/**
 * Retorna cadena de texto de atributo de dato "resultado"
 */
std::string Estadisticos::getResultado()
{
  return resultado.str();
}

/**
 * Borra el contenido del atributo "resultado" y limpia todas las banderas de error.
 */
void Estadisticos::resetResultado()
{
  resultado.str(std::string());
  resultado.clear();
  resultado.flush();
}