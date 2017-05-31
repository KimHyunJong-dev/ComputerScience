// BinaryTree.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct TreeNode
{
	char Data;
	TreeNode * left;
	TreeNode * right;
}TreeNode;


TreeNode * CreateTreeNode(char Data);
void DestoryTreeNode(TreeNode* node);
void DeleteTreeNode(TreeNode * node);
void PreorderPrintfTree(TreeNode * node);


TreeNode * CreateTreeNode(char Data)
{
	TreeNode * NewNode = (TreeNode*)malloc(sizeof(TreeNode));
	NewNode->Data = Data;

	NewNode->left  = NULL;
	NewNode->right = NULL;
	
	return NewNode;
}

void DestoryTreeNode(TreeNode* node)
{
	free(node);
}

//���� ��ȸ�� ������ ���� 
void DeleteTreeNode(TreeNode * node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		DeleteTreeNode(node->left);

		DeleteTreeNode(node->right);

		DestoryTreeNode(node);
	}
}

// ���� ��ȸ
void PreorderPrintfTree(TreeNode * node)
{
	if (node == NULL)
	{
		return;
	}

	printf(" %c", node->Data);
	
	PreorderPrintfTree(node->left);

	PreorderPrintfTree(node->right);

}

// ���� ��ȸ
void InorderPrintfTree(TreeNode * node)
{
	if (node == NULL)
	{
		return;
	}

	InorderPrintfTree(node->left);

	printf(" %c", node->Data);

	InorderPrintfTree(node->right);
}

// ���� ��ȸ
void PostorderPrintfTree(TreeNode * node)
{
	if (node == NULL)
	{
		return;
	}

	PostorderPrintfTree(node->left);

	PostorderPrintfTree(node->right);

	printf(" %c", node->Data);
}

int main()
{

	TreeNode * A = CreateTreeNode('A');
	TreeNode * B = CreateTreeNode('B');
	TreeNode * C = CreateTreeNode('C');
	TreeNode * D = CreateTreeNode('D');
	TreeNode * E = CreateTreeNode('E');
	TreeNode * F = CreateTreeNode('F');
	TreeNode * G = CreateTreeNode('G');

	A->left = B;
	B->left = C;
	C->right = D;

	A->right = E;
	E->left = F;
	E->right = G;

	printf("\nPreoder....\n");
	PreorderPrintfTree(A);
	printf("\n\n");

	printf("\nInoder....\n");
	InorderPrintfTree(A);
	printf("\n\n");

	printf("\nPostoder....\n");
	PostorderPrintfTree(A);
	printf("\n\n");

	DeleteTreeNode(A);

	char ch;
	printf("\n�ƹ�Ű�� ���缼��~");
	ch = cin.get();

    return 0;
}

