#include <stdio.h>

typedef struct MinHeap MinHeap;
struct MinHeap 
{
	int* arr;
	//current size of heap
	int size;
	//max capacity of heap
	int capacity;
};

int parent(int i)
{
	//get the index of parent
	return (i - 1) / 2;
}

int leftChild(int i)
{
	return (2*i + 1);
}

int rightChild(int i)
{
	return (2*i + 2);
}

int peek(MinHeap* heap)
{
	//return the root node element since is min
	return heap->arr[0];
}

MinHeap* initMinHeap(int capacity)
{
	MinHeap* minHeap = (MinHeap*) calloc (1, sizeof(MinHeap));
	minHeap->arr = (int*) calloc (capacity, sizeof(int));
	minHeap->capacity = capacity;
	minHeap->size = 0;
	return minHeap;
}

MinHeap* add(MinHeap* heap, int element)
{
	//inserts element into min heap
	if(heap->size == heap->capacity)
	{
		fprintf(stderr, "Cannot insert %d. Heap is already full!\n", element);
		return heap;
	}
	//can add, increase size and add to end
	heap->size++;
	heap->arr[heap->size - 1] = element;

	//swap until reach root
	int curr = heap->size - 1;

	//swap as long as aren't in root node while parent node of last element is greater than element
	while(curr > 0 && heap->arr[parent(curr)] > heap->arr[curr])
	{
		//swap
		int temp = heap->arr[parent(curr)];
		heap->arr[parent(curr)] = heap->arr[curr];
		heap->arr[curr]=temp;
		//update current index of element
		curr = parent(curr);
	}
	return heap;
}

MinHeap* remove(MinHeap* heap, int element)
{
	//delete min el at root
	if(!heap || heap->size == 0)
		return heap;
	
	int size = heap->size;
	int lastElement = heap->arr[size-1];

	//update root val with last element
	heap->arr[0] = lastElement;

	//remove last element by decreasing size
	heap->size--;
	size--;

	//must now maintain the heap property with heapify
	heap = bubbleDown(heap, 0);
	return heap;
}

MinHeap* bubbleDown(MinHeap* heap, int index)
{
	//rearranges heap to main min heap property 
	if(heap->size <= 1)
		return heap;

	int left = leftChild(index);
	int right = rightChild(index);

	//var to get smallest element of subtree of an element an index
	int smallest = index;

	//if left child is smaller than this element, is smallest
	if(left < heap->size && heap->arr[left] < heap->arr[index])
		smallest = left;
	
	//if right is smalller update the smallest index
	if(right < heap->size && heap->arr[right] < heap->arr[smallest])
		smallest = right;

	//Now if parent is not smallest, swap with the current element. Will recursively do until reaching root.
	if(smallest != index)
	{
		int temp = heap->arr[index];
		heap->arr[index] = heap->arr[smallest];
		heap->arr[smallest] = temp;
		heap = heapify(heap, smallest);
	}

	return heap;
}

MinHeap* deleteElement(MinHeap* heap, int index)
{
	//deletes element, indexed by index
	//ensure that it is lesser than the current root
	heap->arr[index] = peek(heap) - 1;

	//keep swapping until we update the tree
	int curr = index;
	while(curr > 0 && heap->arr[parent(curr)] > heap->arr[curr])
	{
		int temp = heap->arr[parent(curr)];
		heap->arr[parent(curr)] = heap->arr[curr];
		heap->arr[curr] = temp;
		curr = parent(curr);
	}

	//now simply delete min element
	heap = remove(heap);
	return heap;
}

void printHeap(MinHeap* heap)
{
	printf("Min Heap: \n");
	for(int i=0;i<heap->size;i++)
		printf("%d -> ", heap->arr[i]);
	printf("\n");
}

void freeMinHeap(MinHeap* heap)
{
        if(!heap)
                return;
        free(heap->arr);
        free(heap);
}

int main()
{
	//capacity of 10 elements
	MinHeap* heap = initMinHeap(10);

	add(heap, 40);
	add(heap, 50);
	add(heap, 5);
	add(heap, 8);
	printHeap(heap);

	remove(heap);
	printHeap(heap);
	
	freeMinHeap(heap);
	return 0;
}
