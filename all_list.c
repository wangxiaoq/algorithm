/**
 * 问题描述：给出一个没有相同元素的数组，输出这个数组的全排列
 */

#if 0
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void all_list(char *str, int start, int length)
{
	if (start == length - 1) {
		printf("%s\n", str);
	} else {
		for (int i = start; i <= length-1; i++) {
			swap(&str[start], &str[i]);
			all_list(str, start+1, length);
			swap(&str[start], &str[i]);
		}
	}
}

int main(void)
{
	char abc[] = "aac";
	all_list(abc, 0, 3);
	
	return 0;
}

#endif

#if 0

思考：对于一个存在相同元素的数组，如何得到一个数组的全排列？

去重全排列的规则就是从第一个数开始，每个数分别与它后面的数非重复的数进行交换。
#endif

#include <stdio.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int should_swap(char *str, int start, int end)
{
	for (; start < end; start++) {
		if (str[start] == str[end])
			return 0;
	}

	return 1;
}

void all_list(char *str, int start, int length)
{
	if (start == length - 1) {
		printf("%s\n", str);
	} else {
		for (int i = start; i <= length - 1; i++) {
			if (should_swap(str, start, i)) {
				swap(&str[start], &str[i]);
				all_list(str, start+1, length);
				swap(&str[i], &str[start]);
			}
		}
	}
}

int main(void)
{
	char str[] = "aac";
	all_list(str, 0, 3);

	return 0;
}

#if 0

ref
===
1. http://wuchong.me/blog/2014/07/28/permutation-and-combination-realize/

#endif
