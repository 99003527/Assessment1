BUILD=a.out
OBJS=test.o Src/mystring.o  Src/bitmask.o Src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/Inc
LDFLAGS=-lmystring -lmyutils -lmasking
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libmystring.a libmyutils.a libmasking.a
    gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} 
libMystring.a:src/mystring.o 
    ar rc $@ $^
libMyutils.a:src/myutils.o 
    ar rc $@ $^
libBitmask.a:src/bitmask.o 
    ar rc $@ $^
%.o:src/%.c Inc/%.h

test.o: test.c Inc/*.h

test:
    ./sall.out
