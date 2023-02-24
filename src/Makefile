RANDOM := $(shell bash -c 'echo $$RANDOM')

make: gen main.o hint.o level_admin.o level_9.o level_8.o level_7.o level_6.o level_5.o level_4.o level_3.o level_2.o level_1.o level_0.o
	gcc main.o hint.o level_admin.o level_9.o level_8.o level_7.o level_6.o level_5.o level_4.o level_3.o level_2.o level_1.o level_0.o -O1 -o reverseGame

gen: library/
	cd library; python3 generator.py $(RANDOM)

main.o: main.c
	gcc -c main.c

hint.o: library/hint.c library/hint.h
	gcc -c library/hint.c

level_admin.o: library/level_admin.c library/level_admin.h
	gcc -c library/level_admin.c

level_9.o: library/level_9.c library/level_9.h
	gcc -c library/level_9.c

level_8.o: library/level_8.c library/level_8.h
	gcc -c library/level_8.c

level_7.o: library/level_7.c library/level_7.h
	gcc -c library/level_7.c

level_6.o: library/level_6.c library/level_6.h
	gcc -c library/level_6.c

level_5.o: library/level_5.c library/level_5.h
	gcc -c library/level_5.c

level_4.o: library/level_4.c library/level_4.h
	gcc -c library/level_4.c

level_3.o: library/level_3.c library/level_3.h
	gcc -c library/level_3.c

level_2.o: library/level_2.c library/level_2.h
	gcc -c library/level_2.c

level_1.o: library/level_1.c library/level_1.h
	gcc -c library/level_1.c

level_0.o: library/level_0.c library/level_0.h
	gcc -c library/level_0.c


clean:
	rm *.o reverseGame
