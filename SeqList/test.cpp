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
	SLPopFront(&s);//���pop�����Σ�һ���ĸ�Ԫ�أ�����ʣ��2�������Ծͻ�����ˣ���ע��һ��pop������
	SLPrint(s);
	SLErase(&s, 3);//����ҿ����ˣ��������ж����ǿ��Ե�
	SLPrint(s);
	SLInsert(&s, 2, 100);
	SLPrint(s);
}

int main()
{
	test01();
	return 0;
}

//ͷ�ļ���realloc�ģ�˫�Ⱥţ�˳������