// LinkedListStack.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


// 데이터를 가지는 Node 구조체
typedef struct node
{
	// ArrayStack과 다르게 데이터를 문자열로 지정
	// Node 생성시 Node 구조체 타입의 메모리 생성뿐만 아니라 문자열의 메모리도 생성 및 삭제 해줘야 한다.
	char* Data; 	
	
	// 다음 노드를 가리키는 NextNode
	struct node* NextNode;
} Node;


typedef struct linked_list_stack
{
	Node* List; // 최하위 노드를 가리키는 List
	Node* Top;  // 최상위 노드를 가리키는 Top

} LinkedListStack;


void CreateStack(LinkedListStack** Stack);     // stack 생성
void DestroyStackAll(LinkedListStack* Stack);  // 모든 node들의 pop연산 수행 후 stack 해제 

Node* CreateNode(char* Data);  // node 생성
void DestroyNode(Node* _Node); // node 삭제

void  Push(LinkedListStack* Stack, Node* NewNode); // stack의 push 연산 수행
Node* Pop(LinkedListStack* Stack);				  // stack의 pop 연산 수행
												
Node* Top(LinkedListStack* Stack);   // stack의 Top node를 구하는 함수
int GetSize(LinkedListStack* Stack); // stack의 node 개수를 구하는 함수
int IsEmpty(LinkedListStack* Stack); // stack이 비어있는지 여부를 구하는함수.


// stack 생성
void CreateStack(LinkedListStack** Stack) 
{
	// Stack의 메모리 할당
	printf("*** Stack is created ***\n");
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	
	// Top, List를 NULL로 초기화
	(*Stack)->Top = (*Stack)->List = NULL;
	
}


// 모든 node들의 pop연산 수행 후 stack 해제 
void DestroyStackAll(LinkedListStack* Stack)
{
	while (!IsEmpty(Stack)) 
	{ 
		// Stack의 Node가 Empty 상태가 될때까지 loop문 수행
		Node* Popped = Pop(Stack);
		DestroyNode(Popped);
	}
	// 모든 node의 pop 연산을 마친 후 stack의 메모리 해제
	printf("*** Stack is deleted ***\n");
	free(Stack);
}




// node 생성, 생성과 동시에 push연산을 수행하려면
// Push(Stack, LLS_CreateNode("문자열")) 이런식으로 쓰면 된다.
Node* CreateNode(char* Data) 
{
	// 새로운 노드의 메모리 할당
	Node* NewNode = (Node*)malloc(sizeof(Node)); 

	// 문자열의 경우 \0까지 들어가야되므로...+1
	NewNode->Data = (char*)malloc(strlen(Data) + 1); 

	// 문자열 카피 수행
	strcpy(NewNode->Data, Data); 

	// NextNode는 NULL로 초기화
	NewNode->NextNode = NULL; 

	// 생성된 노드의 주소 반환
	return NewNode; 
}

// node 삭제
void DestroyNode(Node* _Node) 
{
	printf("*** Node is deleted - Data : %s\n", _Node->Data);
	// 문자열부터 해제하고...
	free(_Node->Data); 

	// 그다음 node 해제.
	free(_Node);	   
}


// stack의 push 연산 수행
void Push(LinkedListStack* Stack, Node* NewNode) 
{
	// 비어있는 stack의 경우라면
	if (IsEmpty(Stack)) 
	{
		Stack->List = NewNode;
	}
	else 
	{ 
		// 비어있지않는 stack의 경우라면 최상위 노드를 찾아 NewNode를 연결
		Node* Current_Top = Stack->Top;
		Current_Top->NextNode = NewNode;
	}

	printf("  - Pushed Node's Data : %s\n", NewNode->Data);
	NewNode->NextNode = NULL;
	Stack->Top = NewNode;
}


// stack의 pop 연산 수행
// 연산 수행 후 NextNode 와 Top 이 가리키는 링크 수정 기능 제공.
// Pop되는 Node의 주소를 리턴해야되니 pop되는 node의 메모리 해제는  
// DestroyNode(LLS_Pop(Stack)) 처럼 사용
Node* Pop(LinkedListStack* Stack) 
{
	Node* TopNode = Stack->Top;

	// stack이 비어있을 경우 pop연산을 수행할때 예외처리
	if (IsEmpty(Stack)) {
		printf("* Error - Stack is empty !! *\n");
		return NULL;
	}	
	else if (Stack->List == Stack->Top) 
	{
		// node가 한개 남았을시 pop연산을 수행할때
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else 
	{ 
		// 그외의 경우 - 새로운 Top노드 설정
		Node* CurrentTop = Stack->List;

		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) 
		{
			// 새로운 Top을 구하기
			CurrentTop = CurrentTop->NextNode;
		}
		
		// Loop문 수행후 원래의 Top 바로 아래에 있는 Node가 CurrentTop이 된다
		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL; // 링크 해제		

	}
	printf("  - Poped Node's Data : %s\n", TopNode->Data);

	return TopNode;
}

// stack의 Top node를 구하는 함수
Node* Top(LinkedListStack* Stack) 
{
	printf("  - Top node's Data : %s \n", Stack->Top->Data);
	return Stack->Top;
}


// stack의 node 개수를 구하는 함수
int GetSize(LinkedListStack* Stack) 
{
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL) 
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

// stack이 비어있는지 여부를 구하는 함수.
int IsEmpty(LinkedListStack* Stack) 
{	// List는 항상 최하위의 Node를 가리키므로 List가 NULL일시 stack이 비어있는 상태가 된다.
	return ((Stack->List) == NULL);
}


int main()
{
	LinkedListStack* Stack = NULL;
	int i, Count;

	// 스택의 생성
	CreateStack(&Stack);

	// 노드의 push연산
	printf(" *** Push Function Check *** \n");
	Push(Stack, CreateNode("Kim"));
	Push(Stack, CreateNode("pegasus"));
	Push(Stack, CreateNode("HYUNJONG"));

	// 최상위 node
	printf(" *** Top Node Check *** \n");
	Top(Stack);

	printf(" *** The Number of Nodes = %d\n", Count = GetSize(Stack));

	// 노드의 pop 연산
	printf(" *** Pop Function Check *** \n");

	for (i = 0; i<Count; i++)
		DestroyNode(Pop(Stack)); // Pop연산 수행후 바로 Node삭제

	printf(" *** Exceptional Process Check ***\n");
	Pop(Stack); // 예외처리 확인

	printf(" *** The Number of Nodes = %d\n", Count = GetSize(Stack));

	// 노드의 push연산
	printf(" *** Push Function Check *** \n");
	
	Push(Stack, CreateNode("김"));
	Push(Stack, CreateNode("현"));
	Push(Stack, CreateNode("종"));

	printf(" *** The Number of Nodes = %d\n", Count = GetSize(Stack));

	printf(" *** DestroyStack Function Check *** \n");

	DestroyStackAll(Stack);

	char ch;
	printf("아무키나 누루세요\n");
	ch = cin.get();

    return 0;
}

