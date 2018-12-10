#include "format_text.h"

int max_line( char **str, int line_count) {
    int i = 0;
    int max = strlen(str[0]);

    for (i = 1; i < line_count; i++){
        if ((int)strlen(str[i]) > max) {
            max = strlen(str[i]);
        }
    }
    return (max);
}

char *center_line( char *str, int width ){
    char *line = NULL;
    int space, i;
    char sp[2] = " ";
    if( (width - strlen(str)) % 2 == 0)
        space = (width - strlen(str)) / 2;
    else
        space = (width - strlen(str)) / 2 + 1;
    line = (char *)malloc(sizeof(char) * strlen(str) + space + 1);
    for ( i = 0; i < space; i++){
        strcat(line,sp);
    }
    // printf("%s\n",line);
    if(strlen(str) != 1)
        strcat(line,str);
    else
        return(str);
return(line);
    
}

char **center_text(char **text, int s_line, int e_line, int row_count) {
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
        if (e_line < i)
            flag = 0;
        if (flag == 1) {
            tmp_text[i] = center_line(text[i],max);
        }
        else
            strcpy(tmp_text[i], text[i]);
    }
    return(tmp_text);
}

// int main() {

//   char str[1000][1000]= {"Lorem ipsum", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer"
//                         , "elementum, ipsum sit amet vulputate semper, orci justo condimentum",
//                          "felis, eu lobortis metus quam ac mauris. Mauris sed pharetra leo."
//                          , "Morbi mollis nunc eu velit tincidunt ullamcorper. Vestibulum"};
//     printf("%d\n", max_line(str,4));
//     //printf("%s\n",str[1]);
//     for (int i = 0; i <= 4; i++)
//         printf("%s\n", center_line(str[i],max_line(str,4)));
//     return 0;
// }
