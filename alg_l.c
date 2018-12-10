// Copyright [2018] <Ligia Dolinta 311CD>
#include "./format_text.h"

char *left(char *row) {
    char *tmp_row;
    int row_s = strlen(row);
    int counter = 0;

    if (isspace(*row) && (strlen(row) != 1)) {
        while (isspace(*row) && *row) {
            counter++;
            row++;
        }
        tmp_row = (char *)malloc(sizeof(char) * (row_s - counter + 1));
        strcpy(tmp_row, row);
    } else {
        return(row);
        }
    return(tmp_row);
}

char **alignl_text(char **text, int s_line, int e_line, int row_count) {
    char **tmp_text = NULL;
    int flag = 0;

    tmp_text = (char **)malloc(sizeof(char *) * row_count);
    for (int i  = 0; i < row_count; i++)
        tmp_text[i] = (char *)malloc(sizeof(char) * 1000);

    for (int i = 0; i < row_count; i++) {
        if (s_line == i)
            flag = 1;
        if (e_line < i) {
            flag = 0;
        }
        if (flag == 1)
            strcpy(tmp_text[i], left(text[i]));
        else
            strcpy(tmp_text[i], text[i]);
    }
    return(tmp_text);
}