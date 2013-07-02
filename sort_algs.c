#include<stdio.h>
#include<stdlib.h>
// to run
// gcc sort_algs.c
// ./a.out

#define COUNT_OF(x) (sizeof(x)/sizeof(x[0]))

void print_array(int a[], int len);
void insert_sort (int a[], int len);
void selection_sort (int a[], int len);
void merge_sort(int a[], int len);
void merge(int a[], int len);
void merge_in_place(int* a, int len);

int main()
{
	int a[] = { 8, 12, 2, 5, 19, 55, 1, 7 };
	print_array(a, COUNT_OF(a));
	merge_sort(a, COUNT_OF(a));
	print_array(a, COUNT_OF(a));
	return 0;
}

void insert_sort (int a[], int len)
{
	int i;
	for (i = 1; i < len; i++)
	{
		int valueToInsert = a[i];
		int emptyIndex = i;
		while (valueToInsert < a[emptyIndex - 1] && emptyIndex > 0)
		{
			a[i] = a[emptyIndex - 1];
			emptyIndex --;
		}
		a[emptyIndex] = valueToInsert;
	}
}

void selection_sort (int a[], int len)
{
	int i;
	int j;
	for (i = 0; i < len; i++)
	{
		int min = a[i];
		int index = i;
		for (j = i+1; j < len; j++){
			if (a[j] < min)
			{
				min = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = min;
	}
}

void merge_sort(int a[], int len)
{
	if (len > 1)
	{
		merge_sort(&a[0], len/2);
		merge_sort(&a[len/2], len/2);
		merge(&a[0], len);
	}
}

void merge(int a[], int len)
{
	int *merged;
	merged = malloc(len*sizeof(int));
	int left = 0;
	int right = len/2;
	int insert = 0;
	while (left < len/2 && right < len)
	{
		if (a[left] < a[right])
		{
			merged[insert] = a[left];
			left ++;
		}
		else
		{
			merged[insert] = a[right];
			right ++;
		}
		insert ++;
	}
	while (left < len/2)
	{
		merged[insert] = a[left];
		left ++;
		insert++;
	}
	while (right < len)
	{
		merged[insert] = a[right];
		right ++;
		insert ++;
	}
	int i;
	for (i=0; i < len; i++)
	{
		a[i] = merged[i];
	}
}

void merge_in_place(int* a, int len)
{
	int left = 0;
	int right = len/2;
	// printf("a[len/2] = %d\n", a[len/2]);
	// print_array(a, len);
	int insert = 0;
	while (left < len && right < len)
	{
		if (left == right)
		{
			if (left >= len/2)
			{
				break;
			}
			left = insert;
		}
		int temp = a[insert];
		if (a[left] <= a[right])
		{
			a[insert] = a[left];
			a[left] = temp;
			insert ++;
			left = insert;
		}
		else // right < left
		{
			a[insert] = a[right];
			a[right] = temp;
			left = right;
			right ++; 
			insert ++;
		}
		print_array(a, len);
	}
}


// void quick_sort ()
// {

// }


// void bucket_sort()
// {

// }

void print_array (int a[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		int x = *(&a[i]);
		printf("%d ", x);
	}
	printf("\n");
}



