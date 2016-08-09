#include <stdio.h>

#define BUCKETSIZE 11

int main(void)
{
	int bucket[BUCKETSIZE];
	int input;
	int i, j;
	
	for (i = 0; i < BUCKETSIZE; i++)
		bucket[i] = 0;

	for (i = 0; i < 5; i++) {
		scanf("%d", &input);
		bucket[input]++;
	}

	for (i = BUCKETSIZE-1; i >= 0; i--) {
		for (j = 0; j < bucket[i]; j++)
			printf("%d ", i);
	}

	printf("\n");

	return 0;
}

/**
 * 思考：如果是对学生成绩按照分数从高到低进行排序，要求输入人名和成绩，输出排好序的人名和
 * 成绩，桶牌序应该怎样做？假设学生的成绩范围[0,100]，且都是整数。
 *
 * 一种思路：可以构造下面的结构体来存放输入信息：
 * struct record {
 * 	char name[NAMESIZE];
 * 	int score;
 * 	struct record *next;
 * };
 * 桶的结构如下：
 * struct record *bucket[101];
 * 将学生信息根据对应的分数挂在相应的bucket中。
 */
