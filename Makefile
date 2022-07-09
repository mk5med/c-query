CC=gcc
CFLAGS=-I.
DEPS = main.h\
			attribute_lib/attribute.h\
			attribute_lib/attribute_parse.h attribute_lib/attribute_print.h\
			string_extensions/string_extensions.h
OBJ = obj/main.o\
			obj/lib/printAttributeTree.o obj/lib/attribute.o\
			obj/lib/createSubAttributeChain.o obj/lib/readToken.o\
			obj/lib/string_split.o
ODIR = obj

obj/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

obj/lib/%.o: attribute_lib/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

obj/lib/%.o: string_extensions/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

c-query: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o

init:
	mkdir obj
	mkdir obj/lib