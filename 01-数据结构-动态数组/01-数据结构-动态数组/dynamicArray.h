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
//动态初始化
struct dynamicArray* init_DynamicArray(int capacity);

//插入数组
void insert_DynamicArray(struct dynamicArray* array, int pos, void* data);

//遍历数组
void foreach_DanamicArray(struct dynamicArray* array, void(*myprint)(void*));


//位置删除
void remove_posDynamicArray(struct dynamicArray* array, int pos);


//按值删除
void remove_valueDynamicArray(struct dynamicArray* array, void* data, int(*mycompare)(void*, void*));
//删除数组
void destroy_DynamicArray(struct dynamicArray* array); 
