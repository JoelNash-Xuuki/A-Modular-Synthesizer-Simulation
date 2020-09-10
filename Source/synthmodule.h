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
	char min_frequency [SYNTH_MODULE_CHARS];
	char max_frequency [SYNTH_MODULE_CHARS];
} OSCILLATOR_MODULE;

void read_osc(OSCILLATOR_MODULE *oscillator_module, int count){

	scanf("%s", oscs[osc_count].signal_out);
	scanf("%s", oscs[osc_count].frequency);
	scanf("%s", oscs[osc_count].waveform);
	scanf("%s", oscs[osc_count].am_signal);
	scanf("%s", oscs[osc_count].fm_signal);
	scanf("%s", oscs[osc_count].min_frequency);
	scanf("%s", oscs[osc_count].max_frequency);

	if(count >= MAXIMUM_MODULES){
		fprintf(stderr,
				"Number of oscillators has exceeded maximum: %d\n", MAXIMUM_MODULES);
		exit(1);
	}
}

void write_csound_oscillator(OSCILLATOR_MODULE oscillator_module){

	float min_frequency, max_frequency;
	float mo2;

	printf("%s oscillator ", oscillator_module.sig_out);

	if(!strcmp(oscillator_module.sig_fm_signal, "NONE"))
		printf("%s, ", oscillator_module.frequency);
	else
		printf("%s * (1.0 + %s), ", oscillator_module.frequency, oscillator_module.fm_signal;

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
		fprintf(not_valid, "oscillator_module: %s is unknown"
			"- using sinewave instead\n", oscillator_module.waveform);
		printf("isine\n");
	}

	sscanf(oscillator_module.min_frequency, "%f", &min_frequency;
	sscanf(oscillator_module.max_frequency, "%f", &max_frequency;

	if(oscillator_module.min_frequency != -1.0 || oscillator_module.max_frequency != 1.0){

		rescale_output = (min_frequency - max_frequency) / 2.0; 

		printf("%s = %s + (%f*%s + %f)\n",
				oscillator_module.output_signal, 
				oscillator_module.min_frequency, 
				oscillator_module.max_frequency,
				rescale_output,
				oscillator_module.output_signal,
				rescale_output);
}
#endif
