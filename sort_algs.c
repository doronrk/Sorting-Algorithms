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

void quick_sort (int a[], int len);
int partition (int a[], int len, int p_value);

int main()
{
	int a[9] = {32, 1 ,22, 3, 5, 56, 32, 1, 6};
	print_array(a, 9);
	insert_sort(&a[0], 9);
	print_array(a, 9);
	return 0;
}

void insert_sort (int a[], int len)
{
	int i;
	for (i = 1; i < len; i++)
	{
		int valueToInsert = a[i];
		int check = i-1;
		while (valueToInsert < a[check] && check >= 0)
		{
			a[check+1] = a[check];
			check--;
		}
		a[check+1] = valueToInsert;
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
		merge_sort(&a[len/2], len - len/2);
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
			left++;
		}
		else
		{
			merged[insert] = a[right];
			right++;
		}
		insert++;
	}
	while (left < len/2)
	{
		merged[insert] = a[left];
		left++;
		insert++;
	}
	while (right < len)
	{
		merged[insert] = a[right];
		right++;
		insert++;
	}
	int i;
	for (i=0; i < len; i++)
	{
		a[i] = merged[i];
	}
	free(merged);
}

void quick_sort (int a[], int len)
{
	if (len > 1)
	{
		int pivot = len/2;
		int p_value = a[pivot];
		int front = partition (a, len, p_value);
		quick_sort(a, front);
		quick_sort(&a[front+1], len - (front+1));
	}
}

int partition (int a[], int len, int p_value)
{
	int *part;
	part = malloc(len*sizeof(int));
	int front = 0;
	int back = len - 1;
	int i;
	for (i = 0; i < len; i++)
	{
		if (i == len/2) {continue;}
		if (a[i] <= p_value)
		{
			part[front] = a[i];
			front++;
		}
		else
		{
			part[back] = a[i];
			back--;
		}
	}
	part[front] = p_value;
	for (i = 0; i < len; i++)
	{
		a[i] = part[i];
	}
	free(part);
	return front;
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



