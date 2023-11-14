#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void printArray(int* arr, int l, int r)
{
	for (int i = 0; i < l; i++)
	{
		printf("%*c", 3, ' ');
	}
	for (int i = l; i <= r; i++)
	{
		printf("%-3d", arr[i]);
	}
	printf("\n");
}

void mergeArray(int* arr, int l, int r)
{
	int m = l + (r - l) / 2;

	int s1 = m - l + 1;
	int s2 = r - m;

	int i = 0;
	int j = 0;
	int k = l;

	int* L = (int*)malloc(sizeof(int) * s1);
	int* R = (int*)malloc(sizeof(int) * s2);

	if (L && R)
	{
		for (i = 0; i < s1; i++)
		{
			L[i] = arr[l + i];
		}

		for (j = 0; j < s2; j++)
		{
			R[j] = arr[m + 1 + j];
		}

		i = 0;
		j = 0;

		while (i < s1 && j < s2)
		{
			if (L[i] <= R[j])//zapewnienie stabilnosci
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		while (i < s1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}

		while (j < s2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}

		free(L);
		free(R);
	}
}

void mergeSortRecursively(int *arr, int l, int r)
{
	printArray(arr, l, r);
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSortRecursively(arr, l, m);
		mergeSortRecursively(arr, m + 1, r);
		mergeArray(arr, l, r);
	}
}

void mergeSort(int* arr, int size)
{
	mergeSortRecursively(arr, 0, size - 1);
}

int main(void)
{
	int arr[] = { 55, 34, 5, 89, 13, 8, 21 };
	int size = sizeof(arr) / sizeof(*arr);

	mergeSort(arr, size);

	return 0;
}