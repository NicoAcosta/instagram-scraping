#include <stdbool.h>
#include <string.h>


int strlen2 (char array[]) {
    int i = 0;
    while (array[i] != '\0')
        i += 1;
    return i;
}

bool esNumeroPuntoComaOMenos (char c) {
    return  (   c == '1'  ||  c == '2'  ||  c == '3'  ||    c == '4'  ||  c == '5'  ||
                c == '6'  ||  c == '7'  ||  c == '8'  ||    c == '9'  ||  c == '0'  ||
                c == '-'  ||  c == '.'  ||  c == ','   );

}

bool stringsIguales (char *str1, char * str2) {
    int largo = strlen2(str1);
    for (int i = 0; i < largo; i++) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}