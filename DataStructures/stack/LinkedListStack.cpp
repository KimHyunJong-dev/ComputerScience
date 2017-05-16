// LinkedListStack.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


// �����͸� ������ Node ����ü
typedef struct node
{
	// ArrayStack�� �ٸ��� �����͸� ���ڿ��� ����
	// Node ������ Node ����ü Ÿ���� �޸� �����Ӹ� �ƴ϶� ���ڿ��� �޸𸮵� ���� �� ���� ����� �Ѵ�.
	char* Data; 	
	
	// ���� ��带 ����Ű�� NextNode
	struct node* NextNode;
} Node;


typedef struct linked_list_stack
{
	Node* List; // ������ ��带 ����Ű�� List
	Node* Top;  // �ֻ��� ��带 ����Ű�� Top

} LinkedListStack;


void CreateStack(LinkedListStack** Stack);     // stack ����
void DestroyStackAll(LinkedListStack* Stack);  // ��� node���� pop���� ���� �� stack ���� 

Node* CreateNode(char* Data);  // node ����
void DestroyNode(Node* _Node); // node ����

void  Push(LinkedListStack* Stack, Node* NewNode); // stack�� push ���� ����
Node* Pop(LinkedListStack* Stack);				  // stack�� pop ���� ����
												
Node* Top(LinkedListStack* Stack);   // stack�� Top node�� ���ϴ� �Լ�
int GetSize(LinkedListStack* Stack); // stack�� node ������ ���ϴ� �Լ�
int IsEmpty(LinkedListStack* Stack); // stack�� ����ִ��� ���θ� ���ϴ��Լ�.


// stack ����
void CreateStack(LinkedListStack** Stack) 
{
	// Stack�� �޸� �Ҵ�
	printf("*** Stack is created ***\n");
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	
	// Top, List�� NULL�� �ʱ�ȭ
	(*Stack)->Top = (*Stack)->List = NULL;
	
}


// ��� node���� pop���� ���� �� stack ���� 
void DestroyStackAll(LinkedListStack* Stack)
{
	while (!IsEmpty(Stack)) 
	{ 
		// Stack�� Node�� Empty ���°� �ɶ����� loop�� ����
		Node* Popped = Pop(Stack);
		DestroyNode(Popped);
	}
	// ��� node�� pop ������ ��ģ �� stack�� �޸� ����
	printf("*** Stack is deleted ***\n");
	free(Stack);
}




// node ����, ������ ���ÿ� push������ �����Ϸ���
// Push(Stack, LLS_CreateNode("���ڿ�")) �̷������� ���� �ȴ�.
Node* CreateNode(char* Data) 
{
	// ���ο� ����� �޸� �Ҵ�
	Node* NewNode = (Node*)malloc(sizeof(Node)); 

	// ���ڿ��� ��� \0���� ���ߵǹǷ�...+1
	NewNode->Data = (char*)malloc(strlen(Data) + 1); 

	// ���ڿ� ī�� ����
	strcpy(NewNode->Data, Data); 

	// NextNode�� NULL�� �ʱ�ȭ
	NewNode->NextNode = NULL; 

	// ������ ����� �ּ� ��ȯ
	return NewNode; 
}

// node ����
void DestroyNode(Node* _Node) 
{
	printf("*** Node is deleted - Data : %s\n", _Node->Data);
	// ���ڿ����� �����ϰ�...
	free(_Node->Data); 

	// �״��� node ����.
	free(_Node);	   
}


// stack�� push ���� ����
void Push(LinkedListStack* Stack, Node* NewNode) 
{
	// ����ִ� stack�� �����
	if (IsEmpty(Stack)) 
	{
		Stack->List = NewNode;
	}
	else 
	{ 
		// ��������ʴ� stack�� ����� �ֻ��� ��带 ã�� NewNode�� ����
		Node* Current_Top = Stack->Top;
		Current_Top->NextNode = NewNode;
	}

	printf("  - Pushed Node's Data : %s\n", NewNode->Data);
	NewNode->NextNode = NULL;
	Stack->Top = NewNode;
}


// stack�� pop ���� ����
// ���� ���� �� NextNode �� Top �� ����Ű�� ��ũ ���� ��� ����.
// Pop�Ǵ� Node�� �ּҸ� �����ؾߵǴ� pop�Ǵ� node�� �޸� ������  
// DestroyNode(LLS_Pop(Stack)) ó�� ���
Node* Pop(LinkedListStack* Stack) 
{
	Node* TopNode = Stack->Top;

	// stack�� ������� ��� pop������ �����Ҷ� ����ó��
	if (IsEmpty(Stack)) {
		printf("* Error - Stack is empty !! *\n");
		return NULL;
	}	
	else if (Stack->List == Stack->Top) 
	{
		// node�� �Ѱ� �������� pop������ �����Ҷ�
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else 
	{ 
		// �׿��� ��� - ���ο� Top��� ����
		Node* CurrentTop = Stack->List;

		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) 
		{
			// ���ο� Top�� ���ϱ�
			CurrentTop = CurrentTop->NextNode;
		}
		
		// Loop�� ������ ������ Top �ٷ� �Ʒ��� �ִ� Node�� CurrentTop�� �ȴ�
		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL; // ��ũ ����		

	}
	printf("  - Poped Node's Data : %s\n", TopNode->Data);

	return TopNode;
}

// stack�� Top node�� ���ϴ� �Լ�
Node* Top(LinkedListStack* Stack) 
{
	printf("  - Top node's Data : %s \n", Stack->Top->Data);
	return Stack->Top;
}


// stack�� node ������ ���ϴ� �Լ�
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

// stack�� ����ִ��� ���θ� ���ϴ� �Լ�.
int IsEmpty(LinkedListStack* Stack) 
{	// List�� �׻� �������� Node�� ����Ű�Ƿ� List�� NULL�Ͻ� stack�� ����ִ� ���°� �ȴ�.
	return ((Stack->List) == NULL);
}


int main()
{
	LinkedListStack* Stack = NULL;
	int i, Count;

	// ������ ����
	CreateStack(&Stack);

	// ����� push����
	printf(" *** Push Function Check *** \n");
	Push(Stack, CreateNode("Kim"));
	Push(Stack, CreateNode("pegasus"));
	Push(Stack, CreateNode("HYUNJONG"));

	// �ֻ��� node
	printf(" *** Top Node Check *** \n");
	Top(Stack);

	printf(" *** The Number of Nodes = %d\n", Count = GetSize(Stack));

	// ����� pop ����
	printf(" *** Pop Function Check *** \n");

	for (i = 0; i<Count; i++)
		DestroyNode(Pop(Stack)); // Pop���� ������ �ٷ� Node����

	printf(" *** Exceptional Process Check ***\n");
	Pop(Stack); // ����ó�� Ȯ��

	printf(" *** The Number of Nodes = %d\n", Count = GetSize(Stack));

	// ����� push����
	printf(" *** Push Function Check *** \n");
	
	Push(Stack, CreateNode("��"));
	Push(Stack, CreateNode("��"));
	Push(Stack, CreateNode("��"));

	printf(" *** The Number of Nodes = %d\n", Count = GetSize(Stack));

	printf(" *** DestroyStack Function Check *** \n");

	DestroyStackAll(Stack);

	char ch;
	printf("�ƹ�Ű�� ���缼��\n");
	ch = cin.get();

    return 0;
}

