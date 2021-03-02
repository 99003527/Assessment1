BUILD=a.out
OBJS=test.o Src/mystring.o  Src/bitmask.o Src/myutils.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/inc
LDFLAGS=-lmystring -lmyutils -lmasking
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libmystring.a libmyutils.a libbitmask.a
    gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} -static
libMystring.a:Src/mystring.o 
    ar rc $@ $^
libMyutils.a:Src/myutils.o 
    ar rc $@ $^
libBitmask.a:Src/bitmask.o 
    ar rc $@ $^
%.o:Src/%.c Inc/%.h

test.o: test.c Inc/*.h

test:
    ./sall.out

clean:
    rm -rf *.a *.o Src/*.o ${TARGET}
