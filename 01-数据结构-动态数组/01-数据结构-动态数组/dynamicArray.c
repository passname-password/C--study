#include"dynamicArray.h"


//动态初始化
struct dynamicArray* init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}
	struct dynamicArray* array = (struct dynamicArray*)malloc(sizeof(struct dynamicArray));
	if (array == NULL)
	{
		return NULL;
	}
	array->pAddr = (void**)malloc(sizeof(void*) * capacity);
	array->m_capacity = capacity;
	array->m_size = 0;
	return array;
}
//插入数组
void insert_DynamicArray(struct dynamicArray* array, int pos, void* data)
{
	if (array == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	if (pos<0 || pos>array->m_size)
	{
		pos = array->m_size;
	}
	if (array->m_size == array->m_capacity)
	{
		int newcapacity = array->m_capacity * 2;
		void** newspace = (void**)malloc(sizeof(void*) * newcapacity);
		memcpy(newspace, array->pAddr, sizeof(void*) * array->m_size);
		free(array->pAddr);
		array->pAddr = newspace;
		array->m_capacity = newcapacity;
	}
	for (int i = array->m_size - 1;i >= pos;i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}
	array->pAddr[pos] = data;
	array->m_size++;
}
//遍历数组
void foreach_DanamicArray(struct dynamicArray* array, void(*myprint)(void*))
{
	if (array == NULL)
	{
		return;
	}
	if (myprint == NULL)
	{
		return;
	}
	for (int i = 0;i < array->m_size;i++)
	{
		myprint(array->pAddr[i]);
	}
}

//位置删除
void remove_posDynamicArray(struct dynamicArray* array, int pos)
{
	if (NULL == array)
	{
		return;
	}
	if (pos<0 || pos>array->m_size - 1)
	{
		return;
	}
	for (int i = pos;i < array->m_size - 1;i++)
	{
		array->pAddr[i] = array->pAddr[i + 1];
	}
	array->m_size--;
}

//按值删除
void remove_valueDynamicArray(struct dynamicArray* array, void* data, int(*mycompare)(void*, void*))
{
	if (NULL == array)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	for (int i = 0;i < array->m_size;i++)
	{
		if (mycompare(array->pAddr[i], data))
		{
			remove_posDynamicArray(array, i);
			break;
		}
	}
}
//删除数组
void destroy_DynamicArray(struct dynamicArray* array)
{
	if (array== NULL)
	{
		return;
	}
	if (array->pAddr !=NULL)
	{
		free(array->pAddr);
		array->pAddr = NULL;
	}
	free(array);
	array = NULL;
}
