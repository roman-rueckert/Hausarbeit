all: staticlib
  gcc-10 -o funktionsgenerator.elf main.c -lm

staticlib:
	gcc-10 -c funktionsgenerator.c
	ar -crs static_lib_funktionsgenerator.a funktionsgenerator.o
	sudo cp funktionsgenerator.h /usr/include
	sudo cp static_lib_funktionsgenerator.a /usr/lib

