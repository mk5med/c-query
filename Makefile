CC=gcc
CFLAGS=-I. -g
ODIR = obj
DEPS = main.h \
			lib/attribute_lib/attribute.h \
			lib/attribute_lib/attribute_parse.h lib/attribute_lib/attribute_print.h \
			lib/string_extensions/string_extensions.h

OBJ = $(ODIR)/lib/printAttributeTree.o $(ODIR)/lib/attribute.o \
			$(ODIR)/lib/createSubAttributeChain.o $(ODIR)/lib/readToken.o \
			$(ODIR)/lib/string_split.o

TARGET = c-query

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(ODIR)/lib/%.o: lib/attribute_lib/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(ODIR)/lib/%.o: lib/string_extensions/%.c $(DEPS)
	$(CC) -g -c -o $@ $< $(CFLAGS)

$(TARGET): $(ODIR)/main.o $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

.PHONY: clean

library:
	make
	ar rcs "$(TARGET).lib" $(OBJ)

clean:
	rm -rf $(ODIR)
	# You can now run 'make init'

init:
	mkdir obj
	mkdir obj/lib
	# You can now run 'make' or 'make clean'