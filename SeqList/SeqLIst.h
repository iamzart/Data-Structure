#pragma once
#include<stdio.h>
#include<stdlib.h>
/*顺序表的结构*/
typedef int SLDataType;
//定义这个是因为，在表示数组类型的时候就用这一串，到时候要改char就很方便
 typedef struct SeqList
{
	SLDataType* arr;//数组类型
	int size;//数组有效个数
	int capacity;//容量
}SL;//给结构体取的别名，方便
//该初始化，这里只用声明
void SLInit(SL *ps);
//销毁
void SLDestroy(SL* ps);
//尾插
void SLPushBack(SL* PS, SLDataType x);
//头插
void SLPushFront(SL* ps, SLDataType x);
//尾删
void SLPopBack(SL* ps);
//头删
void SLPopFront(SL* ps);
//查找
int SLFind(SL* ps, SLDataType x);
//指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x);
//指定位置删除数据
void SLErase(SL* ps, int pos);