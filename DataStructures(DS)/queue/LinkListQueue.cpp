// LinkListQueue.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

typedef struct Node {
	char* Data;
	struct Node* NextNode;
}Node;

typedef struct LinkedQueue {
	Node* Front; // ������ ����Ű�� ������
	Node* Rear;  // �Ĵ��� ����Ű�� ������
	int Count;   // Node�� ������ ����
} LinkedQueue;

void CreateQueue(LinkedQueue** Queue); // Queue ����
void DestroyQueue(LinkedQueue* Queue); // Queue �ı� - Queue�� �����ϴ� ��� Node�� ���� �� Queue �ı�

Node* CreateNode(char* Data);
void DestroyNode(Node* _Node);

void Enqueue(LinkedQueue* Queue, Node* NewNode);
// Queue�� ��� ����
// Node ������ ���� Queue�� Enqueue �� �ϴ� ��� LQ_Enqueue(Queue,LQ_CreateNode("XXX"))

Node* Dequeue(LinkedQueue* Queue);

// Queue�� Dequeue ����
// Dequeue�� ���� Dequeue�� Node�� �ı��Ϸ���
// LQ_DestroyNode(LQ_Dequeue(Queue))

int IsEmpty(LinkedQueue* Queue); // Queue�� ����ִ� ���� Ȯ��.

void PrintQueue(LinkedQueue* Queue); // Queue�� ��� ������ �����͸� ��� - ��ü����


// Queue ����
void CreateQueue(LinkedQueue** Queue) 
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;

}

// Queue �ı� - Queue�� �����ϴ� ��� Node�� ���� �� Queue �ı�
void DestroyQueue(LinkedQueue* Queue) 
{
	while (!(IsEmpty(Queue))) {
		Node* Dequeued = Dequeue(Queue);
		DestroyNode(Dequeued);
	}
	free(Queue);
}


Node* CreateNode(char* Data) 
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(Data) + 1);
	strcpy(NewNode->Data, Data);

	NewNode->NextNode = NULL;

	return NewNode;
}


void DestroyNode(Node* _Node) {
	free(_Node->Data);
	free(_Node);
}

// Queue�� ��� ����
// Node ������ ���� Queue�� Enqueue �� �ϴ� ��� LQ_Enqueue(Queue,LQ_CreateNode("XXX"))
void Enqueue(LinkedQueue* Queue, Node* NewNode) 
{
	// ť�� ��尡 ���� ���
	if (LQ_IsEmpty(Queue))
	{
		// ���ܰ� �Ĵ� ��� NewNode�� ����Ű�� �Ѵ�.
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else
	{
		// Rear�� ��ũ�� �����Ѵ�.
		// ���� Rear�� NextNode�� NewNode�� �ٲٰ�
		// Rear�� ���ο� NewNode�� ����Ű�� ��.

		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}

	// ������ ����� ������ ����
	(Queue->Count)++;
	
	printf("  - Data : %s - Node Enqueued....\n", NewNode->Data);
	printf("  - Current Queue->Count = %d\n", Queue->Count);
}

// Queue�� Dequeue ����
// Dequeue�� ���� Dequeue�� Node�� �ı��Ϸ���
// LQ_DestroyNode(LQ_Dequeue(Queue))
Node* Dequeue(LinkedQueue* Queue) 
{
	Node* Front = Queue->Front; // Front�� ����Ű�� Node�� ����
								// Queue��尡 �Ѱ� ��������
	if (Queue->Front->NextNode == NULL)
	{
		// Queue�� Front�� Rear�� NULL�� .. Front == NULL -> Empty ����
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
	{
		Queue->Front = Queue->Front->NextNode;
	}

	(Queue->Count)--;
	printf("  - Data : %s - Node Dequeue....\n", Front->Data);
	printf("  - Current Queue->Count = %d\n", Queue->Count);
	return Front;
}

// Queue�� ����ִ� ���� Ȯ��.
int IsEmpty(LinkedQueue* Queue) 
{
	return (Queue->Front == NULL);
}


// Queue�� ��� ������ �����͸� ��� - ��ü����
void LQ_PrintQueue(LinkedQueue* Queue) 
{
	Node* Printed = Queue->Front;

	printf(" *** Current Queue's Nodes *** \n");
	while (Printed != NULL)
	{
		printf("  %s  ->", Printed->Data);
		Printed = Printed->NextNode;
	}
	printf("\n");
	printf("\n");
}



int main()
{
	LinkedQueue* Queue;

	CreateQueue(&Queue); // ť ����

	// Enqueue Ȯ��
	Enqueue(Queue, CreateNode("AA"));
	Enqueue(Queue, CreateNode("BB"));
	Enqueue(Queue, CreateNode("CC"));

	PrintQueue(Queue);

	// Dequeue Ȯ��
	DestroyNode(Dequeue(Queue));
	PrintQueue(Queue);

	DestroyQueue(Queue);

	puts("10000");
	puts("");
	// ����� Ȯ��
	CreateQueue(&Queue);

	Enqueue(Queue, CreateNode("DD"));
	Enqueue(Queue, CreateNode("EE"));
	PrintQueue(Queue);
	DestroyQueue(Queue);

	char ch;
	printf("\n�ƹ�Ű�� ���缼��~");
	ch = cin.get();
    return 0;
}

