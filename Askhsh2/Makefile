objects= dldummy.o main.o

runprogram :$(objects)
	gcc -o runprogram $(objects)

dldummy.o :dldummy.c
	gcc -c dldummy.c dltypedef.h functions.h

main.o :main.c
	gcc -c main.c dltypedef.h functions.h

clean :
	rm runprogram $(objects) typedef.h.gch functions.h.gch

