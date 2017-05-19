// 23_tree.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

#define TRUE 1
#define FALSE 0
#define RR 1
#define LL 2

//==23 TREE Node=======
typedef struct _NODE {
	char LeftData;
	char RightData;
	struct _NODE *Left;
	struct _NODE *Mid;
	struct _NODE *Right;
} NODE;

// ť=====
#define MAX 100
NODE *Queue[MAX]; // ť�� �迭�� ����
int Front, Rear;

void InitializeQueue(void);
void Put(NODE *);
NODE *Get(void);
int IsQueueEmpty(void);

// ť �ʱ�ȭ �Լ�
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
// ť ====================

//23 Tree
NODE *HeadNode;
NODE *ParentNode;


void InitializeTree(void);
void InsertNode(int);
NODE *SplitNode(NODE *, NODE *);
void Level_Traverse(NODE *);
void Visit(NODE *);


// Ʈ�� �ʱ�ȭ
void InitializeTree(void)
{
	HeadNode = (NODE *)malloc(sizeof(NODE));
	HeadNode->Left = HeadNode;
	HeadNode->Mid = HeadNode;
	HeadNode->Right = HeadNode;
}

// ���ο� ��� ����
void InsertNode(int Data)
{
	int FlagSplit = 0;
	NODE *tmpNode;

	if (HeadNode->Right == HeadNode) {  // ù ��° ����� ���
		NODE *ptrNode = (NODE *)malloc(sizeof(NODE));

		ptrNode->LeftData = Data;
		ptrNode->RightData = -1;
		ptrNode->Left = HeadNode;
		ptrNode->Mid = HeadNode;
		ptrNode->Right = HeadNode;

		HeadNode->Right = ptrNode;
		HeadNode->Mid = ptrNode;
		HeadNode->Left = ptrNode;
	}

	else {
		tmpNode = HeadNode->Left;
		ParentNode = HeadNode;

		while (1) {
			if (tmpNode->LeftData < Data) {
				if (tmpNode->RightData == -1)
					break;

				else {
					if (tmpNode->Left == HeadNode) {
						FlagSplit = 1;
						break;
					}

					else {
						if (tmpNode->RightData < Data) {
							if (tmpNode->Mid == HeadNode)
								break;

							else {
								ParentNode = tmpNode;
								tmpNode = tmpNode->Mid;
							}
						}

						else {
							if (tmpNode->Mid == HeadNode)
								break;

							else {
								ParentNode = tmpNode;
								tmpNode = tmpNode->Mid;
							}
						}
					}
				}
			}

			else {
				if (tmpNode->Left == HeadNode) {
					if (tmpNode->RightData == -1)
						FlagSplit = 0;

					else
						FlagSplit = 1;

					break;
				}
				else {
					ParentNode = tmpNode;
					tmpNode = tmpNode->Left;
				}
			}
		}

		if (tmpNode->RightData == -1 && FlagSplit == 0) {
			if (tmpNode->LeftData < Data)
				tmpNode->RightData = Data;

			else {
				tmpNode->RightData = tmpNode->LeftData;
				tmpNode->LeftData = Data;
			}
		}

		else if (FlagSplit > 0) {
			NODE *ptrNode = (NODE *)malloc(sizeof(NODE));

			ptrNode->LeftData = Data;
			ptrNode->RightData = -1;
			ptrNode->Left = HeadNode;
			ptrNode->Mid = HeadNode;
			ptrNode->Right = HeadNode;

			if (FlagSplit == 1) {
				ParentNode->Left = SplitNode(tmpNode, ptrNode);
				tmpNode = ParentNode->Left;

				if (ParentNode->RightData == -1) {
					ParentNode->RightData = ParentNode->LeftData;
					ParentNode->LeftData = tmpNode->LeftData;
					ParentNode->Right = ParentNode->Mid;
					ParentNode->Mid = tmpNode->Mid;
					ParentNode->Left = tmpNode->Left;
				}
			}
		}
	}
}

// ť�� �̿��� Ʈ�� ��ȸ �˰���
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

		if (ptrNode->Mid != HeadNode)
			Put(ptrNode->Mid);

		if (ptrNode->Right != HeadNode)
			Put(ptrNode->Right);
	}
}

void Visit(NODE *ptrNode)
{
	printf("%2d ", ptrNode->LeftData);

	if (ptrNode->RightData != -1)
		printf("%2d ", ptrNode->RightData);
}

// ��� ����
NODE *SplitNode(NODE *tmpNode, NODE *ptrNode)
{
	NODE *NewNode = (NODE *)malloc(sizeof(NODE));
	NewNode->RightData = -1;
	NewNode->Left = HeadNode;
	NewNode->Mid = HeadNode;
	NewNode->Right = HeadNode;

	if (tmpNode->LeftData < ptrNode->LeftData) {
		if (ptrNode->LeftData < tmpNode->RightData) {
			NewNode->LeftData = tmpNode->RightData;
			tmpNode->RightData = -1;
		}

		else {
			NewNode->LeftData = ptrNode->LeftData;
			ptrNode->LeftData = tmpNode->RightData;
			tmpNode->RightData = -1;
		}
	}

	else {
		NewNode->LeftData = tmpNode->RightData;
		tmpNode->RightData = ptrNode->LeftData;
		ptrNode->LeftData = tmpNode->LeftData;
		tmpNode->LeftData = tmpNode->RightData;
		tmpNode->RightData = -1;
	}

	ptrNode->Left = tmpNode;
	ptrNode->Mid = NewNode;

	return ptrNode;
}

int main(void)
{
	InitializeTree();

	//printf("��� 10, 20, 13, 5, 12 ���� \n");
	InsertNode(10);
	InsertNode(20);
	Level_Traverse(HeadNode->Left);
	printf("\n===========================\n");

	InsertNode(15);
	Level_Traverse(HeadNode->Left);
	printf("\n===========================\n");

	InsertNode(13);
	Level_Traverse(HeadNode->Left);
	printf("\n===========================\n");

	InsertNode(5);
	Level_Traverse(HeadNode->Left);
	printf("\n===========================\n");

	InsertNode(12);
	Level_Traverse(HeadNode->Left);
	printf("\n===========================\n");

	char ch;
	printf("\n�ƹ�Ű�� ���缼��~");
	ch = cin.get();

	return 0;
}

