// Copyright [2018] <Ligia Dolinta 311CD>
#include "./format_text.h"

char *justify_line(char *str, int width) {
    char *rez = NULL;
    char *sp = NULL;
    int present_space = 0;
    int extra_space = 0;
    int spaces = 0;
    int equal_space = 0;
    int i = 0;
    char **words;

    if (strlen(str) == 1 || (int)strlen(str) == width)
        return(str);


    str = trim(str);
    rez = (char *)malloc(sizeof(char) * width + 1);
    words = ft_split(str);
    while (str[i++])
        if (str[i] == ' ')
            present_space++;

    spaces = width -  (int)strlen(str);
    equal_space = (spaces + present_space) / present_space;

    sp = (char *)malloc(sizeof(char) * equal_space);
    for (i = 0; i < equal_space; i++)
        strcat(sp, " ");

    int j = 0;
    while (words[j++])
        continue;
    j--;

    i = 0;
    extra_space = spaces % present_space;
        while (i < j) {
        strcat(rez, words[i]);
        if (i == j - 1)
            break;
        strcat(rez, sp);
        if (extra_space > 0) {
            strcat(rez, " ");
            extra_space--;
        }
        i++;
    }
    rez[width - 1] = '\n';
    return(rez);
    free(rez);
}

char   **justify(text input, int s_line, int e_line) {
    char **ret;
    int max;
    int flag = 0;

    ret = (char **)malloc(sizeof(char *) * input.rows);
    for (int i = 0; i < input.rows; i++)
        ret[i] = (char *)malloc(sizeof(char) * 1000);
    max = max_line(input.text, input.rows);
    for (int i = 0; i < input.rows; i++) {
        if (i == s_line)
            flag = 1;
        if (i > e_line)
            flag = 0;
        if (flag) {
            if (strlen(input.text[i + 1]) > 1)
                strcpy(ret[i], justify_line(trim(input.text[i]), max));
            else
                strcpy(ret[i], trim(input.text[i]));
        } else {
            strcpy(ret[i], input.text[i]);
            }
    }
    return(ret);
}
