application_static: staticlib 
	gcc-10 main.c -l_funktionsgenerator -o funktionsgenerator.elf -lm

staticlib:
	gcc-10 funktionsgenerator.c -c
	ar -crs funktionsgenerator.a funktionsgenerator.o
	sudo cp funktionsgenerator.h /usr/include
	sudo cp funktionsgenerator.a /usr/lib
