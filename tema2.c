#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
void inmultire(int n, int **a, int **b, int ***proc){
	int i,j,k,sum, random;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < n; k++){
				proc[i][j][k] = a[i][k] * b[k][j];
			}
		}
	}
}
void reducere(int n, int ***proc){
	int i,j,k,m;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			for(m = 0; m < (int)log2((double)n); m++){
				for(k = 0; k < n; k++){
				
					if( (k % (int)pow(2, (m+1))) == 0){
						proc[i][j][k] += proc[i][j][k+(int)pow(2,m)];
					}
					
				}
			}
		}
	}
}
int main(){
	int i, n, j, k;
	n = 4;
	int **a, **b, **c, ***proc;
	a = calloc(n, sizeof(int*));
	b = calloc(n, sizeof(int*));
	c = calloc(n, sizeof(int*));

	for(i = 0; i < n; i++){
		a[i] = calloc(n, sizeof(int));
		b[i] = calloc(n, sizeof(int));
		c[i] = calloc(n, sizeof(int));
	}
	proc = calloc(n, sizeof(int**));
	for(i = 0; i < n; i++){
		proc[i] = calloc(n, sizeof(int*));
	}
	for(i = 0; i < n; i++){
		for(j = 0 ; j < n; j++){
			proc[i][j] = calloc(n, sizeof(int));
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0 ; j < n; j++){
			a[i][j] = rand() % 10;
			b[i][j] = rand() % 10;
			c[i][j] = 0;
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0 ; j < n; j++){
			printf ("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	for(i = 0; i < n; i++){
		for(j = 0 ; j < n; j++){
			printf ("%d ", b[i][j]);
		}
		printf("\n");
	}

	inmultire(n, a, b, proc);
	//reducere(n, proc);


	printf("\n");
	printf("\n");
	
	reducere(n, proc);
	for(i = 0; i < n; i++){
		for(j = 0 ; j < n; j++){
			printf ("%d ", proc[i][j][0]);
		}
		printf("\n");
	}
	
	return 0;
}