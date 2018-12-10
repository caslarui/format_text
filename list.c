#include "format_text.h"

char *list_operations(list_t args, char *string, char index) {
    char *tmp = NULL;
    char *c=NULL;

    c = (char *)malloc(sizeof(char) * 100);
    if (args.list_type == 'a' || args.list_type == 'A')
        sprintf(c,"%c",index);
    if (args.list_type == 'n')
        sprintf(c, "%d", index);
    strcat(c, &args.sp_char);
    tmp = (char *)malloc(sizeof(char) * (strlen(c) + strlen(string)));
    tmp = strcat(c, " ");
    strcat(tmp,string);
    return(tmp);      
    free(c);
}

char **ino_list(list_t args, char ** list, int s_line, int e_line) {
    char **tmp_list=NULL;
    int flag = 0;
    int index;

    tmp_list = (char **)malloc(sizeof(char *) * args.row_count);
    for (int i = 0; i < args.row_count; i++)
        tmp_list[i] = (char *)malloc(sizeof(char) * 1000);

    if (args.list_type == 'n')
        index = 1;
    if (args.list_type == 'a')
        index = 97;
    if (args.list_type == 'A')
        index = 65;
    for (int i = 0; i < args.row_count; i++) {
        if (i == s_line)
            flag = 1;
        if (i > e_line || i == args.row_count)
            flag = 0;
        if (flag) {
                strcpy(tmp_list[i], list_operations(args, list[i], index));
            index++;
        } else {
            if(strcmp(list[i],"\n") == 0)
                strcpy(tmp_list[i], "\n");
            else
                strcpy(tmp_list[i], trim(list[i]));
        }
    }
    return(tmp_list);
    free(tmp_list);
}

char **ord_list(list_t args, char **list, int s_line, int e_line) {
    char **tmp_list ;
    char **rez = NULL;
    int flag = 0;
    int index;
    int k = -1;
    int aux = e_line - s_line;

    rez = (char **)malloc(sizeof(char *) * args.row_count);
    for (int i = 0; i < args.row_count; i++)
        rez[i] = (char *)malloc(sizeof(char) * 1000);
    
    tmp_list = (char **)malloc(sizeof(char * ) * e_line - s_line + 1);
    for (int i = 0; i < aux + 1; i++)
        tmp_list[i] = (char *)malloc(sizeof(char) * 1000);
    if ( s_line == e_line) {
        strcpy(tmp_list[++k], list[s_line]);
        aux = 1;
    } else 
        for (int i = s_line; i < e_line; i++) {
            strcpy(tmp_list[++k], list[i]);
        }
    if(args.ord_type == 'a')
        tmp_list = a_sort(tmp_list, aux);
    if(args.ord_type == 'z')
        tmp_list = z_sort(tmp_list, aux);
    if (args.list_type == 'n')
        index = 1;
    if (args.list_type == 'a')
        index = 97;
    if (args.list_type == 'A')
        index = 65;
    // printf("%d | %d",s_line, e_line);
    k = -1;
    for (int i = 0; i < args.row_count; i++) {
        if (i == s_line)
            flag = 1;
        if (i > e_line)
            flag = 0;
        if (flag) {
            // printf("DA\n");
            strcpy(rez[i], list_operations(args, tmp_list[++k], index));
            index++;
        } else {
                strcpy(rez[i], trim(list[i]));
            if(strcmp(list[i], "\n") == 0)
                strcat(rez[i], "\n");
        }
    }
    return(rez);
    free(rez);
    free(tmp_list);
}
