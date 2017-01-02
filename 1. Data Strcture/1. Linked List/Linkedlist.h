#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagnode
{
	int DATA;
	struct tagnode *NextNode;
}Node;

Node* SLL_CreateNode(int newdata);

Node *SLL_GetNodeAt(Node *Head, int Location);

void SLL_AppendNode(Node **Head, Node *NewNode);

void SLL_RemoveNode(Node **Head, Node *Remove);

void SLL_DestoryNode(Node *Node);

void SLL_InsertAfter(Node *Current, Node *NewNode);

void SLL_InsertNewHead(Node **Head, Node *NewHead);

int SLL_GetNodeCount(Node* Head);

#endif