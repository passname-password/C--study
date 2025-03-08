#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1024
struct sstack
{
	void * data[MAX];
	int m_size;
};
typedef void* seqstack;
//初始化
seqstack init_seqstack()
{
	struct sstack *mystack=malloc(sizeof(struct sstack));
	if (mystack == NULL)
	{
		return NULL;
	}
	memset(mystack->data, 0, sizeof(void*) * MAX);
	mystack->m_size = 0;
	return mystack;
}
//入栈
void push_seqstack(seqstack stack,void*data)
{
	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct sstack * mystack = stack;
	if (mystack->m_size >= MAX)
	{
		return;
	}
	mystack->data[mystack->m_size] = data;
	mystack->m_size++;
}
//出栈
void pop_seqstack(seqstack stack)
{
	if (stack == NULL)
	{
		return;
	}
	struct sstack* mystack = stack;
	if (mystack->m_size== 0)
	{
		return;
	}
	mystack->data[mystack->m_size - 1] = NULL;
	mystack->m_size--;
}
//返回栈顶
void* top_seqstack(	seqstack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct sstack* mystack = stack;
	if (mystack->m_size == 0)
	{
		return NULL;
	}
	return mystack->data[mystack->m_size-1];
}
//返回栈大小
int size_seqstack(seqstack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct sstack* mystack = stack;
	return mystack->m_size;
}
//判断是否为空
int isenpty_seqstack(seqstack stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	struct sstack* mystack = stack;
	if (mystack->m_size == 0)
	{
		return 1;
	}
	return 0;
}
//销毁
void destroy_seqstack(seqstack stack)
{
	if (stack == NULL)
	{
		return;
	}
	free(stack);
	stack = NULL;
}

//测试
struct person 
{
	char name[64];
	int age;
};
void test()
{
	seqstack stack = init_seqstack();
	struct person p1 = { "aaa",10 };
	struct person p2 = { "bbb",20 };
	struct person p3 = { "ccc",30 };
	struct person p4 = { "ddd",40 };
	struct person p5 = { "fff",50 };
	printf("%d\n", size_seqstack(stack));
	push_seqstack(stack, &p1);
	push_seqstack(stack, &p2);
	push_seqstack(stack, &p3);
	push_seqstack(stack, &p4);
	push_seqstack(stack, &p5);
	printf("%d\n", size_seqstack(stack));

	while (isenpty_seqstack(stack) == 0)
	{
		struct person* p = top_seqstack(stack);
		printf("%s,%d\n", p->name, p->age);
		pop_seqstack(stack);
		printf("%d\n", size_seqstack(stack));
	}
	printf("%d\n",size_seqstack(stack));

}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}