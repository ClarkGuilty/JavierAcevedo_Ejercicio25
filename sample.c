#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

double u1;   
double u2;   

int i;





int main( int argc, char *argv[] )  {

   if( argc != 4 ) {
		printf("La entrada debe ser de la forma %s N mu sigma\n", argv[0]);
		exit(0);
   }
    srand(time(NULL));   
    int N = atoi(argv[1]);
    int mu = atoi(argv[2]);
    int sigma = atoi(argv[3]);
    
    printf("N=%d\n",N);
    double *arreglo = malloc(N*sizeof(double));
    
    for(i=0;i<N/2;i++){
        u1 = rand()/(RAND_MAX*1.0);
        u2 = rand()/(RAND_MAX*1.0);
        arreglo[N-i-1] = sqrt(-2*log(u1))*cos(2*PI*u2);
        arreglo[i] = sqrt(-2*log(u1))*sin(2*PI*u2);
    }
    
	FILE *output = fopen("sample.dat", "w+");
	for(i=0;i<N;i+=1){
            fprintf(output, "%f\n",arreglo[i]*sigma+mu); 
			}
	fclose(output);
    output = fopen("stan.dat", "w+");
    fprintf(output,"%d\n",N); 
    fprintf(output,"%d\n",mu); 
    fprintf(output,"%d\n",sigma); 
    fclose(output);
    
    
}
   
   
	
    
    
    





