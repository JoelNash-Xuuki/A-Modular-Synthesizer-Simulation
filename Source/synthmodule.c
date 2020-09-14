#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "synthmodule.h"

int main(int argc, char **argv)
{
	OSCILLATOR_MODULE *oscillator;
	int oscillator_count = 0; 
	char module_name[64];

	oscillator = (OSCILLATOR_MODULE *) malloc(MAXIMUM_MODULES * sizeof(OSCILLATOR_MODULE));

	while(scanf("%s", module_name) != EOF){ 
		if(!strcmp(module_name, "OSC"))
			read_oscillator(oscillator, oscillator_count++);

		else{
			fprintf(stderr,"%s is an unknown module\n", module_name);
		}
	}
	for(int i = 0; i < oscillator_count; i++)
		print_csound_oscillator(oscillator[i]);
}
