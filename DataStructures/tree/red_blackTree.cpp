// red_blackTree.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


typedef enum { RED, BLACK } NodeColor;
typedef struct RBTNode
{
	int Data;
	NodeColor Color;
	RBTNode *parent;
	RBTNode *left;
	RBTNode *right;
}RBTNode;

RBTNode* RBTCreateNode(int data);
void RBTDestroyNode(RBTNode * node);
void RBTDestroyTree(RBTNode * node);

RBTNode * RBTSearchNode(RBTNode* tree, int target);
RBTNode * RBTSearchMinNode(RBTNode* tree);
void RBTInsertNode(RBTNode** tree, RBTNode* newNode);

void RBTInsertNodeHelper(RBTNode** tree, RBTNode* newnode);
void RBTRebuildAfterInsertNode(RBTNode** tree, RBTNode* x);

void RBTRotateRight(RBTNode ** root, RBTNode* parent);
void RBTRotateLeft(RBTNode ** root, RBTNode* parent);
RBTNode* RBTRemoveNode(RBTNode **root, int data);
void RBTRebuildAfterRemove(RBTNode** root, RBTNode* successor);
void RBTPrintTree(RBTNode* node, int depth, int black_count);

RBTNode* Nil;
RBTNode* RBTCreateNode(int data)
{
	RBTNode *NewNode = (RBTNode*)malloc(sizeof(RBTNode));
	NewNode->parent = NULL;
	NewNode->left = NULL;
	NewNode->right = NULL;	
	NewNode->Color = BLACK;
	NewNode->Data = data;

	return NewNode;
}

void RBTDestroyNode(RBTNode * node)
{
	free(node);
}

void RBTDestroyTree(RBTNode * tree)
{
	if (tree->right != Nil)
		RBTDestroyTree(tree->right);

	if(tree->left != Nil)
		RBTDestroyTree(tree->left);

	tree->left = Nil;
	tree->right = Nil;

	RBTDestroyNode(tree);
}


RBTNode * RBTSearchNode(RBTNode* tree, int target)
{
	if (tree == Nil)
		return NULL;

	if (tree->Data > target)
		return RBTSearchNode(tree->left, target);
	else if (tree->Data < target)
		return RBTSearchNode(tree->right, target);
	else
		return tree;
}

RBTNode * RBTSearchMinNode(RBTNode* tree)
{
	if (tree == Nil)
		return Nil;

	if (tree->left == Nil)
		return tree;
	else
		return RBTSearchMinNode(tree->left);
}

void RBTInsertNode(RBTNode** tree, RBTNode* newnode)
{
	RBTInsertNodeHelper(tree, newnode);

	newnode->Color = RED;
	newnode->left = Nil;
	newnode->right = Nil;

	RBTRebuildAfterInsertNode(tree, newnode);
}


void RBTInsertNodeHelper(RBTNode** tree, RBTNode* newnode)
{
	if ((*tree) == NULL)
		(*tree) = newnode;

	if ((*tree)->Data < newnode->Data)
	{
		if ((*tree)->right == Nil)
		{
			(*tree)->right = newnode;
			newnode->parent = (*tree);
		}
		else
			RBTInsertNodeHelper(&(*tree)->right, newnode);
	}
	else if ( (*tree)->Data > newnode->Data)
	{
		if ((*tree)->left == Nil)
		{
			(*tree)->left = newnode;
			newnode->parent = (*tree);
		}
		else
			RBTInsertNodeHelper(&(*tree)->left, newnode);
	}
}


void RBTRotateRight(RBTNode ** root,RBTNode* parent)
{
	RBTNode * LeftChild = parent->left;

	parent->left = LeftChild->right;

	if (LeftChild->right != Nil)
		LeftChild->right->parent = parent;

	LeftChild->parent = parent->parent;

	if (parent->parent == NULL)
	{
		(*root) = LeftChild;
	}
	else
	{
		if (parent == parent->parent->left)
		{
			parent->parent->left = LeftChild;
		}
		else
		{
			parent->parent->right = LeftChild;
		}
	}

	LeftChild->right = parent;
	parent->parent = LeftChild;

}

