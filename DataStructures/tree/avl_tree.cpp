// avl_tree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define RR 1
#define LL 2
#define MAX 100
#define TRUE 1
#define FALSE 0

// AVL Tree Node
typedef struct _NODE {
	char Data;
	int Balance;
	struct _NODE *Left;
	struct _NODE *Right;
} NODE;


//큐
NODE *Queue[MAX]; // 큐를 배열로 선언
int Front, Rear;

void InitializeQueue(void);
void Put(NODE *);
NODE *Get(void);
int IsQueueEmpty(void);

// 큐 초기화 함수
void InitializeQueue(void)
{
	Front = Rear = 0;
}

void Put(NODE *ptrNode)
{
	Queue[Rear] = ptrNode;
	Rear = (Rear++) % MAX;

}

NODE *Get(void)
{
	NODE *ptrNode;

	if (!IsQueueEmpty()) {
		ptrNode = Queue[Front];
		Front = (Front++) % MAX;
		return ptrNode;
	}

	else
		printf("Queue is Empty\n");

	return NULL;
}

int IsQueueEmpty(void)
{
	if (Rear == Front)
		return TRUE;

	else
		return FALSE;
}
//===============================
NODE *HeadNode;
NODE *ParentNode;
NODE *GrandNode;
NODE *ChildNode;
NODE *BigNode;

void InitializeTree(void);
void InsertNode(int);
int IsBalance(void);
void RR_Rotate(void);
void LL_Rotate(void);
void Level_Traverse(NODE *);
void Visit(NODE *);

// 외부 함수 정의
extern void InitializeQueue(void);
extern void Put(NODE *);
extern NODE *Get(void);
extern int IsQueueEmpty(void);

// 트리 초기화
void InitializeTree(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	HeadNode->Left = HeadNode;
	HeadNode->Right = HeadNode;
	BigNode = HeadNode;
}

// 새로운 노드 삽입
void InsertNode(int Data)
{
	NODE *tmpNode;
	NODE *ptrNode = (NODE *)malloc(sizeof(NODE));

	ptrNode->Data = Data;
	ptrNode->Balance = 0;
	ptrNode->Left = HeadNode;
	ptrNode->Right = HeadNode;

	if (HeadNode->Right == HeadNode) {  // 첫 번째 노드인 경우
		HeadNode->Right = ptrNode;
		HeadNode->Left = ptrNode;
	}

	else {
		GrandNode = HeadNode;
		ParentNode = HeadNode;
		ChildNode = HeadNode->Right;
		tmpNode = HeadNode->Right;

		while (tmpNode != HeadNode) {
			ChildNode = tmpNode;

			if (ChildNode->Data > ptrNode->Data) {
				BigNode = GrandNode;

				GrandNode = ParentNode;
				ParentNode = ChildNode;
				tmpNode = tmpNode->Left;
			}

			else {
				BigNode = GrandNode;
				GrandNode = ParentNode;
				ParentNode = ChildNode;
				tmpNode = tmpNode->Right;
			}
		}

		ChildNode = ptrNode;

		// 새로운 노드 삽입
		if (ParentNode->Data > ChildNode->Data) {
			ParentNode->Left = ChildNode;
			ParentNode->Balance++;

			if (GrandNode != HeadNode)
				GrandNode->Balance++;

			if (BigNode != HeadNode)
				BigNode->Balance++;
		}

		else {
			ParentNode->Right = ChildNode;
			ParentNode->Balance--;

			if (GrandNode != HeadNode)
				GrandNode->Balance--;

			if (BigNode != HeadNode)
				BigNode->Balance--;
		}

		switch (IsBalance()) {
		case RR:
			RR_Rotate();
			break;

		case LL:
			LL_Rotate();
			break;

		default:
			break;
		}
	}
}

// 회전 필요 여부 확인
int IsBalance(void)
{
	int ret = 0;
	int LeftCnt = 0;
	int RightCnt = 0;

	NODE *ptrNode;
	ptrNode = HeadNode->Right;

	InitializeQueue();
	Put(ptrNode);

	while (!IsQueueEmpty()) {
		ptrNode = Get();

		if (ptrNode->Balance > 1) {
			ret = LL;
			break;
		}

		else if (ptrNode->Balance < -1) {
			ret = RR;
			break;
		}

		if (ptrNode->Left != HeadNode) {
			Put(ptrNode->Left);
			LeftCnt++;
			RightCnt = 0;
		}

		if (ptrNode->Right != HeadNode) {
			Put(ptrNode->Right);
			RightCnt++;
			LeftCnt = 0;
		}
	}

	return ret;
}

// RR 회전
void RR_Rotate(void)
{
	ParentNode = GrandNode->Right;
	ChildNode = ParentNode->Right;

	if (GrandNode->Balance == -2) {
		BigNode->Right = ParentNode;
		ParentNode->Left = GrandNode;
		GrandNode->Left = HeadNode;
		GrandNode->Right = HeadNode;
	}

	BigNode->Balance++;

	ParentNode->Balance = 0;
	GrandNode->Balance = 0;
	ChildNode->Balance = 0;
}

// LL 회전
void LL_Rotate(void)
{
	ParentNode = GrandNode->Left;
	ChildNode = ParentNode->Left;

	if (GrandNode->Balance == 2) {
		BigNode->Left = ParentNode;
		ParentNode->Right = GrandNode;
		GrandNode->Left = HeadNode;
		GrandNode->Right = HeadNode;
	}

	BigNode->Balance--;

	ParentNode->Balance = 0;
	GrandNode->Balance = 0;
	ChildNode->Balance = 0;
}

// 큐를 이용한 트리 순회 알고리즘
void Level_Traverse(NODE *ptrNode)
{
	InitializeQueue();
	Put(ptrNode);

	while (!IsQueueEmpty()) {
		ptrNode = Get();
		printf(" -> ");
		Visit(ptrNode);

		if (ptrNode->Left != HeadNode)
			Put(ptrNode->Left);

		if (ptrNode->Right != HeadNode)
			Put(ptrNode->Right);
	}
}

void Visit(NODE *ptrNode)
{
	printf("%2d ", ptrNode->Data);
}

int main(void)
{
	InitializeTree();
	printf("노드 30, 20, 40, 10 삽입 \n");
	InsertNode(30);
	InsertNode(20);
	InsertNode(40);
	InsertNode(10);
	Level_Traverse(HeadNode->Right);
	printf("\n===========================\n");
	printf("노드 5 삽입 \n");
	InsertNode(5);
	Level_Traverse(HeadNode->Right);

	char ch;
	printf("\n아무키나 누루세요~");
	ch = cin.get();
	
	return 0;
}
