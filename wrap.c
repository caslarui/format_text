#include "format_text.h"

static word make_word_list(const char *s, int *n)
{
	int max_n = 0;
	word words = 0;
 
	*n = 0;
	while (1) {
		while (*s && isspace(*s)) s++;
		if (!*s) break;
 
		if (*n >= max_n) {
			if (!(max_n *= 2)) max_n = 2;
			words = realloc(words, max_n * sizeof(*words));
		}
		words[*n].s = s;
		while (*s && !isspace(*s)) s++;
		words[*n].len = s - words[*n].s;
		(*n) ++;
	}
 
	return words;
}
 
static void greedy_wrap(word words, int count, int cols, int *breaks)
{
	int line, i, j;
 
	i = j = line = 0;
	while (1) {
		if (i == count) {
			breaks[j++] = i;
			break;
		}
 
		if (!line) {
			line = words[i++].len;
			continue;
		}
 
		if (line + words[i].len < cols) {
			line += words[i++].len + 1;
			continue;
		} else {
			breaks[j++] = i;
			line = 0;}
	}
	breaks[j++] = 0; 
}
 
 
static text save_wrap(word list, int count, int *breaks)
{
	text ret = {0,0};
	char *space = " ";
	int row = 0;
	int i, j;

	ret.text = (char **)malloc(sizeof(char *) * 1000);
	for (int i = 0; i < 1000; i++)
		ret.text[i] = (char *)malloc(sizeof(char) * 1000);

	for (i = j = 0; i < count && breaks[i]; i++) {
		// printf("BREAKS--%d ---------\n", breaks[i]);
		while (j < breaks[i]) {
		// printf("--------%d ---------\n", j);
			strncat(ret.text[row], list[j].s, list[j].len);
			if (j < breaks[i] - 1)
				strcat(ret.text[row], space);
			j++;
		}
		if 	(breaks[i]) row++;
	}
	ret.rows = row;
	ret.text[row] = NULL;
	return(ret);
}
 
text wrap_text(char *string, int max_line_length)
{
	text ret;
	int len, cols;
	word list = make_word_list(string, &len);
	int *breaks;
	
	breaks = malloc(sizeof(int) * (len + 1));
	
	cols = max_line_length;
	greedy_wrap(list, len, cols, breaks);
	ret = save_wrap(list, len, breaks);
	return ret;
}