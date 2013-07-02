#include<stdio.h>
#include<stdlib.h>
// to run
// gcc sort_algs.c
// ./a.out
void print_array(int a[], int len);
void insert_sort (int a[], int len);
void selection_sort (int a[], int len);
void merge_sort(int a[], int len);
void merge(int a[], int len);
void merge_in_place(int* a, int len);

int main()
{
	int a[8];
	a[0] = 8;
	a[1] = 12;
	a[2] = 2;
	a[3] = 5;
	a[4] = 19;
	a[5] = 55;
	a[6] = 835;
	a[7] = 1;
	int b[8];
	b[0]= 8;
	b[1]= 12;
	b[2]= 2;
	b[3]= 5;
	b[4]= 2;
	b[5]= 19;
	b[6]= 1;
	b[7]= 83;
	merge_sort(&b[0], 8);
	print_array(&b[0], 8);
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


// void quick_sort ()
// {

// }

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
			insert ++;
			left ++;
		}
		else
		{
			merged[insert] = a[right];
			insert ++;
			right ++;
		}
	}
	int i;
	if (left == len/2)
	{
		printf("%d\n", right);
		for (i=right; i < len; i++)
		{
			merged[insert] = a[i];
			insert ++;
		}
	}
	if (right == len)
	{
		for (i=left; i < len/2; i++)
		{
			merged[insert] = a[i];
			insert ++;
		}
	}
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



