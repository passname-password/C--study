#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"dynamicArray.h"
//struct dynamicArray
//{
//	void** pAddr;
//	int m_capacity;
//	int m_size;
//};
////��̬��ʼ��
//struct dynamicArray* init_DynamicArray(int capacity)
//{
//	if (capacity <= 0)
//	{
//		return NULL;
//	}
//	struct dynamicArray* array = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
//	if (array == NULL)
//	{
//		return NULL;
//	}
//	array->pAddr = (void**)malloc(sizeof(void*) * capacity);
//	array->m_capacity = capacity;
//	array->m_size = 0;
//	return array;
//}
////��������
//void insert_DynamicArray(struct dynamicArray* array, int pos, void* data)
//{
//	if (array == NULL)
//	{
//		return;
//	}
//	if (data == NULL)
//	{
//		return;
//	}
//	if (pos<0 || pos>array->m_size)
//	{
//		pos = array->m_size;
//	}
//	if (array->m_size == array->m_capacity)
//	{
//		int newcapacity = array->m_capacity * 2;
//		void** newspace = (void**)malloc(sizeof(void*) * newcapacity);
//		memcpy(newspace, array->pAddr, sizeof(void*) * array->m_size);
//		free(array->pAddr);
//		array->pAddr = newspace;
//		array->m_capacity = newcapacity;
//	}
//	for (int i = array->m_size - 1;i >= pos;i--)
//	{
//		array->pAddr[i + 1] = array->pAddr[i];
//	}
//	array->pAddr[pos] = data;
//	array->m_size++;
//}
////��������
//void foreach_DanamicArray(struct dynamicArray* array, void(*myprint)(void*))
//{
//	if (array == NULL)
//	{
//		return;
//	}
//	if (myprint == NULL)
//	{
//		return;
//	}
//	for (int i = 0;i < array->m_size;i++)
//	{
//		myprint(array->pAddr[i]);
//	}
//}
//
////λ��ɾ��
//void remove_posDynamicArray(struct dynamicArray* array, int pos)
//{
//	if (NULL == array)
//	{
//		return;
//	}
//	if (pos<0 || pos>array->m_size - 1)
//	{
//		return;
//	}
//	for (int i = pos;i < array->m_size - 1;i++)
//	{
//		array->pAddr[i] = array->pAddr[i + 1];
//	}
//	array->m_size--;
//}
//
////��ֵɾ��
//void remove_valueDynamicArray(struct dynamicArray* array, void* data, int(*mycompare)(void*, void*))
//{
//	if (NULL == array)
//	{
//		return;
//	}
//	if (NULL == data)
//	{
//		return;
//	}
//	for (int i = 0;i < array->m_size;i++)
//	{
//		if (mycompare(array->pAddr[i], data))
//		{
//			remove_posDynamicArray(array, i);
//			break;
//		}
//	}
//}
////ɾ������
//void destroy_DynamicArray(struct dynamicArray* array)
//{
//	if (array != 0)
//	{
//		free(array);
//		array == NULL;
//	}
//	if (array->pAddr != 0)
//	{
//		free(array->pAddr);
//		array->pAddr = NULL;
//	}
//}


//����
struct person
{
	char name[64];
	int age;
};

int mycompareperson(void* data1, void* data2)
{
	struct person* p1 = (struct person*)data1;
	struct person* p2 = (struct person*)data2;
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void myprintperson(void* data)
{
	struct person* p = (struct person*)data;
	printf("������%s, ���䣺%d\n", p->name, p->age);
}

int main()
{

	struct dynamicArray* array = init_DynamicArray(5);

	struct person p1 = { "��ɪ",20 };
	struct person p2 = { "��ħ",199 };
	struct person p3 = { "���",299 };
	struct person p4 = { "����",399 };
	struct person p5 = { "����",99 };
	struct person p6 = { "������",19 };
	printf("������%d, ��С��%d\n", array->m_capacity, array->m_size);

	insert_DynamicArray(array, 0, &p1);
	insert_DynamicArray(array, 0, &p2);
	insert_DynamicArray(array, 1, &p3);
	insert_DynamicArray(array, 0, &p4);
	insert_DynamicArray(array, -1, &p5);
	insert_DynamicArray(array, 2, &p6);

	foreach_DanamicArray(array, myprintperson);

	printf("������%d, ��С��%d\n", array->m_capacity, array->m_size);

	remove_posDynamicArray(array, 2);
	foreach_DanamicArray(array, myprintperson);
	printf("------------------------\n");
	remove_valueDynamicArray(array, &p1, mycompareperson);
	foreach_DanamicArray(array, myprintperson);

	destroy_DynamicArray(array);
	array = NULL;
	system("pause");
	return EXIT_SUCCESS;
}