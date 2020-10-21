#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void menu() {

    char tecla;

    while (1) {
        
        printf("\n\n\n\n\n---------------------------------------------------------------\n\n\n\n\n");
        printf("Presione la telca correspondiente a la opción deseada:\n\n");

        printf("1 - Reporte A\n");
        printf("2 - Reporte B\n");
        printf("3 - Reporte C\n");
        printf("4 - Salir\n\n\n");

        tecla = getc(stdin);

        switch (tecla)
        {
        case '1':
            reporteA();
            break;
    
        case '2':
            reporteB();
            break;

        case '3':
        //reporteC();
        break;

            case 27:
            exit(0);
            break;

        default:
            printf("Presione una tecla adecuada.");
            break;
        }

        sleep(1);
    }

}