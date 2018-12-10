// Copyright [2018] <Ligia Dolinta 311CD>
#include "./format_text.h"

static int ft_toupper(int c) {
    if (97 <= c && c <= 122)
        return (c - 32);
    return (c);
}

char **parse_arg(char *str) {
    int k = 0;
    const char s[2] = ",";
    char *token;
    char **ret = NULL;

    token = (char *)malloc(sizeof(char) * 1000);
    token = strtok(str, s);

    ret = (char **)malloc(sizeof(char *) * 20);
    for (int i = 0; i < 20; i++)
        ret[i] = (char *)malloc(sizeof(char) * 1000);
    while (token != NULL) {
        strcpy(ret[k++], token);
        token = strtok(NULL, s);
    }
    ret[k] = NULL;
    return(ret);
}

text parser(text input, char *str) {
    int count = 1;
    char **tmp = NULL;
    text ret_text;
    int s_line, e_line;
    list_t params;
    char **args;

    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] == ',')
            count++;
    }

    ret_text.rows = input.rows;
    ret_text.text = (char **)malloc(sizeof(char *) * 1000);
    for (int i = 0; i < 1000; i++) {
        ret_text.text[i] = (char *)malloc(sizeof(char) * 1000);
    }

    for (int i = 0; i < ret_text.rows; i++)
        strcpy(ret_text.text[i], input.text[i]);

    args = (char **)malloc(sizeof(char *) * count);
    for (int i = 0; i < count; i++) {
        args[i] = (char *)malloc(sizeof(char) * 20);
    }

    tmp = (char **)malloc(sizeof(char *) * 6);
    for (int i = 0; i < 6; i++)
        tmp[i] = (char *)malloc(sizeof(char) * 5);

    args = parse_arg(str);
    s_line = 0;
    e_line = ret_text.rows;
    for (int i = 0; i < count; i++) {
        if (i > 10) {
            printf("Too many operations! Only the first 10 will be applied.\n");
            break;
        }
        tmp = ft_split(args[i]);
        int j = 0;

        while (tmp[j++])
            continue;

        tmp[j] = NULL;

        if (ft_toupper(tmp[0][0]) == 'I') {
            params.is_ordered = 0;
            params.list_type = tmp[1][0];
            params.sp_char = tmp[2][0];
            params.ord_type = 0;
            params.row_count = ret_text.rows;
            if (tmp[3] && isdigit(tmp[3][0]))
                s_line = atoi(tmp[3]);
            if (tmp[4] && isdigit(tmp[4][0]))
                e_line = atoi(tmp[4]);
            else
                e_line = ret_text.rows;
            ret_text.text = ino_list(params, ret_text.text, s_line, e_line);
        } else if (ft_toupper(tmp[0][0]) == 'O') {
            params.is_ordered = 1;
            params.list_type = tmp[1][0];
            params.sp_char = tmp[2][0];
            params.ord_type = tmp[3][0];
            params.row_count = ret_text.rows;
            if (tmp[4] && isdigit(tmp[4][0])) {
                s_line = atoi(tmp[4]);
            }
            if (tmp[5] && isdigit(tmp[5][0]))
                e_line = atoi(tmp[5]);
            else
                e_line = ret_text.rows;
            ret_text.text = ord_list(params, ret_text.text, s_line, e_line);
        } else if (ft_toupper(tmp[0][0]) == 'W') {
            int max_line_length;
            if (isdigit(tmp[1][0])) {
                max_line_length = atoi(tmp[1]);
            }
            char *string = NULL;
            text wrap;
            char res[1000][1000];
            int row = 0;
            string = (char *)malloc(sizeof(char) * 1000);
            wrap.text = (char **)malloc(sizeof(char *) * 1000);
            for (int i = 0; i < 1000; i++) {
                wrap.text[i] = (char *)malloc(sizeof(char) * 1000);
            }
            for (int i = 0; i < ret_text.rows; i++) {
                if (strlen(ret_text.text[i]) > 1) {
                    strcat(string, ret_text.text[i]);
                }
                if (strlen(ret_text.text[i]) == 1 || i == (ret_text.rows - 1)) {
                    wrap = wrap_text(string, max_line_length);
                    strcpy(string, "\0");
                    for (int j = 0; j < wrap.rows; j++) {
                        strcat(res[row++], wrap.text[j]);
                        strcat(res[row], "\n");
                    }
                    wrap.text = NULL;
                    strcat(res[row], "\n");
                    }
            }
            ret_text.rows = row;

            for (int i = 0; i < row; i++) {
                strcpy(ret_text.text[i], res[i]);
            }
            strcat(ret_text.text[row - 1], "\n");
        } else if (ft_toupper(tmp[0][0]) == 'C') {
            if (tmp[1] && isdigit(tmp[1][0])) {
                s_line = atoi(tmp[1]);
            }
            if (tmp[2] && isdigit(tmp[2][0])) {
                e_line = atoi(tmp[2]);
            } else {
                e_line = ret_text.rows;
            }
            ret_text.text = center_text(ret_text.text, s_line, e_line, \
                                                     ret_text.rows);
        } else if (ft_toupper(tmp[0][0]) == 'L') {
            if (tmp[1] && isdigit(tmp[1][0]))
                s_line = atoi(tmp[1]);
            if (tmp[2] && isdigit(tmp[2][0]))
                e_line = atoi(tmp[2]);
            else
                e_line = ret_text.rows;
            ret_text.text = alignl_text(ret_text.text, s_line, e_line, \
                                                    ret_text.rows);
        } else if (ft_toupper(tmp[0][0]) == 'R') {
            if (tmp[1] && isdigit(tmp[1][0]))
                s_line = atoi(tmp[1]);
            if (tmp[2] && isdigit(tmp[2][0]))
                e_line = atoi(tmp[2]);
            else
                e_line = ret_text.rows;
            ret_text.text = alignr_text(ret_text.text, s_line, e_line, \
                                                    ret_text.rows);
        } else if (ft_toupper(tmp[0][0]) == 'J') {
            if (tmp[1] && isdigit(tmp[1][0]))
                s_line = atoi(tmp[1]);
            if (tmp[2] && isdigit(tmp[2][0]))
                e_line = atoi(tmp[2]);
            else
                e_line = ret_text.rows;
            ret_text.text = justify(ret_text, s_line, e_line);
        }
    }
    return(ret_text);
}
