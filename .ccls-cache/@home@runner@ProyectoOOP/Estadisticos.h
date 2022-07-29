#ifndef ESTADISTICOS_H
#define ESTADISTICOS_H
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>


class Estadisticos{
private:
  std::ostringstream resultado;

public:
  void OA(std::vector<int> &vect);
  void OD(std::vector<int>& vect);
  void MN(std::vector<int>& vect);
  void MY(std::vector<int>& vect);
  void MO(std::vector<int>& vect);
  void MD(std::vector<int>& vect);
  void MA(std::vector<int>& vect);
  std::string getResultado();
  void resetResultado();
  
};



#endif