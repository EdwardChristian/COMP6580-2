.PHONY: all
all : runtime.a

runtime.a: array.o io.o list.o
	$(AR) r $@ $+

CFLAGS += -std=c11

clean :
	rm -f io.o array.o list.o runtime.a
