.RP

.TL Modular Synth Simulation

.AB[no]

.LP 
\fBA little back ground...\fR
 - A modulular synth simulation is one of the earliest ideas in computer music.
 - Bell Labs 1950's (including Max Mathews) 
 recognised that analog electronic circuits could be understood 
 performing mathematical operations that can be modelled digitally.

 - Previous programs BLODI, Music I-V....acoustic compilers.


\fBBasic design\fR

.I Concept:

    - A basic method of analog synthesis is to patch together self contained modules that generate or modify electric signals.
    - Csound uses this paradigm, instead of modules csound has unit generators and patch cords are signal variables.

So, there are are two parts to this investigation:

	1. Write a "patch specification language"(PSL). A simple "language"(program) to transtate patch specifications to csound orchestra.

	2. Develop it into a programme will algorithmically generate patch specifications, automating the sound design process.

.I Why?... 

 ...PSL instead of writing Csound code? It should encourage creation of more complex patches, as PSL is more convenient.

\fBWhich analogue modules shall we model?\fR

    - Oscillator
    - Filter
    - Sample and hold unit
    - Noise

\fBLets look at the patch Specification for an oscillator.\fR 

A primary function of an ocillator








\fBUnit Generators (Modules) / interface design\fR

 \fBOscillator.\fR
 	Patch Specification:
	
             - Adjust Waveform.
             - Adjust Frequency.
             - Frequency Modulate oscillator.
             - Amplitude Modulate oscillator. 
             - Specifiy oscillator amplitude range. 
             - Output name (patch cord). 

	Intereface:
             - Module
             - output variable.
             - frequency.
             - waveform.
             - AM signal.
             - FM signal.
			 - Minimum amplitude
             - Maximum amplitude

	Csound Code:
             
             OSC a1 400 SINE NONE NONE -1 1

	Format Alternative 

		- to patch by hand instead of automation you could use:

			 OSC OUT=a1 FREQ=440


 - filter
 - sample hold


\fBBuilding the Code\fR

C needs to.
        -> Read in patch specifications.
        -> Turn read patch specifications into Csound code.
        -> Embed the Csound code patch specificaions into a 
            working instrument. 
        -> Write Csound orchestra that can synthesize the patch.

Code can be found as:
    - synthmodule.h
    - synthmodule.c

\fB The Command-Line Interface\fR
 
Use the synthmodule (executable file) in the shell.
A data file is the module patch to configure our synth. This can be done
on the command line using:

λsynthmodule < modulepatch1

\fB Tightening the Structure and Making It Safer (note: xtremeprgramming.com) \fR

At the moment there are a maxium of 256 OSCS.

.I When we print the Oscillators to csound code.

Next I think is the algorithm for the Frequency and ...
If the minimum frequency is !=-1.0 and if maximum frequency is !=1.0

Rescale the frequency with maxium frequency minus the minimumfrequency then divid 
by 2.0.

We then ask for the output signal to be:
the minmum frequency plus (rescaled frequency * output signal + rescaled signal)




