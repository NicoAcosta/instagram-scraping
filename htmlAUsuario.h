#include <stdlib.h>
#include <stdio.h>

char    delimitador[]       = " =<>\"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

usuario * HTML_A_Usuario (char *nombreDeUsuario) {

    FILE *archivo = fopen(nombreDeUsuario, "r");

    usuario *nodo = malloc(sizeof(usuario));
    char linea[600] = "";
    
    copiarNombreEn(archivo, nodo->nombre);

    strcpy(nodo->nombreDeUsuario, nombreDeUsuario);

    copiarLineaInfo(archivo, linea);

    char *token = strtok(linea, " <meta content=\"");
    nodo->seguidores = atoi(token);
    
    token = strtok(NULL, delimitador);
    token = strtok(NULL, delimitador);
    nodo->seguidos = atoi(token);

    token = strtok(NULL, delimitador);
    token = strtok(NULL, delimitador);
    nodo->publicaciones = atoi(token);

    copiarBioInfo(archivo, linea);

    token = strtok(linea, "\"biography\":\"");
    token = strtok(NULL, "\"");
    strcpy(nodo->descripcion, token);

    
    

    
    nodo->sgte = NULL;

    fclose(archivo);

    return nodo;

}

/*
usuario *tabla_HTML_A_Lista () {
    
    FILE* archivo = fopen(archivoHTML, "r");

    irALaTabla(archivo, encabezados);

    char linea[340];

    accion* lista = NULL;

    fgets(linea, sizeof(linea), archivo);
    lista = linea_HTML_A_Nodo(linea);
    fgets(linea, sizeof(linea), archivo);
    fgets(linea, sizeof(linea), archivo);

    accion* aux1 = lista;

    while (!finDeTabla(linea)) {
        
        accion *nuevo = malloc(sizeof(accion));
        
        fgets(linea, sizeof(linea), archivo);
        nuevo = linea_HTML_A_Nodo(linea);
        fgets(linea, sizeof(linea), archivo);
        fgets(linea, sizeof(linea), archivo);

        aux1->sgte = nuevo;
        aux1 = nuevo;

    }

    fclose(archivo);

    return lista;
}
*/

usuario * init (char *nombreDeUsuario){

    descargarPagina(nombreDeUsuario);
    
    usuario *nodo = HTML_A_Usuario(nombreDeUsuario);

    int del = remove(nombreDeUsuario);

    return nodo;
}