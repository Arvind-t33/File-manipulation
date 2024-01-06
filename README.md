# File-manipulation
C and Python programs that modify input files.

## volume.c
### Inputs:
The program expects three command-line arguments in the following order:
   1. ```input.wav```: The name of the input audio file in WAV format.
   2. ```output.wav```: The name of the output audio file where the modified audio will be saved.
   3. ```factor```: A floating-point number representing the scaling factor for modifying the volume.
### Outputs:
1. Printed Usage Message:
   - If the number of command-line arguments is not 4, the program prints a usage message indicating the correct format and exits with a return code of 1.
2. Error Messages:
   - If the input file cannot be opened, the program prints an error message (```"Could not open file."```) and exits with a return code of 1.
   - If the output file cannot be opened, the program prints an error message (```"Could not open file."```) and exits with a return code of 1.
3. Modified Audio File:
   - The program reads the WAV file specified by input.wav.
   - It applies the volume modification by multiplying each audio sample by the scaling factor provided in the command line.
   - The modified audio samples are then written to the WAV file specified by output.wav.
