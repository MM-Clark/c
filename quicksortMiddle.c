#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksortMiddle(int arr[],int start,int end)
{
	if(start < end)
	{
		int pivot = arr[(start+end)/2];
		int i = start;
		int j = end;
		int temp;
		while(i<=j)
		{
			//move elements smaller than pivot to right
			while(arr[i]<pivot)
				i++;
			//move elements larger than pivot to left
			while(arr[j]>pivot)
				j--;
			if (i<=j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i++;
				j--;
			}
		}

		//recursively sort the partitions
		if(start<j)
			quicksortMiddle(arr,start,j);
		if(i<end)
			quicksortMiddle(arr,i,end);
	}
}

void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = {34,7,23,32,5,62};
	int n = sizeof(array)/sizeof(array[0]);

	printf("original array: \n");
	printArray(array, n);

	quicksortMiddle(array, 0, n - 1);
	printf("Sorted with middle element as pivot: \n");
	printArray(array, n);

	return 0;
}
