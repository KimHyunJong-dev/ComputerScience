// ArrayStack.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


// �����͸� ������ Node ����ü ����
typedef struct node 
{
	int  Data;
}Node;


// ���� ����ü
typedef struct arrayStack 
{
	int Capacity; // �迭�� �����ϱ� ������ ��ü �뷮�� ������
	int Top;	  // ���� �ֱٿ� ���� �������� �ε����� ������ Top
	Node* Nodes;  // ������
}ArrayStack;


void CreateStack(ArrayStack** Stack, int Capacity); // stack�� ����� �Լ�
void DestroyStack(ArrayStack* Stack);			    // stack�� �޸𸮸� �����ϴ� �Լ�

void Push(ArrayStack* Stack, int Data);	            // stack�� Push ���� ����
int Pop(ArrayStack* Stack);				            // stack�� Pop ���� ����
int Top(ArrayStack* Stack);				            // stack�� �ֻ��� �����͸� ��� �Լ�

int GetSize(ArrayStack* Stack);					    // stack�� ���� ������ ������ ��� �Լ�
int IsEmpty(ArrayStack* Stack);					    // stack�� ����ִ� ���θ� �˻��ϴ��Լ�										
int IsFull(ArrayStack* Stack);                      // ������ ���� �� �ִ��� üũ�ϴ� �Լ�


void CreateStack(ArrayStack** Stack, int Capacity) 
{
	// ArrayStack ����ü Ÿ���� stack�� �޸𸮸� �Ҵ�
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	// stack�� �ɹ��� Nodes�� Node* �� �����̹Ƿ� ���������� Capacity��ŭ �޸� �Ҵ�
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->Capacity = Capacity; // stack�� �뷮 ����
	(*Stack)->Top = 0;		       // �ʱ������ top�� 0���� �ʱ�ȭ �Ѵ�.
}

// stack�� �޸𸮸� �����ϴ� �Լ�
void DestroyStack(ArrayStack* Stack) 
{	
	// Capacity�� ���� �����Ҵ� �� Nodes�� �޸𸮸� ���� ����
	free(Stack->Nodes); 

	// Stack�� �����Ѵ�.
	free(Stack);		
}


// stack�� Push ���� ����
// ������ ���� �� �ִ� ��� �����޽��� ó��
void Push(ArrayStack* Stack, int Data) 
{
	// Top�� ���Ե� �������� �ε����� ����Ű�Ƿ� (�ʱⰪ = 0)
	int Position = Stack->Top;	

	if (!(IsFull(Stack))) 
	{
		// Nodes[Stack->Top].Data �� ������ ����
		Stack->Nodes[Position].Data = Data;
		
		// ������ ������ ������ Top�� +1 ���� ��Ų��.
		printf("Data : %d is pushed  ||  ", Data);
		(Stack->Top)++;
	}
	else {
		printf("**** Error - Stack Is Full !! ****\n");
		return;
	}

}

// stack�� Pop ���� ����
// ������ ����ִ� ��� �����޽��� ó��
int Pop(ArrayStack* Stack) 
{
	// Top�� ���Ե� �������� �ε����� ����Ű�Ƿ� -1 ����� 
	// ���� Top�� �������� �ε����� ������ �ִ�.
	int Position;
	
	// ex) Nodes[0]�� �����Ͱ� ����Ǿ������� 
	// ������ Top�� 1, ���� Nodes[0]�� �����͸� Pop��Ű�� ���ؼ�
	// Nodes[Top-1]�� �����͸� ã���� ��

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


// stack�� �ֻ��� �����͸� ��� �Լ�
// ������ ����ִ� ��� �����޽��� ó��
int Top(ArrayStack* Stack) 
{
	// Stack->Top�� ���� -1 �Ǿ� ���ο� �ֻ��� �����Ͱ��� �ε����� ����ų�� �ְ� �Ѵ�.
	int Position = Stack->Top - 1;

	if (!IsEmpty(Stack))
		return Stack->Nodes[Position].Data;
	else {
		printf("**** Error - Stack Is Empty ****\n");
		return 0;
	}
}

// stack�� ���� ������ ������ ��� �Լ�
int GetSize(ArrayStack* Stack) 
{
	// �������� ������ Top�� ���� ����.
	return Stack->Top; 
}

// stack�� ����ִ� ���θ� �˻��ϴ��Լ�.
int IsEmpty(ArrayStack* Stack) 
{
	// Stack->Top�� 0�̶�� 1, �ƴϸ� 0�� ����
	return ((Stack->Top) == 0);
	
}

// ������ ���� �� �ִ��� üũ�ϴ� �Լ�
int IsFull(ArrayStack* Stack) 
{
	// Top�� Capacity�� ������ �����Ͱ� ���� �� �ִ�.
	return (Stack->Top) == (Stack->Capacity);	
}




int main()
{
	int i = 0;
	ArrayStack* Stack = NULL;

	// Capacity�� 10�� Stack ����
	CreateStack(&Stack, 10); 
	
	// Push ���� 10ȸ ����
	for (i = 0; i<10; i++) {
		Push(Stack, i);
		printf("Current Top : %d\n", Stack->Top);
	}

	// �뷮�� �ʰ��������� ���� ó�� Ȯ��
	Push(Stack, i); 

	// Pop ���� 10ȸ ����
	for (i = 0; i<10; i++) {
		Pop(Stack);
		printf("Current Top : %d\n", Stack->Top);
	}

	Pop(Stack); // ����ִ� Stack�� Pop������ ���������� ����ó�� Ȯ��

	DestroyStack(Stack);

	char ch;
	printf("�ƹ�Ű�� ���缼��\n");
	ch = cin.get();

    return 0;
}

