#include "format_text.h"

char *paragraf (char *row, int indent_length){
    char *tmp = NULL;
    int row_w = strlen(row);
    char *s_spaces = NULL;
    char *sp = " ";
    int i, j;

    s_spaces = (char *)malloc(sizeof(char) * indent_length);
    tmp = (char *)malloc(sizeof(char) * (row_w + indent_length));

    for ( j = 0; j < indent_length; j++){
            strcat(s_spaces, sp);
    }
    for (i = 0; i < row_w; i++) {
                 tmp = strcat(s_spaces,tmp);
               // insert a '\0' in the output buffer;
    }
    return(tmp);
    free(tmp);
   
}
char **paragraf_txt (char **text, int s_line, int e_line, int row_count, int indent_length ){

     char **tmp_text = NULL;
     int flag = 0;

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
            if (text[i] == '\n')
                strcpy(tmp_text[i],paragraf(text[i],indent_length));
        else
            strcpy(tmp_text[i], text[i]);
    }
    return(tmp_text);


}

int main() {
    char string[1000]= {"elit. Vestibulum posuere, ipsum et eleifend\nVestibulum posuere, ipsum et eleifend\n\nVestibulum posuere, ipsum et eleifend."};
    char **str = NULL;
    char **ret = NULL;
    int i, j;
    str = (char **)malloc(sizeof(char *) * 1000);
            for (int i = 0; i < 1000; i++) {
                str[i] = (char *)malloc(sizeof(char) * 1000);
            }

    strcpy(str[0],string);
    ret = (char **)malloc(sizeof(char *) * 1000);
   
            for (int j = 0; j < 1000; j++) {
                ret[j] = (char *)malloc(sizeof(char) * 1000);
                
            }

             ret = paragraf_txt(str,0,5,5,3);
             for (int j = 0; j < 1000; j++) {
            
                 printf("%s\n",ret[j]);
            }
   

    return(0);
}

