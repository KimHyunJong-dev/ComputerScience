// CircularQueue.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// ������ ����ü
typedef struct Node {
	int Data;
}Node;


typedef struct CircularQueue {
	int Capacity; // �뷮 (�����뷮�� Capacity+1)
	int Front;    // Front index
	int Rear;     // Rear index
	Node* Nodes;  // ������ ����ü �迭
} CircularQueue;



void CreateQueue(CircularQueue** Queue, int Capacity); // Queue ���� �Լ�
void DestroyQueue(CircularQueue* Queue);			   // �����Ҵ�� Nodes�� �޸� �����Լ�
void Enqueue(CircularQueue* Queue, int Data);	       // ���� �Լ� - Rear�� ������ ����
int Dequeue(CircularQueue* Queue);				       // ����(?) �Լ� - Front�� ������ ��ȯ
int GetSize(CircularQueue* Queue);					   // Queque �� �����ϴ� Data ���� ��ȯ
int IsEmpty(CircularQueue* Queue);					   // Queque�� ����ִ��� ���� �Ǵ�
int IsFull(CircularQueue* Queue);					   // Queque�� ���� �� �ִ��� ���� �Ǵ�
void PrintQueueData(CircularQueue* Queue);             // Queue�� ��� �����͸� ����ϴ� �Լ� - ��ü����


void CreateQueue(CircularQueue** Queue, int Capacity) 
{
	*Queue = (CircularQueue*)malloc(sizeof(CircularQueue));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	// ��ȯ ť�� ������ ���� Rear�� �ϳ��� �� ������ �׻� ����Ű�� �Ѵ�.
	// ���� �뷮���� +1 ��ŭ ũ�� �����Ҵ��Ͽ� Rear�� ����ų ������ �����.
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
	(*Queue)->Capacity = Capacity;

}

void DestroyQueue(CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}

// Queue�� Enqueue ����
void Enqueue(CircularQueue* Queue, int Data) 
{
	int Position = 0; // Enqueue �� ������ Nodes�迭�� index

    // ť�� ������ �ִ� ��찡 �ƴ϶��
	if (!IsFull(Queue)) {
		// Rear�� �迭�� ������ ��Ҹ� ����Ű�� ��� 
		// capacity = 5 
		// ex)           Front            Rear
		//    index :  0   1   2   3   4   5
		//    data  :  X   1   2   3   4   X
		// -> Enqueue ������ 
		//           Rear Front            
		//    index :  0   1   2   3   4   5
		//    data  :  X   1   2   3   4   5
		if (Queue->Rear == (Queue->Capacity)) {
			Position = Queue->Rear;
			Queue->Rear = 0;
		}
		else {
			Position = (Queue->Rear)++;
		}

	}
	// ���� ���ִٸ�
	else {
		printf("Error - Current Queue State : Full !!!\n");
		return;
	}

	// ������ ����
	printf("- Enqueue : %d \n", Data);
	Queue->Nodes[Position].Data = Data;

}

// Queue�� Dequeue ����
int Dequeue(CircularQueue* Queue) 
{
	int Position = Queue->Front;
	int temp;
	// Front�� �迭�� ������ ��Ҹ� ����Ű�� ��� 
	// capacity = 5 
	// ex)                   Rear    Front
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   5
	// -> Dequeue ������ 
	//            Front       Rear            
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   X
	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		(Queue->Front)++;

	temp = Queue->Nodes[Position].Data;
	Queue->Nodes[Position].Data = -1;  // Dequeue�� �����ʹ� -1�� ��������..
	printf("- Dequeue : %d \n", temp);
	return temp;
}

// queue�� �����ϴ� �������� ������ ��ȯ
int GetSize(CircularQueue* Queue) 
{
	if (Queue->Front <= Queue->Rear) // �Ĵ��� ���� �ڿ� ������
		return (Queue->Rear - Queue->Front);	
	//ex)            Front       Rear            
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   X
	else							// �Ĵ��� ���� �տ� ������
									// �� ������ ���� �������� �����ؾߵǳ�..�ƹ�ư �̷��� �ϸ� �ȴ�. �ܿ���.
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
	// ex)                   Rear    Front
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   5
}

int IsEmpty(CircularQueue* Queue) 
{
	// ť�� ����ִ� ��� - Front == Rear
	return (Queue->Front == Queue->Rear);
}

// Queue�� Nodes �迭�� ���� ���ִ��� ���θ� �Ǵ�

int IsFull(CircularQueue* Queue) 
{
	// ť�� ������ �ִ� ��� 
	// * Front<Rear �� ��� - Rear-Front == Capacity
	// * Front>Rear �� ��� - Rear+1 == Front
	if ((Queue->Front) > (Queue->Rear)) // Front > Rear�� ���
		return (Queue->Rear + 1) == (Queue->Front);
	else // Rear > Front
		return (Queue->Rear) - (Queue->Front) == (Queue->Capacity);
}

// Queue�� ��� �����͸� ����ϴ� �Լ� - ��ü����
void PrintQueueData(CircularQueue* Queue) 
{

	int i;
	if (Queue->Front <= Queue->Rear) // �Ĵ��� ���� �ڿ� ������
	{
		if (Queue->Front == Queue->Rear) {
			printf("Error  - Current Queue State : Empty !!! \n");
			return;
		}
		for (i = Queue->Front; i < Queue->Rear; i++)
			printf("Queue->Nodes[%d].Data : %d\n", i, Queue->Nodes[i].Data);
	}
	else // �Ĵ��� ���� �տ� ������
	{
		for (i = Queue->Front; i <= Queue->Capacity; i++)
			printf("Queue->Nodes[%d].Data : %d\n", i, Queue->Nodes[i].Data);
		for (i = 0; i<Queue->Rear; i++)
			printf("Queue->Nodes[%d].Data : %d\n", i, Queue->Nodes[i].Data);
	}
}



int main() {
	CircularQueue *Queue;
	int i;

	CreateQueue(&Queue, 10);
	for (i = 0; i < 10; i++)
	{
		Enqueue(Queue, i); // Enqueue Ȯ��
	}

	Enqueue(Queue, i); // ����ó�� Ȯ��
	
	for (i = 0; i < 5; i++)
	{
		Dequeue(Queue); // Dequeue Ȯ��	
	}
	
	printf("Queue Data Size : %d\n", GetSize(Queue));
	for (i = 10; i < 15; i++)
	{
		Enqueue(Queue, i);
	}

	printf("- Current Queue - \n");
	PrintQueueData(Queue);
	
	printf("Queue Data Size : %d\n", GetSize(Queue));

	for (i = 0; i < 10; i++)
	{
		Dequeue(Queue);
	}
		
	printf("Queue Data Size : %d\n", GetSize(Queue));
	PrintQueueData(Queue);

	char ch;
	printf("\n�ƹ�Ű�� ���缼��~");
	ch = cin.get();
	return 0;
}

