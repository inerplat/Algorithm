#include "Linkedlist.h"

// 연결리스트 정의

// 노드 생성 함수
Node* SLL_CreateNode(int newdata)
{
	Node *NewNode = (Node *)malloc(sizeof(Node));
	NewNode->DATA = newdata;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노트 탐색 함수
Node *SLL_GetNodeAt(Node *Head, int Location)
{
	Node *Current = Head;
	while (--Location >= 0 && Current != NULL) Current = Current->NextNode;
	return Current;
}

// 노드 추가 함수
void SLL_AppendNode(Node **Head, Node *NewNode)
{
	if (*Head == NULL)
		*Head = NewNode;
	else
	{
		Node *Tail = (*Head);
		while (Tail->NextNode != NULL) Tail = Tail->NextNode;
		Tail->NextNode = NewNode;
	}
}


void SLL_RemoveNode(Node **Head, Node *Remove)
{
	if (*Head == Remove)
		*Head = Remove->NextNode;
	else
	{
		Node *Current = *Head;
		while (Current != NULL && Current->NextNode != Remove) Current = Current->NextNode;
		if (Current != NULL) Current->NextNode = Remove->NextNode;
	}

}

void SLL_DestoryNode(Node *Node)
{
	free(Node);
}

void SLL_InsertAfter(Node *Current, Node *NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node **Head, Node *NewHead)
{
	if (Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

int SLL_GetNodeCount(Node *Head)
{
	int count = 0;
	Node *Current = Head;
	while (Current != NULL)
	{
		Current = Current->NextNode;
		count++;
	}
	return count;
}
