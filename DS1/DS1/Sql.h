#define _CRT_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mod 4
#pragma once

// 定义线性表
typedef struct Sql{
	// 定义线性表所装元素
	int* arr;
	// 定义线性表所存元素个数
	int size;
	// 线性表容量
	int capacity;
}Sql;

// 初始化线性表
void SqlInit(Sql* sl);

// 线性表插入

// 头插
void insert_head(Sql* sl, int key);
// 尾插
void insert_back(Sql* sl, int key);
// 指定位置插入
void insert_pos(Sql* sl, int pos,int key);


// 线性表删除

// 头删除
void del_head(Sql* sl);
// 尾删除
void del_back(Sql* sl);
// 指定位置删除
void del_pos(Sql* sl, int pos);

// 根据元素查找位置,返回位置pos
void get_pos(Sql* sl, int key);
// 根据位置返回元素
void get_element(Sql* sl, int pos);

// 打印线性表
void PrintSql(Sql* sl);

//查看线性表中得元素个数
int Size(Sql* sl);

// 对线性表进行排序
void sortSql(Sql* sl);

// 判断增加元素时线性表是否会溢出
// 溢出返回1，否则返回0
int isFull(Sql* sl);

// 给线性表扩容
int* exCapacity(Sql* sl);