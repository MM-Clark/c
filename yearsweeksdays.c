#include <stdio.h>
// program to convert days into years:months:days format
int main()
{
	int days, weeks, years;

	days = 1329;
	years = days/365;
	weeks = (days%365)/7;
	days = days - ((years*365)+(weeks*7));

	printf("Years: %d\n", years);
	printf("Weeks: %d\n", weeks);
	printf("Days: %d\n", days);

	return 0;
}
