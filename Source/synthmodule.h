#ifndef Note_H
#define Note_H

#define SYNTH_MODULE_CHARS (128)
#define MAXIMUM_MODULES (256)

typedef struct{

	char signal_out[SYNTH_MODULE_CHARS]; 
	char frequency[SYNTH_MODULE_CHARS];
	char waveform [SYNTH_MODULE_CHARS];
	char am_signal[SYNTH_MODULE_CHARS];
	char fm_signal [SYNTH_MODULE_CHARS];
	char min_amp [SYNTH_MODULE_CHARS];
	char max_amp [SYNTH_MODULE_CHARS];
} OSCILLATOR_MODULE;

void read_oscillator(OSCILLATOR_MODULE *oscillator_module, int count){

	scanf("%s", oscillator_module[count].signal_out);
	scanf("%s", oscillator_module[count].frequency);
	scanf("%s", oscillator_module[count].waveform);
	scanf("%s", oscillator_module[count].am_signal);
	scanf("%s", oscillator_module[count].fm_signal);
	scanf("%s", oscillator_module[count].min_amp);
	scanf("%s", oscillator_module[count].max_amp);

	if(count >= MAXIMUM_MODULES){
		fprintf(stderr,
				"Number of oscillators has exceeded maximum: %d\n", MAXIMUM_MODULES);
		exit(1);
	}
}

void print_csound_oscillator(OSCILLATOR_MODULE oscillator_module){

	float min_amp, max_amp;
	float rescale_output;

	printf("%s oscillator ", oscillator_module.signal_out);

	if(!strcmp(oscillator_module.fm_signal, "NONE"))
		printf("%s, ", oscillator_module.frequency);
	else
		printf("%s * (1.0 + %s), ", oscillator_module.frequency, oscillator_module.fm_signal);

	if(!strcmp(oscillator_module.am_signal, "NONE"))
		printf("1.0, ");

	else
		printf("%s, ", oscillator_module.am_signal);
	
	if(!strcmp(oscillator_module.waveform, "SINE"))
		printf("isine\n");

	else if(!strcmp(oscillator_module.waveform, "TRIANGLE"))
		printf("itriangle");

	else if(!strcmp(oscillator_module.waveform, "SAWTOOTH"))
		printf("isawtooth");

	else if(!strcmp(oscillator_module.waveform, "SQUARE"))
		printf("isquare"); 

	else if(!strcmp(oscillator_module.waveform, "PULSE"))
		printf("ipulse");

	else{
		fprintf(stderr, "oscillator_module: %s is unknown"
			"- using sinewave instead\n", oscillator_module.waveform);
		printf("isine\n");
	}

	sscanf(oscillator_module.min_amp, "%f", &min_amp);
	sscanf(oscillator_module.max_amp, "%f", &max_amp);

	if(min_amp != -1.0 || max_amp != 1.0){

		rescale_output = (min_amp - max_amp) / 2.0; 

		printf("%s = %s + (%f*%s + %f)\n",
				oscillator_module.signal_out, 
				oscillator_module.min_amp, 
				oscillator_module.max_amp,
				rescale_output,
				oscillator_module.signal_out,
				rescale_output);
	}
}
#endif
