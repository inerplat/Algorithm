#include "Linkedlist.h"
#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int count = 0;
	Node *List = NULL;
	Node *Current = NULL;
	Node *NewNode = NULL;
	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	NewNode = SLL_CreateNode(-1);
	SLL_AppendNode(&List, NewNode);

	NewNode = SLL_CreateNode(-2);
	SLL_AppendNode(&List, NewNode);

	count = SLL_GetNodeCount(List);
	for (i = 0; i < count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] :" << Current->DATA << endl;
	}

	cout << endl << "Inserting 3000 After [2]" << endl << endl;

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);

	count = SLL_GetNodeCount(List);
	for (i = 0; i < count; i++)
	{
		Current = SLL_GetNodeAt(List, i);
		cout << "List[" << i << "] :" << Current->DATA << endl;
	}

	cout << endl << "Destroying List" << endl;
	for (i = 0; i < count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveNode(&List, Current);
			SLL_DestoryNode(Current);
		}
	}
	return 0;
}
