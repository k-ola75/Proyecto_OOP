#include "Persistencia.h"

/**
 * Almacena texto en un archivo manteniendo la persistencia.
 * @param texto Cadena de caracteres a almacenar.
 * @param nombreArchivo nombre del archivo que almacenara el texto.
 */
  void Persistencia::llenar(std::string texto, std::string nombreArchivo)
{
    std::ofstream archivoSalida;
    archivoSalida.open(nombreArchivo, std::ofstream::app);
    archivoSalida << texto << std::endl;
    archivoSalida.close();
}