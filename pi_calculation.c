#include <stdio.h>
#include <stdlib.h>
#include <time.h>



double getRandomNumber(double lower_limit, double upper_limit){
  
   return lower_limit + (upper_limit-lower_limit) * rand() / RAND_MAX;
}

double calculatePi(int max_iteration){
    double x, y;
	int inside_the_circle = 0;
	for (int i = 0; i < max_iteration; i++){
	  x = getRandomNumber(-1,1);
	  y = getRandomNumber(-1,1);
	  
	  if(x*x + y*y <= 1){
	    inside_the_circle++ ;
	}
}	
return (inside_the_circle * 4.0 / max_iteration);
}	
int main(){	
    int max_iteration = 100;
	srand(time(NULL));
	double pi = calculatePi(max_iteration);
	printf("Estimated Pi's = %.3lf for %d red-dots\n", pi, max_iteration);
	
	double mean = 0;
	int number_of_trials = 100;
	for (int i = 0; i<number_of_trials; i++){
		mean+= calculatePi(max_iteration);
	}
	mean /= number_of_trials;
	printf("Mean Value of %d Estimated Pi's = %.3lf", number_of_trials, mean);
	
	return EXIT_SUCCESS;
}
