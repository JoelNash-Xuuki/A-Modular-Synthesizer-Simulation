#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "synthmodule.h"

int main(int argc, char **argv)
{
	OSCMODULE *oscs;
	int osc_count = 0; 
	char module_name[64];

	oscs = (OSCMODULE *) malloc(MAXMODS * sizeof(OSCMODULE));

	while(scanf("%s", module_name) != EOF)
	{ if(! strcmp(module_name, "OSC"))
		{
			scanf("%s", oscs[osc_count].output_signal);
			scanf("%s", oscs[osc_count].frequency);
			scanf("%s", oscs[osc_count].waveform);
			scanf("%s", oscs[osc_count].am_signal);
			scanf("%s", oscs[osc_count].fm_signal);
			scanf("%s", oscs[osc_count].min_frequency);
			scanf("%s", oscs[osc_count].max_frequency);

			printf("%s %s %s %s %s %s %s\n",
				oscs[osc_count].signal_out,
				oscs[osc_count].frequency,
				oscs[osc_count].waveform,
	 	        oscs[osc_count].am_signal,
				oscs[osc_count].fm_signal,
				oscs[osc_count].set_min_frequency,
				oscs[osc_count].set_max_frequency);
			++osc_count;
		}	
	}
}
