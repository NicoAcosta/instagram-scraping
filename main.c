#include "estructurasDeDatos.h"
#include "funcionesGenerales.h"
#include "funcionesArchivos.h"
#include "htmlAUsuario.h"

//#include "menu.h"

int main (int argc, char *argv[])
{
    usuario *user = init(argv[1]);

    mostrarUsuario(user);

    liberarMemoriaDeLista(user);

    return 0;

}