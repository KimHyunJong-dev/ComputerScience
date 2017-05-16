// DoubleLinkList.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node
{
	int Data;
	node * PrevNode;
	node * NextNode;
}Node;

Node *CreateNode(int NewData);
void DestroyNode(Node*node);

void AppendNode(Node** Head, Node *NewNode);
void InsertAfter(Node* current, Node* NewNode);

void RemoveNode(Node** node, Node* remove);
Node * GetNodeAt(Node* Head, int Location);
int GetNodeCount(Node* Head);



Node *CreateNode(int NewData)
{
	Node * NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;

	NewNode->NextNode = NULL;
	NewNode->PrevNode = NULL;

	return NewNode;
}

void DestroyNode(Node* node)
{
	free(node);
}


void AppendNode(Node** Head, Node *NewNode)
{
	// Head �� NULL  �̸� ���ο� ��� �߰�
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// Tail ��, �ǳ��� ��带 �߰�.
		Node *Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;

		// ���� ������ ������ �� PrevNode �� ����Ų��. 
		Tail->PrevNode = Tail;
	}
}

// ��� ����.
void InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
	}

	Current->NextNode = NewNode;
}


void RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;

		if ((*Head) != NULL)
		{
			(*Head)->PrevNode = NULL;
		}
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != NULL) 
		{
			Remove->PrevNode->NextNode = Temp->NextNode;
		}

		if (Remove->NextNode != NULL)
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;
			Remove->PrevNode = NULL;
			Remove->NextNode = NULL;
		}
	}
}


Node * GetNodeAt(Node* Head, int Location)
{
	Node * Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	return Current;
}

int GetNodeCount(Node* Head)
{
	int Count = 0;

	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}




int main()
{
	int i = 0;
	int Count = 0;

	Node * List = NULL;
	Node * Current = NULL;
	Node * NewNode = NULL;

	for (i = 0; i < 10; i++)
	{
		NewNode = CreateNode(i);
		AppendNode(&List, NewNode);
	}

	Count = GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(List, i);
		printf("Double List[%d]: Data %d\n", i, Current->Data);
	}

	printf("Insert 300000 Data\n");

	Current = GetNodeAt(List, 2);
	NewNode = CreateNode(300000);
	InsertAfter(Current, NewNode);

	Count = GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(List, i);
		printf("Double List[%d]: Data %d\n", i, Current->Data);
	}

	printf("Destroying List Data\n");
	Count = GetNodeCount(List);
	
	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(List, 0);

		if (Current != NULL)
		{
			RemoveNode(&List, Current);
			DestroyNode(Current);

		}
	}

	char ch;
	printf("\n�ƹ�Ű�� ���缼��~");
	ch = cin.get();
	return 0;
}

