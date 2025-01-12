#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h";
#include<assert.h>
#include<stdlib.h>//realloc函数头文件带上

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//扩容
//创建一个新的capacity，因为原来的为0，一直二倍还是0
//单位是字节
//如果扩容失败会返回空指针，到时候原数据也丢失了，所以应该用一个东西来接受realloc返回值
//什么时候需要扩容，当size = capacity时，就是空间占满了
void SLCapacityCheck(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;//判断是双灯好
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));//ps是整个结构体指针，这块要给数组开辟哈
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//尾插
//有效个数+1
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCapacityCheck(ps);
	ps->arr[ps->size++] = x;
}
//头插
//让后边的元素都向后移动一位，给新元素把头位置腾出来
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCapacityCheck(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	++ps->size;
}
//尾删
//直接让有效个数--，不用担心有啥影响，因为也会被覆盖的
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);//得确定他数组里还有元素呀
	ps->size--;
}
//头删
//直接往前移，把第一个元素覆盖，有效个数--
void SLPopFront(SL*ps)
{
	assert(ps && ps->size);
	for (int i = 0; i <ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//查找任意元素
//找到返回下标，找不到返回-1
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] = x)
			return i;
	}
	//如果轮到这里还没返回，就是未找到
	return -1;
}
//在任意位置之前插入数据
//把这个位置及以后的元素都向后移动，把新元素放到下标为这个位置上
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCapacityCheck(ps);//在插入前都要检查内存够不够
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//指定位置删除元素
//从这个位置开始，让他的下一个往前覆盖
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//销毁
void SLDestroy(SL* ps)
{
	if (ps->arr)//不是空指针的话
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->capacity = ps->size = 0;
	}
}