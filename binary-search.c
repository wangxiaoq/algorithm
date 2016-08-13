#include <stdio.h>

/**
 * 查找成功返回数组下标，否则返回-1；
 */
int binary_search(int value, int array[], int len)
{
	int below = 0, up = len - 1, tmp;

	while (below <= up) {
		tmp = (below + up)/2;
		if (array[tmp] == value) {
			return tmp;		
		} else if (array[tmp] > value) {
			up = tmp - 1;
		} else {
			below = tmp + 1;		
		}
	}

	return -1;
}

int main(void)
{
	int array[] = {1,2,3,4,5,6,7,8,9};

	int index = binary_search(-99, array, 9);

	printf("index: %d\n", index);

	return 0;
}
