#include <stdio.h>
#include <math.h>
int main(){
	float i;
	float n=33;
	printf("\nS ");
	for(i = 1; i< n; i++)
		printf("%f ", (i+3)/4);
	printf("\nE ");
	for(i = 1; i< n; i++)
		printf("%f ", (i+3)/(4*i));
	printf("\nR ");
	for(i = 1; i< n; i++)
		printf("%f ", (i + log2(i))/i);
	printf("\nU ");
	for(i = 1; i< n; i++)
		printf("%f ", (i+3)*(i + log2(i))/(i*i*4));
	printf("\nQ ");
	for(i = 1; i< n; i++)
		printf("%f ", (i+3)*(i+3)/(16*(i+log2(i))));
	printf("\n");

	return 0;
}