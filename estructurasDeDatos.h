#include <stdio.h>
#include <stdlib.h>

typedef struct usuario usuario;

struct usuario {
    char    nombreDeUsuario[30];
    char    nombre[50];
    char    descripcion[200];
    int     seguidores;
    int     seguidos;
    int     publicaciones;
    usuario  *sgte;
};

void mostrarUsuario (usuario *usuario) {

        printf("Nombre de usuario:      %s\n",          usuario->nombreDeUsuario);
        printf("Nombre:                 %s\n",          usuario->nombre);
        printf("Descripción:            %s\n",          usuario->descripcion);
        printf("Seguidores:             %d\n",          usuario->seguidores);
        printf("Seguidos:               %d\n",          usuario->seguidos);
        printf("Publicaciones:          %d\n\n\n\n",    usuario->publicaciones);

}

void mostrarListaDeUsuario (usuario *lista) {
    usuario *aux = lista;
    while (aux) {
        mostrarUsuario(aux);
        aux = aux->sgte;
    }
}

void liberarMemoriaDeLista(usuario* lista) {

    usuario *aux1 = lista;
    usuario *aux2 = lista->sgte; 

    free(aux1);

    while (aux2) {
        aux1 = aux2;
        free(aux1);
        aux2 = aux2->sgte;
    }

}