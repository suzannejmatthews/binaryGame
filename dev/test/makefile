PY_CFLAGS  := $(shell python3.7-config --cflags)
PY_LDFLAGS := $(shell python3.7-config --ldflags)

make: wrapper.o
	gcc wrapper.o $(PY_LDFLAGS) -o call

wrapper.o: wrapper.c
	gcc wrapper.c -c $(PY_CFLAGS) -fPIC
