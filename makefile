a.out:		HW4.o
		gcc -o a.out HW2.o

HW4.o:		HW4.c
		gcc -c HW2.c

clean:
		rm *.o
		rm a.out
