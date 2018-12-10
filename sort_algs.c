// Copyright [2018] <Ligia Dolinta 311CD>
#include "./format_text.h"

// void swap(char *xp,  char *yp) 
// { 
//      char temp;
//      temp = *xp; 
//     *xp = *yp; 
//     *yp = temp; 
// }

char **a_sort(char **str, int nb_lines) {
    int i, j;
    char *tmp;

    tmp = (char *)malloc(sizeof(char) * 1000);
    for (i = 0; i < nb_lines - 1; i++) {
        for (j = 0; j < nb_lines - i - 1; j++) {
            if (strcmp(str[j], str[j + 1]) > 0) {
                strcpy(tmp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], tmp);
            }
        }
    }
        return(str);
}

char **z_sort(char **str, int nb_lines) {
    int i, j;
    char *tmp;

    tmp = (char *)malloc(sizeof(char) * 1000);
    for (i = 0; i < nb_lines - 1; i++)
        for (j = 0; j < nb_lines - i - 1; j++) {
            if (strcmp(str[j], str[j + 1]) < 0) {
                strcpy(tmp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], tmp);
            }
        }
    return(str);
}
