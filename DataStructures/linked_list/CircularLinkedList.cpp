// CircularLinkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	// Head 가 NULL  이면 새로운 노드 추가
	if (*Head == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		// Tail 즉, 맨끝에 노드를 추가.
		Node *Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
	}
}

// 노드 삽입.
void InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}


void RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		*Head = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		Remove->PrevNode->NextNode = Temp->NextNode;
		Remove->NextNode->PrevNode = Temp->PrevNode;
		
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
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
		if (Current == Head)
		{
			break;
		}
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
		printf("Circular Linked List[%d]: Data %d\n", i, Current->Data);
	}
	
	printf("Insert 300000 Data\n");

	Current = GetNodeAt(List, 2);
	NewNode = CreateNode(300000);
	InsertAfter(Current, NewNode);

	Count = GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(List, i);
		printf("Circular Linked  List[%d]: Data %d\n", i, Current->Data);
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
	printf("\n아무키나 누루세요~");
	ch = cin.get();
	return 0;
}

