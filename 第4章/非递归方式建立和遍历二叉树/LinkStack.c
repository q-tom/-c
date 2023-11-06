#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkStack.h"
LinkStack SetNullStack_Link() /*��������ͷ���Ŀ���ջ*/
{
	LinkStack top = (LinkStack)malloc(sizeof(struct Node));
	if (top != NULL) top->next = NULL;
	else printf("Alloc failure");
	return top; /*����ջ��ָ��*/
}
int IsNullStack_link(LinkStack top)//�ж�һ����ջ�Ƿ�Ϊ��
{
	if (top->next == NULL)
		return 1;
	else
		return 0;
}
void Push_link(LinkStack top, DataTypeStack x)//��ջ
{
	PNode p;
	p = (PNode)malloc(sizeof(struct Node));
	if (p == NULL)
		printf("Alloc failure");
	else
	{
		p->data = x;
		p->next = top->next;
		top->next = p;
	}
}
void Pop_link(LinkStack top)// ɾ��ջ��Ԫ��
{
	PNode p;
	if (top->next == NULL)
		printf("it is empty stack!");
	else
	{
		p = top->next;
		top->next = p->next;
		free(p);
	}
}
DataTypeStack Pop_seq_return(LinkStack top)// ɾ��ջ��Ԫ��
{
	PNode p; DataTypeStack temp;
	if (top->next == NULL)
	{
		printf("It is empty stack!");
		return 0;
	}
	else
	{
		p = top->next;
		top->next = p->next;
		temp = p->data;
		free(p);
		return temp;
	}
}
DataTypeStack Top_link(LinkStack top)// ��ջ��Ԫ�ص�ֵ
{
	if (top->next == NULL)
	{
		printf("It is empty stack!");
		return 0;
	}
	else
		return top->next->data;
}