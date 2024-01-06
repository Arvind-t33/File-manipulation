# File-manipulation
C and Python programs that modify input files.

## volume.c
###  Inputs:
The program expects three command-line arguments in the following order:
   1. ```input.wav```: The name of the input audio file in WAV format.
   2. ```output.wav```: The name of the output audio file where the modified audio will be saved.
   3. ```factor```: A floating-point number representing the scaling factor for modifying the volume.
###  Outputs:
1. Printed Usage Message:
   - If the number of command-line arguments is not 4, the program prints a usage message indicating the correct format and exits with a return code of 1.
2. Error Messages:
   - If the input file cannot be opened, the program prints an error message (```"Could not open file."```) and exits with a return code of 1.
   - If the output file cannot be opened, the program prints an error message (```"Could not open file."```) and exits with a return code of 1.
3. Modified Audio File:
   - The program reads the WAV file specified by input.wav.
   - It applies the volume modification by multiplying each audio sample by the scaling factor provided in the command line.
   - The modified audio samples are then written to the WAV file specified by output.wav.

## mybreak.c
### Inputs:
The program expects three command-line arguments in the following order:
   1. ```<source_file>```: The name of the source binary file that needs to be broken into chunks.
   2. ```<break_prefix>```: The prefix to be used for the names of the output chunk files.
   3. ```<size of each chunk in 1K>```: The size of each chunk in kilobytes.

ChatGPT
This C program, named mybreak, is designed to break a binary file into chunks of a specified size. Below is an explanation of the inputs and outputs of the program:

### Outputs:
- Printed Messages:
   - If the number of command-line arguments is not 4, the program prints a usage message indicating the correct format and exits with a    return code of 1.
- File Chunk Creation:
   - The program opens the source binary file ```<source_file>``` for reading ```f = fopen(argv[1], "r")```.
   - It then enters a loop that iteratively reads chunks from the source file and writes them to new files with names derived from the       ```<break_prefix>``` and a numeric index.
   - Each output file is named with the pattern ```<break_prefix>.<index>```.
   - The chunk size is determined by multiplying the specified size (in kilobytes) by 1024.
- Printed Progress Messages:
   - During the chunk creation process, the program prints messages indicating the start of each new chunk file.
- File Closure and Memory Deallocation:
   - The program closes the source file (```fclose(f)```) and each output chunk file (```fclose(tf)```) after writing the chunks.
   - It frees dynamically allocated memory for the file name (```free(fname)```) for each iteration of the loop.
