#include <stdio.h>

int main(void)
{
	int array[10];
	int i,j,tmp;

	for (i = 0; i < 10; i++)
		scanf("%d", &array[i]);

	for (i = 0; i < 10-1; i++) {
		for (j = 0; j < 10-1-i; j++) {
			if (array[j] < array[j+1]) {
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}

	for (i = 0; i < 10; i++)
		printf("%d ", array[i]);

	printf("\n");

	return 0;
}

/**
 * 注意：上面这种写法的时间复杂度为(n^2-1)/2。
 * 如果按照下面的恶写法为n^2：
 * for (i = 0; i < N; i++)
 * 	for (j = 0; j < N-1; j++)
 * 		if (array[j] > array[j+1])
 * 			swap(array[j], array[j+1]);
 */
