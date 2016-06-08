#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
	NODE *pHead, *pTail;
};
typedef struct List LIST;

void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

NODE* GetNode(int x)
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		exit(0);
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}

void AddHead(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}	
}

void AddTail(LIST &l, NODE *p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	l.pTail->pNext = p;
	l.pTail = p;
}

void DelHead(LIST &l)
{
	if(l.pHead != NULL)
	{
		NODE *p = l .pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

void DelLast(LIST &l)
{
	NODE *g;
	for(NODE *p = l.pHead; p ; p = p->pNext)
	{
		if(p == l.pTail)
		{
			g->pNext = NULL;
			l.pTail = g;
			delete p;
			return;
		}
		g = p;
	}
}

void InputList(LIST &l)
{
	Init(l);
	int n;
	cout << "\nInput elements: ";
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		int x;
		cout << "\nInput data: ";
		cin >> x;
		NODE *p = GetNode(x);
		AddHead(l, p);
		//AddTail(l, p);
	}
}

void OutputList(LIST l)
{
	for(NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		cout << p->data << "    ";
	}
}

void FreeList(LIST &l)
{
	NODE *p;
	while(l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

int main()
{
	LIST l;
	InputList(l);
	OutputList(l);
	FreeList(l);
	return 0;
}