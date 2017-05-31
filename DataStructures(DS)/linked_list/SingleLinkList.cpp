// SingleLinkList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node
{
	int Data;
	struct node * NextNode;
}Node;

Node *CreateNode(int NewData);
void DestroyNode(Node*node);

void AppendNode(Node** Head, Node *NewNode);
void InsertNewHead(Node** Head, Node* NewHead);
void InsertAfter(Node* current, Node* NewNode);

void RemoveNode(Node** node, Node* remove);
Node * GetNodeAt(Node* Head, int Location);
int GetNodeCount(Node* Head);



Node *CreateNode(int NewData)
{
	Node * NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* node)
{
	free(node);
}


void AppendNode(Node** Head, Node *NewNode)
{
	// Head 가 NULL  이면 새로운 노드 추가
	if ( *Head == NULL ) 
	{
		*Head = NewNode;
	}
	else
	{
		// Tail 즉, 맨끝에 노드를 추가.
		Node *Tail = *Head;		
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

// 노드 삽입.
void InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = NewNode->NextNode;
	Current->NextNode = NewNode;
}

void InsertNewHead(Node** Head, Node* NewHead)
{
	if ( (*Head) == NULL)
	{
		*Head = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		*Head = NewHead;
	}
}


void RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove) 
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current!=NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL) 
		{
			Current->NextNode = Remove->NextNode;
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
		AppendNode(&List,NewNode);
	}

	NewNode = CreateNode(-1);
	InsertNewHead(&List, NewNode);

	NewNode = CreateNode(-2);
	InsertNewHead(&List, NewNode);

	Count = GetNodeCount(List);

	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(List, i);
		printf("List[%d]: Data %d\n", i, Current->Data);
	}
	
	Current = GetNodeAt(List, 2);
	NewNode = CreateNode(3000);

	InsertAfter(Current, NewNode);

	Count = GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(List, i);
		printf("List[%d]: Data %d\n", i, Current->Data);
	}

	printf("List Remove");
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

