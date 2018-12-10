#include "format_text.h"

char *right(char *row, int width) {

    int spaces = 0;
    char *s_spaces=NULL;
    char *sp = " ";
    char *tmp_row = NULL;
    int row_s = (int)strlen(row);
    int j;

    if(row_s == 1)
        return(row);
    if (row_s < width){
        spaces = width - row_s;
        s_spaces = (char *)malloc(sizeof(char) * spaces);
        tmp_row = (char *)malloc(sizeof(char) * width);
        strcpy(tmp_row,row);
        for ( j = 0; j < spaces; j++){
            strcat(s_spaces, sp);
        }
        tmp_row = strcat(s_spaces,tmp_row);
    }
    else
        if ((int)strlen(row) == width)
            return(row);

    return (tmp_row);
    free(tmp_row);
}

char **alignr_text(char **text, int s_line, int e_line, int row_count) {
    char **tmp_text = NULL;
    int flag = 0;
    int max = max_line(text, row_count);

    tmp_text = (char **)malloc(sizeof(char *) * row_count);
    for (int i  = 0; i < row_count; i++)
        tmp_text[i] = (char *)malloc(sizeof(char) * 1000);

    for (int i = 0; i < row_count; i++)
    {
        if (s_line == i)
            flag = 1;
        if (e_line == i)
            flag = 0;
        if (flag == 1)
            strcpy(tmp_text[i],right(text[i],max));
        else
            strcpy(tmp_text[i], text[i]);
    }
    return(tmp_text);
}
