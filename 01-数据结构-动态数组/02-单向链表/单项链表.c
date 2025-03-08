#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ڵ�ṹ��
struct Linknode
{//������
	void* data;
	//ָ����
	struct Linknode* next;
};

struct Llist
{//ͷ�ڵ�
	struct Linknode  pheader;
	//������
	int m_size;
};

typedef void* Linklist;
//��ʼ������
Linklist init_Linklist()
{
	struct Llist* mylist = malloc(sizeof(struct Llist));
	if (mylist == NULL)
	{
		return NULL;
	}

	mylist->pheader.data = NULL;
	mylist->pheader.next = NULL;
	mylist->m_size = 0;
	return mylist;
}

//����
void insert_Linklist(Linklist list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct Llist* mylist = list;
	if (pos < 0 || pos>mylist->m_size)
	{
		pos = mylist->m_size;
	}
	struct Linknode * pcurrent = &mylist->pheader;
	for (int i = 0;i < pos;i++)
	{
		pcurrent = pcurrent->next;
	}
	struct Linknode* newnode = malloc(sizeof(struct Linknode));
	newnode->data = data;
	newnode->next = NULL;

	newnode->next = pcurrent->next;
	pcurrent->next = newnode;

	mylist->m_size++;
}
//����
void foreach_Linklist(Linklist list,void(*myprint)(void *))
{
	if (list == NULL)
	{
		return;
	}
	struct Llist* mylist = list;
	struct Linknode* pcurrent = mylist->pheader.next;
	for (int i =0;i < mylist->m_size;i++)
	{
		myprint(pcurrent->data);
		pcurrent = pcurrent->next;
	}
}
//��λ��ɾ��
void remove_posLinklist(Linklist list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct Llist* mylist = list;
	if (pos<0 || pos>mylist->m_size - 1)
	{
		return;
	}
	struct Linknode* pcurrent = &mylist->pheader;
	for (int i = 0;i < pos;i++)
	{
		pcurrent = pcurrent->next;
	}
	struct Linknode* pdel = pcurrent->next;
	pcurrent->next = pdel->next;
	free(pdel);
	pdel = NULL;
	mylist->m_size--;
}

//��ֵɾ��
void remove_valueLinklist(Linklist list, void* data, int(*compare)(void*, void*))
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct Llist* mylist = list;
	struct Linknode* pre = &mylist->pheader;
	struct Linknode* pcurrent = pre->next;
	for (int i = 0;i < mylist->m_size;i++)
	{
		if (compare(pcurrent->data, data))
		{
			pre->next = pcurrent->next;
			free(pcurrent);
			pcurrent = NULL;
			mylist->m_size--;
			break;
		}
		pre = pcurrent;
		pcurrent = pcurrent->next;
	}
}
//�������
void clear_Linklist( Linklist list)
{
	if (list == NULL)
	{
		return;
	}
	struct Llist* mylist = list;
	struct Linknode* pcurrent = mylist->pheader.next;
	for (int i = 0;i < mylist->m_size;i++)
	{
		struct Linknode* pnext = pcurrent->next;
		free(pcurrent);
		pcurrent = pnext;
	}
	mylist->pheader.next = NULL;
	mylist->m_size = 0;
}
//����������
int size_Linklist(Linklist list)
{
	if (list == NULL)
	{
		return;
	}
	struct Llist* mylist = list;
	return mylist->m_size;
}
//��������
void destroy_Linklist(Linklist list)
{
	if (list == NULL)
	{
		return;
	}
	clear_Linklist(list);
	free(list);
	list = NULL;
}


//����
struct person
{
	char name[64];
	int age;
};
void print(void * data)
{

	struct person* p = data;
	printf("������%s,���䣺%d\n", p->name, p->age);
}
int compare(void *data1, void* data2)
{
	struct person* p1 = data1;
	struct person* p2 = data2;
	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}
void test01()
{
	struct person p1 = { "��ɪ",20 };
	struct person p2 = { "��ħ",199 };
	struct person p3 = { "���",299 };
	struct person p4 = { "����",399 };
	struct person p5 = { "����",99 };
	struct person p6 = { "������",19 };
	
	Linklist mylist = init_Linklist();
	
	printf("%d\n", size_Linklist(mylist));
	insert_Linklist(mylist, 0, &p1);
	insert_Linklist(mylist, 0, &p2);
	insert_Linklist(mylist, -1, &p3);
	insert_Linklist(mylist, 0, &p4);
	insert_Linklist(mylist, 1, &p5);
	insert_Linklist(mylist, 0, &p6);

	foreach_Linklist(mylist, print);
	printf("%d\n", size_Linklist(mylist));
	printf("-------------------------------\n");

	remove_posLinklist(mylist, 0);
	foreach_Linklist(mylist, print);
	printf("%d\n", size_Linklist(mylist));
	printf("-------------------------------\n");
	remove_valueLinklist(mylist, &p2,compare);
	foreach_Linklist(mylist, print);
	printf("%d\n", size_Linklist(mylist));

	clear_Linklist(mylist);
	printf("%d\n", size_Linklist(mylist));

	destroy_Linklist(mylist);
	mylist = NULL;
}
int main()
{
	test01();

	system("pause");
	return EXIT_SUCCESS;
}

