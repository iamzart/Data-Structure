#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h"
SL s;

void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d", s.arr[i]);
	}
	printf("\n");
}
void test01()
{
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPrint(s);
	//SLPopBack(&s);
	SLPopFront(&s);//这儿pop了两次，一共四个元素，现在剩余2个，所以就会断言了，我注释一个pop就行啦
	SLPrint(s);
	SLErase(&s, 3);//这个我看错了，哈哈，有断言是可以的
	SLPrint(s);
	SLInsert(&s, 2, 100);
	SLPrint(s);
}

int main()
{
	test01();
	return 0;
}

//头文件，realloc的，双等号，顺序问题