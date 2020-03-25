#define _CRT_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mod 4
#pragma once

// �������Ա�
typedef struct Sql{
	// �������Ա���װԪ��
	int* arr;
	// �������Ա�����Ԫ�ظ���
	int size;
	// ���Ա�����
	int capacity;
}Sql;

// ��ʼ�����Ա�
void SqlInit(Sql* sl);

// ���Ա����

// ͷ��
void insert_head(Sql* sl, int key);
// β��
void insert_back(Sql* sl, int key);
// ָ��λ�ò���
void insert_pos(Sql* sl, int pos,int key);


// ���Ա�ɾ��

// ͷɾ��
void del_head(Sql* sl);
// βɾ��
void del_back(Sql* sl);
// ָ��λ��ɾ��
void del_pos(Sql* sl, int pos);

// ����Ԫ�ز���λ��,����λ��pos
void get_pos(Sql* sl, int key);
// ����λ�÷���Ԫ��
void get_element(Sql* sl, int pos);

// ��ӡ���Ա�
void PrintSql(Sql* sl);

//�鿴���Ա��е�Ԫ�ظ���
int Size(Sql* sl);

// �����Ա��������
void sortSql(Sql* sl);

// �ж�����Ԫ��ʱ���Ա��Ƿ�����
// �������1�����򷵻�0
int isFull(Sql* sl);

// �����Ա�����
int* exCapacity(Sql* sl);