// Copyright [2018] <Ligia Dolinta 311CD>
#include "./format_text.h"

char *delete_space(char *str) {
    char **words = NULL;
    char *ret = NULL;
    int i = 0;

    words = ft_split(str);
    ret = (char *)malloc(sizeof(char) * 1000);
    while (words[i]) {
        strcat(ret, words[i]);
        if(words[i + 1] == NULL)
            break;
        strcat(ret, " ");
        i++;
    }
    i = 0;
    while (ret[i])
        i++;
    ret[i] = '\n';
    return(ret);
}

static int count_words(char *str) {
    int count;

    count = 0;
    while (*str) {
        while (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
            str++;
        if (*str && *str != ' ' && *str != '\n' && *str != '\t') {
            count++;
            while (*str && *str != ' ' && *str != '\n' && *str != '\t')
                str++;
        }
    }
    return (count);
}

static char *malloc_word(char *str) {
    char *word;
    int i;

    i = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    i = 0;
    while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char **ft_split(char *str) {
    int words;
    char **tab;
    int i;

    words = count_words(str);
    tab = (char **)malloc(sizeof(char*) * (words + 1));
    i = 0;
    while (*str) {
        while (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
            str++;
        if (*str && *str != ' ' && *str != '\n' && *str != '\t') {
            tab[i] = malloc_word(str);
            i++;
            while (*str && *str != ' ' && *str != '\n' && *str != '\t')
                str++;
        }
    }
    tab[i] = NULL;
    return (tab);
}
char *trim(char *str) {
    char *end;

    if (*str == 10)
        return(str);
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    end[1] = '\n';
    return (str);
}
