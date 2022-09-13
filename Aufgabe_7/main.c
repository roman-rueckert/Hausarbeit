#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <unistd.h>


int main(int argc,char *argv[])
{
	char *vvalue = NULL;
	int option;
	opterr = 0;
	

	while ((option = getopt(argc, argv, "hd:f:")) != -1)
	switch (option)
      	{	
		//minimal
		case 'f':
			printf("Hier das eingegebene Argument: %s\n", optarg);
			break;
      		case 'h':
        		printf("-h for help \n-d [text] um Text auszugeben\n");
        		break;
      		case 'd':
			vvalue = optarg;
			printf("%s\n", vvalue);
        	break;
		//optional error handling
      		case '?':
        		if (optopt == 'd')
			{
        			fprintf (stderr, "There are rules! -%c requires an argument.\n", optopt);
			}       	
			else if (isprint (optopt))//is character printable
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

  

  return 0;

}
