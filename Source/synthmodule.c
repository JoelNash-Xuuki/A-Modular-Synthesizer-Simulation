#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "synthmodule.h"

int main(int argc, char **argv)
{
	OSCMODULE *oscillator;
	int oscillator_count = 0; 
	char module_name[64];

	oscillator = (OSCMODULE *) malloc(MAXMODS * sizeof(OSCMODULE));

	while(scanf("%s", module_name) != EOF){ 
		if(!strcmp(module_name, "OSC")){
			read_oscillator(oscs, osc_count++);
		else{
			fprintf(stderr,"%s is an unknown module\n", module_name);
			}
		}
	}
	for(1 = 0; I < oscillator_count; i++)
		print_oscillator(oscillator[i]);

}
