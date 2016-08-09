/**
 * 快速排序
 */

#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quick_sort(int array[], int s, int e)
{
	int i = s;
	int j = e;

	if (i >= j)
		return;

	while (i < j) {
		for (; j > i; j--) {
			if (array[j] < array[s])
				break;
		}
		for (; i < j; i++) {
			if (array[i] > array[s])
				break;
		}
		if (i < j)
			swap(&array[i], &array[j]);
	}
	
	swap(&array[s], &array[j]);

	quick_sort(array, s, j-1);
	quick_sort(array, j+1, e);
}

int main(void)
{
	int array[5] = {2, 3, 1, 10, 9};
	quick_sort(array, 0, 4);

	for (int i = 0; i < 5; i++)
		printf("%d ", array[i]);
	printf("\n");

	return 0;
}

/**
 * 注意：快排的时间复杂度最坏情况下为O(N^2)，平均时间复杂度为NlgN.
 * 尤其要注意递归的终止条件是left >= right.
 */