void RBTRotateLeft(RBTNode ** root, RBTNode* parent)
{
	RBTNode * RightChild = parent->right;

	parent->right = RightChild->left;

	if (RightChild->left != Nil)
		RightChild->left->parent = parent;

	RightChild->parent = parent->parent;

	if (parent->parent == NULL)
	{
		(*root) = RightChild;
	}
	else
	{
		if (parent == parent->parent->left)
			parent->parent->left = RightChild;
		else
			parent->parent->right = RightChild;
	}

	RightChild->left = parent;
	parent->parent = RightChild;	
}


void RBTRebuildAfterInsertNode(RBTNode** root, RBTNode* x)
{
	while ( x != (*root) && x->parent->Color == RED)
	{
		if (x->parent == x->parent->parent->left)
		{
			RBTNode * uncle = x->parent->parent->right;
			if (uncle->Color == RED)
			{
				x->parent->Color         = BLACK;
				uncle->Color             = BLACK;
				x->parent->parent->Color = RED;

				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->right)
				{
					x = x->parent;
					RBTRotateLeft(root, x);
				}
				
				x->parent->Color = BLACK;
				x->parent->parent->Color = RED;

				RBTRotateRight(root, x->parent->parent);
			}
		}
		else
		{
			RBTNode * uncle = x->parent->parent->left;

			if (uncle->Color == RED)
			{
				x->parent->Color         = BLACK;
				uncle->Color             = BLACK;
				x->parent->parent->Color = RED;

				x = x->parent->parent;
			}
			else
			{
				if (x == x->parent->left)
				{
					x = x->parent;
					RBTRotateRight(root, x);
				}

				x->parent->Color = BLACK;
				x->parent->parent->Color = RED;
				RBTRotateLeft(root, x->parent->parent);
			}
		
		}

	}

	(*root)->Color = BLACK;
}


RBTNode* RBTRemoveNode(RBTNode **root, int data)
{
	RBTNode * removed	= NULL;
	RBTNode * successor = NULL;
	RBTNode * target = RBTSearchNode((*root), data);

	if (target == NULL)
	{
		return NULL;
	}

	if (target->left == Nil || target->right == Nil)
	{
		removed = target;
	}
	else
	{
		removed = RBTSearchMinNode(target->right);
		target->Data = removed->Data;
	}


	if (removed->left != Nil)
		successor = removed->right;
	else
		successor = removed->right;


	successor->parent = removed->parent;
	if (removed->parent == NULL)
	{
		(*root) = successor;
	}
	else
	{
		if (removed == removed->parent->left)
			removed->parent->left = successor;
		else
			removed->parent->right = successor;
	}

	if (removed->Color == BLACK)
		RBTRebuildAfterRemove(root, successor);

	return removed;
}



