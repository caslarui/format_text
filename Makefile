CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
HEADERS = format_text.h
OBJECTS = tema2.o alg_l.o alg_r.o centerf.o list.o parser.o sort_algs.o split.o wrap.o justify.o
EXEC = format_text

.PHONY = default build clean

default: build

build: format_text

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@mkdir objs
	@mv *.o objs/

run: build
	@./$(EXEC) ${ARGS}

clean:
	@-rm -rf objs
	@-rm -f $(OBJECTS)
	@-rm -f $(EXEC)

re: clean build