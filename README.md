# File-manipulation
C and Python programs that modify input files.

## volume.c

###  Inputs:
1. **Command-line arguments:**
   - `argc`: An integer representing the number of command-line arguments.
   - `argv`: An array of strings representing the command-line arguments.
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
1. **Command-line arguments:**
   - `argc`: An integer representing the number of command-line arguments.
   - `argv`: An array of strings representing the command-line arguments.
   The program expects three command-line arguments in the following order:
   1. ```<source_file>```: The name of the source binary file that needs to be broken into chunks.
   2. ```<break_prefix>```: The prefix to be used for the names of the output chunk files.
   3. ```<size of each chunk in 1K>```: The size of each chunk in kilobytes.

   Note: The program assumes that the source file is a binary file and may not work correctly for text files or files in other formats. It also assumes that the file is large enough to produce multiple chunks based on the specified size.

### Outputs:
1. Printed Messages:
   - If the number of command-line arguments is not 4, the program prints a usage message indicating the correct format and exits with a    return code of 1.
2. File Chunk Creation:
   - The program opens the source binary file ```<source_file>``` for reading ```f = fopen(argv[1], "r")```.
   - It then enters a loop that iteratively reads chunks from the source file and writes them to new files with names derived from the       ```<break_prefix>``` and a numeric index.
   - Each output file is named with the pattern ```<break_prefix>.<index>```.
   - The chunk size is determined by multiplying the specified size (in kilobytes) by 1024.
3. Printed Progress Messages:
   - During the chunk creation process, the program prints messages indicating the start of each new chunk file.
4. File Closure and Memory Deallocation:
   - The program closes the source file (```fclose(f)```) and each output chunk file (```fclose(tf)```) after writing the chunks.
   - It frees dynamically allocated memory for the file name (```free(fname)```) for each iteration of the loop.

## myheal.c 

### Inputs:

1. **Command-line arguments:**
   - `argc`: An integer representing the number of command-line arguments.
   - `argv`: An array of strings representing the command-line arguments.

   The program expects five command-line arguments in the following order:
   1. `<target_file>`: The name of the target binary file that needs to be reconstructed.
   2. `<break_prefix>`: The prefix used for the names of the chunk files produced by `mybreak`.
   3. `<chunk_size in 1K>`: The size of each chunk in kilobytes (used during the chunking process).
   4. `<number_of_chunks>`: The total number of chunks that need to be read and reconstructed.

### Outputs:

1. **Printed Messages:**
   - If the number of command-line arguments is not 5, the program prints a usage message indicating the correct format and exits with a return code of 1.

2. **File Reconstruction:**
   - The program opens the target binary file (`<target_file>`) for writing.
   - It enters a loop that iteratively reads chunks from the chunk files and writes them to the target binary file.
   - The loop continues for the specified number of chunks, and each chunk file is named with the pattern `<break_prefix>.<index>`.

3. **Printed Progress Messages:**
   - During the reconstruction process, the program prints messages indicating the chunks being processed.

4. **File Size Matching:**
   - The program checks if the size of each chunk matches the expected chunk size, except for the last chunk which may have a different size.

5. **Error Handling:**
   - The program checks for errors during file opening, reading, writing, and memory allocation.
   - It prints appropriate error messages and exits with a return code of 1 if an error occurs.

6. **Completion Message:**
   - Once all chunks are processed and the target file is reconstructed, the program prints a completion message indicating the number of chunks processed and the target file name.

7. **Return Code:**
   - The program returns a code of 1 at the end, indicating that it has finished execution.


