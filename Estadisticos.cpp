#include "Estadisticos.h"

void Estadisticos::OA(std::vector<int> &vect)
{
  sort(vect.begin(), vect.end());
  for(int idx = 0; idx < vect.size(); ++idx)
  {
    if (idx != 0){resultado << ',';}
    resultado << vect[idx];
  }
}

void Estadisticos::OD(std::vector<int>& vect)
{
  sort(vect.begin(), vect.end(), std::greater<int>());
  for(int idx = 0; idx < vect.size(); ++idx)
  {
    if (idx != 0){resultado << ',';}
    resultado << vect[idx];
  }
}

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
  else{resultado << "N.A";}
}

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

std::string Estadisticos::getResultado()
{
  return resultado.str();
}

void Estadisticos::resetResultado()
{
  resultado.str(std::string());
  resultado.clear();
  //resultado.flush();
}