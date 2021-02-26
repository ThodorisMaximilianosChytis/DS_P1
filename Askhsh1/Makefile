objects= dummy.o main.o

runprogram :$(objects)
	gcc -o runprogram $(objects)

dummy.o :dummy.c
	gcc -c dummy.c typedef.h functions.h

main.o :main.c
	gcc -c main.c typedef.h functions.h

clean  :
	rm runprogram $(objects) typedef.h.gch functions.h.gch