void RBTRebuildAfterRemove(RBTNode** root, RBTNode* successor)
{
	RBTNode * sibling = NULL;
	while (successor->parent != NULL && successor->Color == BLACK)
	{

		if (successor == successor->parent->left)
		{
			sibling = successor->parent->right;
			if (sibling->Color == RED)
			{
				sibling->Color = BLACK;
				successor->parent->Color = RED;
				RBTRotateLeft(root, successor->parent);
			}
			else 
			{
				if (sibling->left->Color == BLACK && sibling->right->Color == BLACK)
				{
					sibling->Color = RED;
					successor = successor->parent;
				}
				else 
				{
					if (sibling->left->Color == RED)
					{
						sibling->left->Color = BLACK;
						sibling->Color       = RED;

						RBTRotateRight(root, sibling);
						sibling = successor->parent->right;
					}

					sibling->Color = successor->parent->Color;
					successor->parent->Color = BLACK;
					sibling->right->Color    = BLACK;
					RBTRotateLeft(root, successor->parent);
					successor = (*root);
				}
			}
		}
		else
		{
			sibling = successor->parent->left;
			if (sibling->Color == RED)
			{
				sibling->Color = BLACK;
				successor->parent->Color = RED;
				RBTRotateRight(root, successor->parent);
			}
			else
			{
				if (sibling->right->Color == BLACK && sibling->left->Color == BLACK)
				{
					sibling->Color = RED;
					successor = successor->parent;
				}
				else
				{
					if (sibling->right->Color == RED)
					{
						sibling->right->Color = BLACK;
						sibling->Color = RED;

						RBTRotateLeft(root, sibling);
						sibling = successor->parent->left;
					}

					sibling->Color = successor->parent->Color;
					successor->parent->Color = BLACK;
					sibling->left->Color     = BLACK;

					RBTRotateRight(root, successor->parent);
					successor = (*root);
				}
			}
		}
	}

	successor->Color = BLACK;
}


void RBTPrintTree(RBTNode* node, int depth, int black_count)
{
	int i  = 0;
	char c = 'X';
	int v  = -1;

	char cnt[100];

	if (node == NULL || node == Nil)
	{
		return;
	}

	if (node->Color == BLACK)
	{
		black_count++;
	}

	if (node->parent != NULL)
	{
		v = node->parent->Data;

		if (node->parent->left == node)
			c = 'L';
		else
			c = 'R';
	}

	if (node->left == Nil && node->right == Nil)
		sprintf(cnt, "---------------------------%d", black_count);
	else
		sprintf(cnt, "");


	for (i = 0; i < depth; i++)
	{
		printf("     ");

	}

	printf("%d %s [%c, %d] %s \n",node->Data, (node->Color == RED) ? "RED":"BLACK",c,v,cnt);

	RBTPrintTree(node->left,depth +1,black_count);
	RBTPrintTree(node->right, depth + 1, black_count);
}


int main()
{
	RBTNode* tree = NULL;
	RBTNode* node = NULL;

	Nil = RBTCreateNode(0);
	Nil->Color = BLACK;

	while (true)
	{
		int cmd = 0;
		int param = 0;
		char buffer[10];

		printf("Enter command number:\n");
		printf("(1)Create node, (2)Remove Node,(3)Search Node\n");
		printf("(4)Display Tree,(5)quit/n");
		printf("\ncommand number:");

		fgets(buffer, sizeof(buffer) - 1, stdin);
		sscanf(buffer, "%d", &cmd);

		if (cmd < 1 || cmd >5)
		{
			printf("Invaild command number %d", cmd);
			continue;
		}
		else if (cmd == 4)
		{
			RBTPrintTree(tree, 0, 0);
			printf("\n");
			continue;
		}
		else if (cmd == 5)
		{
			break;
		}

		printf("Enter parameter(1~~200):\n");

		fgets(buffer, sizeof(buffer) - 1, stdin);
		sscanf(buffer, "%d", &param);

		if (param < 1 || param >200)
		{
			printf("Invaild paramter.%d\n", param);
			continue;
		}

		switch(cmd)
		{
		case 1:
			RBTInsertNode(&tree, RBTCreateNode(param));
			break;
		case 2:
			node = RBTRemoveNode(&tree, param);

			if (node == NULL)
				printf("Not Found node to delete:%d\n", param);
			else
				RBTDestroyNode(node);
			break;

		case 3:
			node = RBTSearchNode(tree, param);
			if (node == NULL)
				printf("Not Found node to delete:%d\n", param);
			else				
				printf("Found node: %d(Cloor:%s)\n",node->Data, (node->Color == RED)?"RED":"BLACK");
			break;
		}		
		printf("\n");
	}

	RBTDestroyTree(tree);

	char ch;
	printf("\n아무키나 누루세요~");
	ch = cin.get();
    return 0;
}

