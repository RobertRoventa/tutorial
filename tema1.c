#include <stdio.h>
#include <time.h>
#include <stdlib.h>





int G=0;
void inmultire(int n, int **a, int **b, int **c, int ***proc){
	int i,j,k,sum, random;
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			sum = 0;
			for(k = 0; k < n; k++){
				random = rand()%10;
				printf("%d ", random);
				if(random > 5 && proc[i][k][j] == 0){
					proc[i][k][j] = 1;
					sum+= a[i][k] * b[k][j];
				}
			}
			c[i][j] += sum;
		}
	}

}
int check(int n, int ***proc){
	int i,j,k;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			for(k = 0; k < n; k++){
				if(proc[i][k][j] == 0)
					return 0;
			}
		}
	}
return 1;
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
	srand(time(NULL));
	printf("\n");
	while(check(n, proc) != 1){
		inmultire(n, a, b, c, proc);
	}


	printf("\n");
	printf("\n");
	for(i = 0; i < n; i++){
		for(j = 0 ; j < n; j++){
			printf ("%d ", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
