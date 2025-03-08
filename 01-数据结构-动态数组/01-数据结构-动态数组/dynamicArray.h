#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct dynamicArray
{
	void** pAddr;
	int m_capacity;
	int m_size;
};
//��̬��ʼ��
struct dynamicArray* init_DynamicArray(int capacity);

//��������
void insert_DynamicArray(struct dynamicArray* array, int pos, void* data);

//��������
void foreach_DanamicArray(struct dynamicArray* array, void(*myprint)(void*));


//λ��ɾ��
void remove_posDynamicArray(struct dynamicArray* array, int pos);


//��ֵɾ��
void remove_valueDynamicArray(struct dynamicArray* array, void* data, int(*mycompare)(void*, void*));
//ɾ������
void destroy_DynamicArray(struct dynamicArray* array); 
