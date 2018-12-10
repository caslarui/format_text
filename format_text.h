#ifndef FORMAT_TEXT_H
# define FORMAT_TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char char_a[1000][1000];

typedef struct {
	char sp_char;
	int is_ordered;
	char list_type;
	int row_count;
	char ord_type;
}	list_t;

typedef struct word_t {
	const char *s;
	int len;
} *word;

typedef struct text_t {
	char **text;
	int rows;
}	text;

int max_line( char **str, int line_count);

text 	wrap_text(char *string, int max_line_length);
text 	parser(text input, char *str);
void 	wrap( char *out, char *str, int columns );
char 	*delete_space(char *str);
char 	**a_sort(char **str, int nb_lines);
char    **justify(text input, int s_line, int e_line);
char 	**z_sort(char **str, int nb_lines);
char 	**ord_list(list_t args, char** list, int s_line, int e_line);
char 	**ino_list(list_t args, char** list, int s_line, int e_line);
char 	**center_text(char **text, int s_line, int e_line, int row_count);
char 	**alignl_text(char **text, int s_line, int e_line, int row_count);
char 	**alignr_text(char **text, int s_line, int e_line, int row_count);
char	**ft_split(char *str);
char 	*trim(char *str);

#endif