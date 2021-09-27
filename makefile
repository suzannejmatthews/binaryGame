#make: main.c library/level_8.c library/level_8.h library/level_admin.c library/level_admin.h
#	gcc -o reverseGame main.c library/level_8.c library/level_admin.c

make: main.o level_admin.o level_8.o level_7.o level_6.o
	gcc main.o level_admin.o level_8.o level_7.o level_6.o -O1 -o reverseGame

main.o: main.c
	gcc -c main.c

level_admin.o: library/level_admin.c library/level_admin.h
	gcc -c library/level_admin.c

level_8.o: library/level_8.c library/level_8.h
	gcc -c library/level_8.c

level_7.o: library/level_7.c library/level_7.h
	gcc -c library/level_7.c

level_6.o: library/level_6.c library/level_6.h
	gcc -c library/level_6.c



clean:
	rm *.o reverseGame

