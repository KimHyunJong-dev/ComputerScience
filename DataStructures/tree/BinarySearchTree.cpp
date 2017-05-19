// BinarySearchTree.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct BSTNode
{
	int Data;
	BSTNode *left;
	BSTNode *right;
}BSTNode;

BSTNode* CreateBSTNode(int data);
void DestoryBSTreeNode(BSTNode* tree);
void DestoryBSTNode(BSTNode* node);
BSTNode* SearchNode(BSTNode* tree, int target);
BSTNode *SearchMinNode(BSTNode * tree);
void InsertBSTNode(BSTNode *tree, BSTNode * child);
BSTNode* RemoveBSTNode(BSTNode* tree, BSTNode *parent, int target);

void PreorderPrintfTree(BSTNode * node);
void InorderPrinfTree(BSTNode * node);
void PostorderPrintfTree(BSTNode * node);

BSTNode* CreateBSTNode(int data)
{
	BSTNode *NewNode = (BSTNode*)malloc(sizeof(BSTNode));

	NewNode->left = NULL;
	NewNode->right = NULL;

	NewNode->Data = data;

	return NewNode;
}


void DestoryBSTNode(BSTNode* node)
{
	free(node);
}


void DestoryBSTreeNode(BSTNode* tree)
{
	if (tree->right != NULL)
	{
		DestoryBSTreeNode(tree->right);
	}

	if (tree->left != NULL)
	{
		DestoryBSTreeNode(tree->left);
	}

	tree->left = NULL;
	tree->right = NULL;

	DestoryBSTNode(tree);
}


BSTNode* SearchNode(BSTNode* tree, int target)
{
	if (tree == NULL)
	{
		return NULL;
	}

	if (tree->Data == target)
		return tree;
	else if (tree->Data > target)
		return SearchNode(tree->left, target);
	else
		return SearchNode(tree->right, target);
}



BSTNode *SearchMinNode(BSTNode * tree)
{
	if (tree == NULL)
		return NULL;

	if (tree->left == NULL)
		return tree;
	else
		return SearchMinNode(tree->left);
}


void InsertBSTNode(BSTNode *tree, BSTNode * child)
{
	if (tree->Data < child->Data)
	{
		if (tree->right == NULL)
			tree->right = child;
		else
			InsertBSTNode(tree->right, child);
	}

	else if(tree->Data > child->Data)
	{
		if (tree->left == NULL)
			tree->left = child;
		else
			InsertBSTNode(tree->left, child);
	}
}



BSTNode* RemoveBSTNode(BSTNode* tree, BSTNode *parent, int target)
{
	BSTNode * remove = NULL;

	if (tree == NULL)
		return NULL;

	if (tree->Data > target)
	{
		remove = RemoveBSTNode(tree->left, tree, target);
	}
	else if (tree->Data < target)
	{
		remove = RemoveBSTNode(tree->right, tree, target);
	}
	else // ���� �� ��带 ã�� ���
	{
		remove = tree;

		// ���� �ڽ��� ���� ��� ��, �ٳ���� ���
		if (tree->left == NULL && tree->right == NULL)
		{
			if (parent->left == tree)
			{
				parent->left = NULL;
			}
			else
				parent->right = NULL;
		}
		else 
		{
			// ���� �ڽ��� ��δ� �ִ� ���
			if (tree->left != NULL && tree->right != NULL)
			{
				// �ּ� ��� ���� ã�� ���� �� �ڿ� ���� ��忡 ��ġ ��Ų��.
				BSTNode *MinNode = SearchMinNode(tree->right);
				MinNode = RemoveBSTNode(tree, NULL, MinNode->Data);
				tree->Data = MinNode->Data;
			}
			// �ڽ��� �ϳ��� �ִ� ���
			else 
			{
				BSTNode * temp = NULL;
				if (tree->left != NULL)
					temp = tree->left;
				else
					temp = tree->right;


				if (parent->left == tree)
					parent->left = temp;
				else
					parent->right = temp;
			}

		}

	}
	
	return remove;
}





// ���� ��ȸ
void PreorderPrintfTree(BSTNode * node)
{
	if (node == NULL)
	{
		return;
	}

	printf("\n%d", node->Data);

	PreorderPrintfTree(node->left);

	PreorderPrintfTree(node->right);

}

// ���� ��ȸ 
void InorderPrinfTree(BSTNode * node)
{
	if (node == NULL)
		return;

	InorderPrinfTree(node->left);

	printf("\n%d", node->Data);

	InorderPrinfTree(node->right);
}



// ���� ��ȸ
void PostorderPrintfTree(BSTNode * node)
{
	if (node == NULL)
	{
		return;
	}

	PostorderPrintfTree(node->left);

	PostorderPrintfTree(node->right);

	printf("\n%d", node->Data);
}


int main()
{

	BSTNode* tree = CreateBSTNode(123);
	BSTNode* node = NULL;

	InsertBSTNode(tree, CreateBSTNode(22));
	InsertBSTNode(tree, CreateBSTNode(9918));
	InsertBSTNode(tree, CreateBSTNode(242));
	InsertBSTNode(tree, CreateBSTNode(424));
	InsertBSTNode(tree, CreateBSTNode(17));
	InsertBSTNode(tree, CreateBSTNode(3));
	InsertBSTNode(tree, CreateBSTNode(98));
	InsertBSTNode(tree, CreateBSTNode(34));
	InsertBSTNode(tree, CreateBSTNode(760));
	InsertBSTNode(tree, CreateBSTNode(317));
	InsertBSTNode(tree, CreateBSTNode(1));
	InsertBSTNode(tree, CreateBSTNode(45));
	InsertBSTNode(tree, CreateBSTNode(198));
	InsertBSTNode(tree, CreateBSTNode(636));
	InsertBSTNode(tree, CreateBSTNode(234));

	printf("\nInorder Tree Data");
	InorderPrinfTree(tree);
	printf("\n");

	printf("\nremove 9918");
	node = RemoveBSTNode(tree, NULL, 9918);
	DestoryBSTNode(node);
	InorderPrinfTree(tree);
	printf("\n");

	printf("\nremove 760");
	node = RemoveBSTNode(tree, NULL, 760);
	DestoryBSTNode(node);
	InorderPrinfTree(tree);
	printf("\n");


	printf("\nremove 198");
	node = RemoveBSTNode(tree, NULL, 198);
	DestoryBSTNode(node);
	InorderPrinfTree(tree);
	printf("\n");

	printf("\nInsert 111...\n");
	InsertBSTNode(tree, CreateBSTNode(111));
	InorderPrinfTree(tree);
	printf("\n");


	printf("\nInorder....\n");
	InorderPrinfTree(tree);
	printf("\n\n");

	printf("\nPreoder....\n");
	PreorderPrintfTree(tree);
	printf("\n\n");

	printf("\nPostoder....\n");
	PostorderPrintfTree(tree);
	printf("\n\n");

	printf("\nAll Tree Delete...\n");
	DestoryBSTreeNode(tree);

	char ch;
	printf("\n�ƹ�Ű�� ���缼��~");
	ch = cin.get();
    return 0;
}








