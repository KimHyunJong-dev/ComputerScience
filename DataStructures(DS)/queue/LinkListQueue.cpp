// LinkListQueue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	Node* Front; // 전단을 가리키는 포인터
	Node* Rear;  // 후단을 가리키는 포인터
	int Count;   // Node의 개수를 가짐
} LinkedQueue;

void CreateQueue(LinkedQueue** Queue); // Queue 생성
void DestroyQueue(LinkedQueue* Queue); // Queue 파괴 - Queue에 존재하는 모든 Node를 해제 후 Queue 파괴

Node* CreateNode(char* Data);
void DestroyNode(Node* _Node);

void Enqueue(LinkedQueue* Queue, Node* NewNode);
// Queue에 노드 삽입
// Node 생성과 동시 Queue에 Enqueue 를 하는 경우 LQ_Enqueue(Queue,LQ_CreateNode("XXX"))

Node* Dequeue(LinkedQueue* Queue);

// Queue에 Dequeue 수행
// Dequeue와 동시 Dequeue된 Node를 파괴하려면
// LQ_DestroyNode(LQ_Dequeue(Queue))

int IsEmpty(LinkedQueue* Queue); // Queue가 비어있는 여부 확인.

void PrintQueue(LinkedQueue* Queue); // Queue의 모든 노드들의 데이터를 출력 - 자체제작


// Queue 생성
void CreateQueue(LinkedQueue** Queue) 
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;

}

// Queue 파괴 - Queue에 존재하는 모든 Node를 해제 후 Queue 파괴
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

// Queue에 노드 삽입
// Node 생성과 동시 Queue에 Enqueue 를 하는 경우 LQ_Enqueue(Queue,LQ_CreateNode("XXX"))
void Enqueue(LinkedQueue* Queue, Node* NewNode) 
{
	// 큐에 노드가 없을 경우
	if (LQ_IsEmpty(Queue))
	{
		// 전단과 후단 모두 NewNode를 가리키게 한다.
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else
	{
		// Rear의 링크를 조정한다.
		// 기존 Rear의 NextNode를 NewNode로 바꾸고
		// Rear는 새로운 NewNode를 가리키게 함.

		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}

	// 수행후 노드의 개수를 증가
	(Queue->Count)++;
	
	printf("  - Data : %s - Node Enqueued....\n", NewNode->Data);
	printf("  - Current Queue->Count = %d\n", Queue->Count);
}

// Queue에 Dequeue 수행
// Dequeue와 동시 Dequeue된 Node를 파괴하려면
// LQ_DestroyNode(LQ_Dequeue(Queue))
Node* Dequeue(LinkedQueue* Queue) 
{
	Node* Front = Queue->Front; // Front가 가리키는 Node를 저장
								// Queue노드가 한개 남았을시
	if (Queue->Front->NextNode == NULL)
	{
		// Queue의 Front와 Rear를 NULL로 .. Front == NULL -> Empty 상태
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

// Queue가 비어있는 여부 확인.
int IsEmpty(LinkedQueue* Queue) 
{
	return (Queue->Front == NULL);
}


// Queue의 모든 노드들의 데이터를 출력 - 자체제작
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

	CreateQueue(&Queue); // 큐 생성

	// Enqueue 확인
	Enqueue(Queue, CreateNode("AA"));
	Enqueue(Queue, CreateNode("BB"));
	Enqueue(Queue, CreateNode("CC"));

	PrintQueue(Queue);

	// Dequeue 확인
	DestroyNode(Dequeue(Queue));
	PrintQueue(Queue);

	DestroyQueue(Queue);

	puts("10000");
	puts("");
	// 재생성 확인
	CreateQueue(&Queue);

	Enqueue(Queue, CreateNode("DD"));
	Enqueue(Queue, CreateNode("EE"));
	PrintQueue(Queue);
	DestroyQueue(Queue);

	char ch;
	printf("\n아무키나 누루세요~");
	ch = cin.get();
    return 0;
}

