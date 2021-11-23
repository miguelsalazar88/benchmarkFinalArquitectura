# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# ifndef MIN
# define MIN(x,y) ((x)<(y)?(x):(y))
# endif

# define DATA_SZ (1024*1024*64*3)

static double  MEM_CHUNK[DATA_SZ];

float Sample_End(struct timeval *inicio, struct timeval *final){
  
  return (final->tv_sec - inicio->tv_sec) + 1e-6*(final->tv_usec - inicio->tv_usec);
}

void Matrix_Init_col(int SZ, double *a, double *b, double *c){
  int j,k;

  for (k=0; k<SZ; k++) 
    for (j=0; j<SZ; j++){
      a[j+k*SZ] = 2.0*(j+k);  
      b[j+k*SZ] = 3.2*(j-k);   
      c[j+k*SZ] = 1.0;
    }
}


int main (int argc, char **argv){
  int  N;

  struct timeval inicio;
  struct timeval final;


  if (argc < 1){
    printf("MM1c MatrixSize [Sample arguments ...]\n"); 
    return -1;
  }

  N  = (int) atof(argv[1]); argc--; argv++;

  if (N > 1024*8)  {
    printf("Unvalid MatrixSize\n");
    return -1;
  }


  int     SZ;
  int     i, j, k;
  double  *a, *b, *c;

  SZ    = N; 

  
  a = MEM_CHUNK;
  b = a + SZ*SZ;
  c = b + SZ*SZ;

  Matrix_Init_col(SZ, a, b, c); 

  gettimeofday(&inicio, NULL);

  for (i=0; i<SZ; i++)
    for (j=0; j<SZ; j++) {
      double *pA, *pB, S;
      S=0.0; 
      pA = a+(i*SZ); pB = b+j;
      for (k=SZ; k>0; k--, pA++, pB+=SZ) 
        S += (*pA * *pB);
      c[i*SZ+j]= S;
    }

  gettimeofday(&final, NULL);

  printf("%f \n", Sample_End(&inicio, &final));

  exit(EXIT_SUCCESS);
}
