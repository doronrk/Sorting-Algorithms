#include<stdio.h>
#include<stdlib.h>

struct heap {
  int* array;
	int bottom;
	int size;
};

void print_array(int a[], int len);
struct heap *binary_heapify(int a[], int len);
void insert(struct heap *h, int value);
void copy_array(int source[], int dest[], int len);
int extract_greatest(struct heap *h);
void reorder(struct heap *h);
void heap_sort (int a[], int len);


#define PARENT_INDEX(x) ((x-1)/2)
#define LEFT_CHILD(x) (x*2 + 1)
#define RIGHT_CHILD(x) (x*2 + 2)

int main()
{	
	int a[12] = {25,78,3,42,8,12,80,1,7,16,35,29};
	print_array(a, 12);
	heap_sort(a, 12);
	print_array(a, 12);
	return 0;
}

void heap_sort (int a[], int len)
{
	struct heap *h = binary_heapify(a,len);
	int i;
	for (i=0;i<len;i++)
	{
		a[i] = extract_greatest(h);
	}
}


void print_array (int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void copy_array(int source[], int dest[], int len)
{
	int i;
	for (i = 0; i < len; i++){
		dest[i] = source[i];
	}
}

struct heap *new_heap(int len)
{
	struct heap *h = malloc(sizeof(struct heap));
	h->array = malloc(len*sizeof(int));
	h->bottom = 0;
	h->size = len;
	return h;
}

struct heap *binary_heapify(int a[], int len)
{
	struct heap *h = new_heap(len);
	int i;
	for (i = 0; i < len; i++) {
		insert(h, a[i]);
	}
	return h;
	free(a);
}


void insert(struct heap *h, int valueToInsert)
{
	int empty_index = h->bottom;
	int parent_index = PARENT_INDEX(empty_index);
	int temp;
	while (valueToInsert > h->array[parent_index] && empty_index > 0)
	{
		temp = h->array[parent_index];
		h->array[parent_index] = valueToInsert;
		h->array[empty_index] = temp;
		empty_index = parent_index;
		parent_index = PARENT_INDEX(parent_index);
	}
	h->array[empty_index] = valueToInsert;
	h->bottom++;
}

int extract_greatest(struct heap *h)
{	
	if (h->bottom == 0) {
		return 0;
	}
	int greatest = h->array[0];
	reorder(h);
	return greatest;
}

void reorder(struct heap *h)
{
	h->array[0] = h->array[h->bottom-1];
	h->bottom--;
	int empty_index = 0;
	int valueToInsert = h->array[0];
	int left_index, right_index, left_value, right_value, temp;
	while (LEFT_CHILD(empty_index) < h->bottom || RIGHT_CHILD(empty_index) < h->bottom) {
		left_index = LEFT_CHILD(empty_index);
		right_index = RIGHT_CHILD(empty_index);
		left_value = h->array[left_index];
		right_value = h->array[right_index];

		if (valueToInsert < left_value && left_value > right_value) {
			temp = h->array[left_index];
			h->array[left_index] = valueToInsert;
			h->array[empty_index] = temp;
			empty_index = LEFT_CHILD(empty_index);
		}
		else if (valueToInsert < right_value) {
			temp = h->array[right_index];
			h->array[right_index] = valueToInsert;
			h->array[empty_index] = temp;
			empty_index = RIGHT_CHILD(empty_index);
		}
		else {break;}
	}
}

