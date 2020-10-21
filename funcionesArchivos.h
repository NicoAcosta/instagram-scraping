#include <stdio.h>
#include <string.h>
#include <stdbool.h>

FILE *popen(const char *command, const char *type);
int pclose(FILE *stream);

void descargarPagina(char *nombreDeUsuario){
    
    char cmd[200];
    strcpy(cmd, "wget ");
    strcat(cmd, "instagram.com/");
    strcat(cmd, nombreDeUsuario);
    strcat(cmd, " --no-check-certificate");
    
    FILE *pagina;
    pagina = popen(cmd,"r");
    pclose (pagina);

}

long tamanoDeArchivo (FILE *unArchivo) {

    int posicionActual = ftell (unArchivo);
    fseek (unArchivo, 0, SEEK_END);
    int largoDelArchivo = ftell (unArchivo);
    fseek (unArchivo, posicionActual, SEEK_SET);
    return largoDelArchivo;

}

void copiarNombreEn(FILE* archivo, char* stringDestino) {
    char linea[340];
    for (int i = 0; i < 8; i++) {
        fgets(linea, sizeof(linea), archivo);
    }
    char *tok =  strtok(linea, "(");
    strcpy(stringDestino, tok);
}


void copiarLineaInfo(FILE *archivo, char* stringDestino) {
    char linea[340] = "a";
    while (!strstr(linea, "Followers"))
        fgets(linea, sizeof(linea), archivo);
    strcpy(stringDestino, linea);
}

void copiarBioInfo(FILE *archivo, char* stringDestino) {
    char linea[500] = "a";
    while (!strstr(linea, "\"biography\":\""))
        fgets(linea, sizeof(linea), archivo);
    strcpy(stringDestino, linea);
}

/*
void copiarInfoEn(char *linea, char *campo, char *stringDestino) {
    int largo = strlen2(campo);

    char *posicion = strstr(linea, campo);
    char *data = *(posicion + largo + 1);
    

} 
*/















void irA(FILE *archivo, int posicion) {

    fseek(archivo, posicion, SEEK_SET);

}

bool finDeTabla (char *linea){

    char *comparacion = strstr (linea, "</table>");
    if (comparacion == NULL)
        return false;
    else
        return true;

}

bool encabezadoDeTabla (char *linea, char *encabezado){

    char *comparacion = strstr (linea, encabezado);
    if (comparacion == NULL)
        return false;
    else
        return true;

}

void irALaTabla(FILE* archivo, char *encabezado) {

    char linea[340] = "";
    while (!encabezadoDeTabla(linea, encabezado)) {
        fgets(linea, sizeof(linea), archivo);
    }
    fgets(linea, sizeof(linea), archivo);
    fgets(linea, sizeof(linea), archivo);

}