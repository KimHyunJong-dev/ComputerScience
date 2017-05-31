// ArrayStack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


// 데이터를 가지는 Node 구조체 선언
typedef struct node 
{
	int  Data;
}Node;


// 스택 구조체
typedef struct arrayStack 
{
	int Capacity; // 배열로 구현하기 때문에 전체 용량을 제한함
	int Top;	  // 가장 최근에 들어온 데이터의 인덱스를 가지는 Top
	Node* Nodes;  // 데이터
}ArrayStack;


void CreateStack(ArrayStack** Stack, int Capacity); // stack을 만드는 함수
void DestroyStack(ArrayStack* Stack);			    // stack의 메모리를 해제하는 함수

void Push(ArrayStack* Stack, int Data);	            // stack의 Push 연산 수행
int Pop(ArrayStack* Stack);				            // stack의 Pop 연산 수행
int Top(ArrayStack* Stack);				            // stack의 최상위 데이터를 얻는 함수

int GetSize(ArrayStack* Stack);					    // stack의 현재 데이터 개수를 얻는 함수
int IsEmpty(ArrayStack* Stack);					    // stack이 비어있는 여부를 검사하는함수										
int IsFull(ArrayStack* Stack);                      // 스택이 가득 차 있는지 체크하는 함수


void CreateStack(ArrayStack** Stack, int Capacity) 
{
	// ArrayStack 구조체 타입의 stack의 메모리를 할당
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	// stack의 맴버인 Nodes는 Node* 형 변수이므로 마찬가지로 Capacity만큼 메모리 할당
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->Capacity = Capacity; // stack의 용량 저장
	(*Stack)->Top = 0;		       // 초기생성시 top을 0으로 초기화 한다.
}

// stack의 메모리를 해제하는 함수
void DestroyStack(ArrayStack* Stack) 
{	
	// Capacity에 따라 동적할당 된 Nodes의 메모리를 먼저 해제
	free(Stack->Nodes); 

	// Stack을 해제한다.
	free(Stack);		
}


// stack의 Push 연산 수행
// 스텍이 가득 차 있는 경우 에러메시지 처리
void Push(ArrayStack* Stack, int Data) 
{
	// Top은 삽입될 데이터의 인덱스를 가리키므로 (초기값 = 0)
	int Position = Stack->Top;	

	if (!(IsFull(Stack))) 
	{
		// Nodes[Stack->Top].Data 에 데이터 삽입
		Stack->Nodes[Position].Data = Data;
		
		// 데이터 저장이 끝나면 Top을 +1 증가 시킨다.
		printf("Data : %d is pushed  ||  ", Data);
		(Stack->Top)++;
	}
	else {
		printf("**** Error - Stack Is Full !! ****\n");
		return;
	}

}

// stack의 Pop 연산 수행
// 스택이 비어있는 경우 에러메시지 처리
int Pop(ArrayStack* Stack) 
{
	// Top은 삽입될 데이터의 인덱스를 가리키므로 -1 해줘야 
	// 현재 Top인 데이터의 인덱스를 얻을수 있다.
	int Position;
	
	// ex) Nodes[0]에 데이터가 저장되어있으면 
	// 현재의 Top은 1, 따라서 Nodes[0]의 데이터를 Pop시키기 위해선
	// Nodes[Top-1]의 데이터를 찾으면 됨

	if (!(IsEmpty(Stack))) 
	{
		Position = --(Stack->Top);
		printf("Data : %d is popped  ", Stack->Nodes[Position].Data);
		return Stack->Nodes[Position].Data;
	}
	else {
		printf("**** Error - Stack Is Empty ****\n");
		return 0;
	}
}


// stack의 최상위 데이터를 얻는 함수
// 스택이 비어있는 경우 에러메시지 처리
int Top(ArrayStack* Stack) 
{
	// Stack->Top의 값은 -1 되어 새로운 최상위 데이터값의 인덱스를 가리킬수 있게 한다.
	int Position = Stack->Top - 1;

	if (!IsEmpty(Stack))
		return Stack->Nodes[Position].Data;
	else {
		printf("**** Error - Stack Is Empty ****\n");
		return 0;
	}
}

// stack의 현재 데이터 개수를 얻는 함수
int GetSize(ArrayStack* Stack) 
{
	// 데이터의 개수는 Top의 값과 같다.
	return Stack->Top; 
}

// stack이 비어있는 여부를 검사하는함수.
int IsEmpty(ArrayStack* Stack) 
{
	// Stack->Top이 0이라면 1, 아니면 0을 리턴
	return ((Stack->Top) == 0);
	
}

// 스택이 가득 차 있는지 체크하는 함수
int IsFull(ArrayStack* Stack) 
{
	// Top이 Capacity와 같으면 데이터가 가득 차 있다.
	return (Stack->Top) == (Stack->Capacity);	
}




int main()
{
	int i = 0;
	ArrayStack* Stack = NULL;

	// Capacity가 10인 Stack 생성
	CreateStack(&Stack, 10); 
	
	// Push 연산 10회 수행
	for (i = 0; i<10; i++) {
		Push(Stack, i);
		printf("Current Top : %d\n", Stack->Top);
	}

	// 용량이 초과됐을때의 예외 처리 확인
	Push(Stack, i); 

	// Pop 연산 10회 수행
	for (i = 0; i<10; i++) {
		Pop(Stack);
		printf("Current Top : %d\n", Stack->Top);
	}

	Pop(Stack); // 비어있는 Stack에 Pop연산을 수행했을시 예외처리 확인

	DestroyStack(Stack);

	char ch;
	printf("아무키나 누루세요\n");
	ch = cin.get();

    return 0;
}

