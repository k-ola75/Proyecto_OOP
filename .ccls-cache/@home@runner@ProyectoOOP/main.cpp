#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Leer.h"
#include "Estadisticos.h"
#include "Control.h"
using namespace std;

int main(int argc, char* argv[]) {
  if (argc == 1)
  {
    cerr << "Error: Ingresar nombres de archivos de entrada y salida separados por espacios (e.g. entrada.txt salida.txt)" << endl;
		exit(1);
	}
  else if (argc == 2)
  {
    cerr << "Error: Ingresar nombre del archivo de salida." << endl;
		exit(1);
	}
  else if(argc > 2 && argc < 4)
  {
    Control objControl(argv[1]);
    objControl.setMediciones();
    for(int idx = 0; idx < objControl.getMediciones(); ++idx)
    {
      objControl.setParametro();
      objControl.setStrDatos();
      objControl.toVector();
      objControl.calcularParametro();
      objControl.llamarPersistencia(argv[2]);
      objControl.reset();
    }
    return 0;
  }
  else
  {
    cerr << "Error: Exceso de argumentos." << endl;
		exit(1);
  }
}




