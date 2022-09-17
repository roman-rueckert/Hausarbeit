#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <funktionsgenerator.h>

int option;
char *datei;
int frequenz = 0;
int amplitude = 0;
int perioden = 0;
char *datei;


int main(int argc,char *argv[])
{
    while((option = getopt(argc, argv, "h v d: a: f: p:")) != -1)
    {
        switch(option)
        {
        case 'h':
            printf("Der Funktionsgenerator erzeugt Wertepaare einer Rechteckfunktion und gibt diese in eine Datei aus.\n");
            printf("Dazu müssen folgende Kommandozeilenparameter übergeben werden:\n");
            printf("-d /Pfad/zur/Datei/Dateiname\n");
            printf("-a (Amplitude in V)");
            printf("-f (Frequenz in Hz)\n");
            printf("-p (Anzahl der Perioden bzw. Rechteckssignale)\n");
            printf("-v (Verison und Author)\n"); 
            printf("-h (Für diese Hilfe)\n");
            break;
        case 'v':
            printf("Version 0.1\n");
            printf("Autor: Roman Rückert\n");
        case 'd':
            datei = optarg;
            break;
        case 'a':
            amplitude=atoi(optarg);
            printf("Amplitude: %d V \n", amplitude);
            break;
        case 'f':
	    frequenz=atoi(optarg);
            printf("Frequenz: %d Hz\n", frequenz);
            break;
        case 'p':
            perioden=atoi(optarg);
            printf("Anzahl der Perioden: %d \n", perioden);
            break;
        }
    }
    FILE *filepointer;
    filepointer = fopen(datei, "w");

    if (filepointer == NULL)
    {
        printf("Fehler beim öffnen der Datei: '%s'\n", datei);
        exit(-1);
    }




    if(fclose(filepointer) == EOF)
    {
        printf("Fehler beim schließen der Datei!\n");
        exit(-1);
    }
    return 0;
}
