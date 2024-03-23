#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int arr[],int low, int high)
{
	//NOTE: must find way to not have problem with this function
	if(low>=high)
		return;
	int pivot = partition(arr, low, high);
	quicksort(arr,low,pivot-1);
	quicksort(arr,pivot+1,high);
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low;
	for(int j=low;j<=high;j++)
	{
		if(arr[j]<arr[pivot])
		{
			int temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
		}
	}	
	int temp = arr[i];
	arr[i]=arr[pivot];
	arr[pivot]=temp;
	return i;
}

void printArray(int arr[], int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = {34,7,23,32,5,62};
	int n = sizeof(array)/sizeof(array[0]);

	printf("Original array: \n");
	printArray(array, n);
	quicksort(array,0,n-1);
	printf("Sorted with end element as pivot: \n");
	printArray(array,n);

	return 0;
}
