// CircularQueue.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 데이터 구조체
typedef struct Node {
	int Data;
}Node;


typedef struct CircularQueue {
	int Capacity; // 용량 (실제용량은 Capacity+1)
	int Front;    // Front index
	int Rear;     // Rear index
	Node* Nodes;  // 데이터 구조체 배열
} CircularQueue;



void CreateQueue(CircularQueue** Queue, int Capacity); // Queue 생성 함수
void DestroyQueue(CircularQueue* Queue);			   // 동적할당된 Nodes의 메모리 해제함수
void Enqueue(CircularQueue* Queue, int Data);	       // 삽입 함수 - Rear에 데이터 삽입
int Dequeue(CircularQueue* Queue);				       // 삭제(?) 함수 - Front의 데이터 반환
int GetSize(CircularQueue* Queue);					   // Queque 에 존재하는 Data 갯수 반환
int IsEmpty(CircularQueue* Queue);					   // Queque가 비어있는지 여부 판단
int IsFull(CircularQueue* Queue);					   // Queque가 가득 차 있는지 여부 판단
void PrintQueueData(CircularQueue* Queue);             // Queue의 모든 데이터를 출력하는 함수 - 자체제작


void CreateQueue(CircularQueue** Queue, int Capacity) 
{
	*Queue = (CircularQueue*)malloc(sizeof(CircularQueue));
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity + 1));
	// 순환 큐의 구현을 위해 Rear는 하나의 빈 공간을 항상 가리키게 한다.
	// 실제 용량보다 +1 만큼 크게 동적할당하여 Rear가 가리킬 공간을 만든다.
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
	(*Queue)->Capacity = Capacity;

}

void DestroyQueue(CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}

// Queue의 Enqueue 구현
void Enqueue(CircularQueue* Queue, int Data) 
{
	int Position = 0; // Enqueue 를 수행할 Nodes배열의 index

    // 큐가 가득차 있는 경우가 아니라면
	if (!IsFull(Queue)) {
		// Rear가 배열의 마지막 요소를 가리키는 경우 
		// capacity = 5 
		// ex)           Front            Rear
		//    index :  0   1   2   3   4   5
		//    data  :  X   1   2   3   4   X
		// -> Enqueue 수행후 
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
	// 가득 차있다면
	else {
		printf("Error - Current Queue State : Full !!!\n");
		return;
	}

	// 데이터 삽입
	printf("- Enqueue : %d \n", Data);
	Queue->Nodes[Position].Data = Data;

}

// Queue의 Dequeue 구현
int Dequeue(CircularQueue* Queue) 
{
	int Position = Queue->Front;
	int temp;
	// Front가 배열의 마지막 요소를 가리키는 경우 
	// capacity = 5 
	// ex)                   Rear    Front
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   5
	// -> Dequeue 수행후 
	//            Front       Rear            
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   X
	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		(Queue->Front)++;

	temp = Queue->Nodes[Position].Data;
	Queue->Nodes[Position].Data = -1;  // Dequeue된 데이터는 -1로 만들어버림..
	printf("- Dequeue : %d \n", temp);
	return temp;
}

// queue에 존재하는 데이터의 개수를 반환
int GetSize(CircularQueue* Queue) 
{
	if (Queue->Front <= Queue->Rear) // 후단이 전단 뒤에 있을때
		return (Queue->Rear - Queue->Front);	
	//ex)            Front       Rear            
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   X
	else							// 후단이 전단 앞에 있을때
									// 이 수식을 어케 논리적으로 설명해야되나..아무튼 이렇게 하면 된다. 외우자.
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
	// ex)                   Rear    Front
	//    index :  0   1   2   3   4   5
	//    data  :  0   1   2   X   X   5
}

int IsEmpty(CircularQueue* Queue) 
{
	// 큐가 비어있는 경우 - Front == Rear
	return (Queue->Front == Queue->Rear);
}

// Queue의 Nodes 배열이 가득 차있는지 여부를 판단

int IsFull(CircularQueue* Queue) 
{
	// 큐가 가득차 있는 경우 
	// * Front<Rear 일 경우 - Rear-Front == Capacity
	// * Front>Rear 일 경우 - Rear+1 == Front
	if ((Queue->Front) > (Queue->Rear)) // Front > Rear인 경우
		return (Queue->Rear + 1) == (Queue->Front);
	else // Rear > Front
		return (Queue->Rear) - (Queue->Front) == (Queue->Capacity);
}

// Queue의 모든 데이터를 출력하는 함수 - 자체제작
void PrintQueueData(CircularQueue* Queue) 
{

	int i;
	if (Queue->Front <= Queue->Rear) // 후단이 전단 뒤에 있을때
	{
		if (Queue->Front == Queue->Rear) {
			printf("Error  - Current Queue State : Empty !!! \n");
			return;
		}
		for (i = Queue->Front; i < Queue->Rear; i++)
			printf("Queue->Nodes[%d].Data : %d\n", i, Queue->Nodes[i].Data);
	}
	else // 후단이 전단 앞에 있을때
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
		Enqueue(Queue, i); // Enqueue 확인
	}

	Enqueue(Queue, i); // 예외처리 확인
	
	for (i = 0; i < 5; i++)
	{
		Dequeue(Queue); // Dequeue 확인	
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
	printf("\n아무키나 누루세요~");
	ch = cin.get();
	return 0;
}

