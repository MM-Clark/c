#include <stdio.h>

//merge two subarrays L and M into a
void merge(int a[], int p, int q, int r)
{
	//Create L <- A[p..q] and M <- A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];

	for(int i=0; i < n1; i++)
		L[i] = a[p + i];
	for(int j=0;j<n2;j++)
		M[j]=a[q+1+j];

	//Maintain current index of subarrays and main arrays
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	//until we reach either end of either L or M, pick the larger among elements L and M and place them in the correct position at A[p..r]
	while(i<n1 && j<n2)
	{
		if(L[i] <= M[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = M[j];
			j++;
		}
		k++;
	}

	//When we run out of elements in either L or M, pick up
	//the remaining elements and put in A[p..r]
	while(i<n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k] = M[j];
		j++;
		k++;
	}
}

//Divide array into two subarrays, sort and merge them
void mergesort(int a[], int l, int r)
{
	if(l<r)
	{
		//m is the point where the array is divided into two subarrays
		int m = l + (r - l) / 2;
		
		mergesort(a,l,m);
	        mergesort(a,m+1,r);
		
		//merge the sorted arrays 
		merge(a, l, m, r);	
	}
}

void printArray(int a[], int size)
{
	for(int i=0;i<size;i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int arr[] = {6,5,12,19,9,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	printf("Orig arr: \n");
	printArray(arr, size);

	mergesort(arr, 0, size - 1);

	printf("Sorted arr: \n");
	printArray(arr, size);
}
