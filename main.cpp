#include "Control.h"
using namespace std;

int main(int argc, char* argv[]) {
  /*if (argc == 1)
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
  {*/
    Control objControl("entrada.txt");//argv[1]
    objControl.setMediciones();
    for(int idx = 0; idx < objControl.getMediciones(); ++idx)
    {
      objControl.setParametro();
      objControl.getParametro();
      objControl.setStrDatos();
      objControl.getStrDatos();
      objControl.toVector();
      objControl.getVector();
      objControl.calcularParametro();
      objControl.llamarPersistencia("salida.txt");//argv[2]
      objControl.reset();
    }
    return 0;
 // }
 /* else
  {
    cerr << "Error: Exceso de argumentos." << endl;
		exit(1);
  }*/
}

//https://stackoverflow.com/questions/17289324/assign-int-value-to-vector-using-iterator




