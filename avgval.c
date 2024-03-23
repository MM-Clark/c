#include <stdio.h>

int main()
{
	double wi1, ci1, wi2, ci2, result; //dec weight and counts
	
	//weight of item1
	printf("Weight - Item1: ");
	scanf("%lf", &wi1);
	
	//count of item1
	printf("No. of item1: ");
	scanf("%lf", &ci1);
	
	//prompt user for weight of item2
	printf("Weight - Items2: ");
	scanf("%lf",&wi2);

	//prompt user for count of item2
	printf("No. of item2: ");
	scanf("%lf", &ci2);

	//calc avg val
	result = ((wi1 * ci1)+(wi2 * ci2))/(ci1+ci2);

	//print avg val
	printf("Average value = %f\n", result);

	return 0;
}
