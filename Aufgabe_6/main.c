#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

void merge(int array[], int l, int m, int r)
{
    int i, j, k;
    //Größe der beiden temporären Array fetslgen
    int n1 = m - l + 1;
    int n2 = r - m;
    // temporäre Array erstellen
    int left[n1], right[n2];

    //Erste Hälfte der Werte aus dem Array in erstes temporäres Array (left) schreiben
    for (i = 0; i < n1; i++)
    {
        left[i] = array[l + i];
    }
    //Zweite Hälfte der Werte aus dem Array in zweites temporäres Array (right) schreiben
    for (j = 0; j < n2; j++)
    {
        right[j] = array[m + 1 + j];
    }
    // Schleifenzähler wieder auf 0 setzen
    i = 0;
    j = 0;
    k = l;

    // Schleife wiederholen solange beide Arrays noch Zahlen enthalten
    while (i < n1 && j < n2)
    {
        //Sortieren
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // Den Rest kopieren
    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int l, int r)
{
    printf("l: %d\n", l);
    printf("r: %d\n", r);
    // Ende der Rekursion erreicht wenn l = r
    if (l < r)
    {
        // Die Mitte des Array bestimmen
        int m = l+(r-l)/2;

        mergesort(array, l, m);
        mergesort(array, m+1, r);
        merge(array, l, m, r);
    }
}

// Arrayausgabe für Konsole
void print_array(int array[], int array_size)
{
    int i;
    for (i=0; i < array_size; i++)
        printf("%d ", array[i]);
}


int main(int argc,char *argv[])
{
    int option;
    opterr = 0;

    while ((option = getopt(argc, argv, "vh")) != -1)
        switch (option)
        {
        case 'v':
            printf("Version: 0.1, Author: Roman Rückert\n");
            return 0;
        case 'h':
            printf("-h for help\n-v for Version and Author\n");
            return 0;
        //optional error handling
        case '?':
            if (isprint (optopt))//is character printable
            {
                fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            }
            else
            {
                fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
            }
            return 1;
        default:
            abort ();
        }

    // Statisches Array mit  unsortierten Zahlen
    int array[] = {34, 89, 98, 12, 23, 33, 99, 78, 80, 56};
    // Größe des Array bestimmen
    int array_size = sizeof(array)/sizeof(array[0]);

    // Ausgabe des unsortierten Arrays
    printf("Unsortiertes Array: \n");
    print_array(array, array_size);

    // Array an mergesort Funktion inkl. Index des ersten Elements (0) und Index des letzten Elements (Länge - 1) übergeben
    mergesort(array, 0, array_size - 1);

    // Ausgabe des Ergenisses
    printf("\nSortiertes Array:\n");
    print_array(array, array_size);
    // Zeilenumbruch am Ende der Array Ausgabe, sieht besser auf der Konsole aus..
    printf("\n");

    return 0;
}
