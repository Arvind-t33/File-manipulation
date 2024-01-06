

// usage: $myheal <target_file> <break_prefix> <chunk size in 1K> <# of chunks>
// to compile: $gcc -g -Wall myheal.c -o myheal


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define MAX_NAME 8192

int
main
(int argc, char *argv[])
{
  FILE *f = NULL;
  FILE *tf = NULL;
  long chunk_size;
  char *fname = NULL;
  int chunks = 0;

  if (argc != 5) // changed from mybreak
    {
      printf("argc = %d => usage: mybreak <target> <prefix> <chunk size (K bytes)> <number of chunks>\n", argc); // changed from mybreak
      exit(1);
    }

  chunk_size = 1024 * atoi(argv[3]); // size of chunks in bytes.
  if ((chunk_size <= 0) || (chunk_size > (1024 * 1024 * 1024)))
    {
      printf("chunk size error [%d]: size needs to be between 1 (1K) and %d (1G) \n",
	     atoi(argv[3]), 1024*1024);
      exit(1);
    }
	
	chunks = atoi(argv[4]);
	if ((chunks <= 0) || (chunks > 8192 * 16)) {
		printf("chunks erroe [%d]: chunks need to be between 1 and %d \n", 
			atoi(argv[4]), 8192 * 16);
			exit(1);
	}
	
  f = fopen(argv[1], "w"); // changed from mybreak
  if (f != NULL)
    {
      // the file argv[1] has been successfully opened...
      int i,j;
      for (i = 0; i < chunks; i++)
	{
	  fname = malloc(MAX_NAME);
	  bzero((void *) fname, MAX_NAME);
	  sprintf(fname, "%s.%032d", argv[2], i);

	  tf = fopen(fname, "r"); // changed from mybreak
	  if (tf != NULL)
	    {
	      printf(" putting %s\n", fname); // changed from mybreak
	    }
	  else
	    {
	      printf("missing [%d]th chunk, fname %s failed to open\n", i, fname);
	      exit(1);
	    }

		// check chunk size matched
		fseek(tf, 0, SEEK_END);
		long lSize = ftell(tf);
		if ((i != (chunks - 1)) && (chunk_size != lSize))
		{
			printf("error [%d]th chunk: chunk size for %s mismatched\n size [%ld]\n expecting [%ld]\n",
                     i, fname, lSize, chunk_size);
			exit(1);
		}
		rewind(tf);
		

	  // now we have successfully open tf for writing!
	  // read from f, and write to tf
	  // each time 8 bytes.
	  for (j = 0; j < (chunk_size / 8); j++)
	    {
	      unsigned char ccc[8];
	      int cr, cw;

	      cr = fread(ccc, 1, 8, tf); // changed from mybreak
	      if (cr == 0)
		{
		  fclose(f);
		  fclose(tf);
		  free(fname);
		  printf("done... [%d] chunks produced for %s\n", (i+1), argv[1]);
		  exit(0);
		}

	      cw = fwrite(ccc, 1, cr, f); // changed from mybreak
	      if (cr != cw)
		{
		  printf("cr = %d, cw = %d\n", cr, cw);
		  exit(1);
		}

		
	    }
	  fclose(tf);
	  free(fname);
	}
    }
  else
    {
      printf("file {%s} can not be open...\n", argv[1]);
      exit(1);
    }
  return 1;
}
