#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Linknode
{
	struct Linknode* next;
};
struct Llist
{
	struct Linknode pheader;
	int m_size;
};
typedef void* Linklist;

//初始化链表
Linklist init_link()
{
	struct Llist* mylist = malloc(sizeof(struct Llist));
	if (mylist == NULL)
	{
		return NULL;
	}
	mylist->pheader.next = NULL;
	mylist->m_size = 0;
	return mylist;
}
//插入
void insert_list(Linklist list,int pos,void *data)
{
	if (list == NULL)
	{
		return ;
	}
	if (data ==NULL)
	{
		return;
	}
	struct Llist* mylist = list;
	if (pos<0 || pos>mylist->m_size - 1)
	{
		pos = mylist->m_size;
	}
	struct Linknode* pdel = data;
	struct Linknode* pcurrent = &mylist->pheader;
	for (int i = 0;i < pos;i++)
	{
		pcurrent = pcurrent->next;
	}
	pdel->next = pcurrent->next;
	pcurrent->next = pdel;
	mylist->m_size++;
}
//遍历
void for_list(Linklist list, void(*printf)(void*))
{
	if (list == NULL)
	{
		return  ;
	}
	struct Llist* mylist = list;
	struct Linknode* pcurrent = mylist->pheader.next;
	for (int i = 0;i < mylist->m_size;i++)
	{
		printf(pcurrent);
		pcurrent = pcurrent->next;
	}

}
//删除
void del_list(Linklist list, int pos)
{
	if (list == NULL)
	{
		return ;
	}
	struct Llist* mylist = list;
	if (pos<0||pos>mylist->m_size-1)
	{
		return;
	}

	struct Linknode* pcurrent = &mylist->pheader;
	for (int i = 0;i < pos;i++)
	{
		pcurrent = pcurrent->next;
	}
	struct Linknode* del = pcurrent->next;
	pcurrent->next = del->next;
	mylist->m_size--;
}

//销毁
void destroy_list(Linklist list)
{
	if (list == NULL)
	{
		return;
	}
	free(list);
	list = NULL;
}

//测试
struct person
{
	void* node;
	char name[64];
	int age;
};
void print(void * data)
{
	struct person* p = data;
	printf("%s,%d\n", p->name, p->age);
}
void test()
{
	Linklist mylist = init_link();
	struct person p1 = { NULL,"aaa",10 };
	struct person p2 = { NULL,"bbb",20 };
	struct person p3 = { NULL,"ccc",30 };
	struct person p4 = { NULL,"ddd",40 };
	struct person p5 = { NULL,"fff",50 };

	insert_list(mylist, 0, &p1);
	insert_list(mylist, 2, &p2);
	insert_list(mylist, 1, &p3);
	insert_list(mylist, 0, &p4);
	insert_list(mylist, -1, &p5);
	for_list(mylist,print);

	printf("-----------------\n");
	del_list(mylist, 2);
	for_list(mylist, print);

	destroy_list(mylist);
	mylist = NULL;
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}
