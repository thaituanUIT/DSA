#include <iostream>
using namespace std;

struct NODE {
	int info;
	NODE* pNext;
};

struct LIST {
	NODE* pHead;
	NODE* pTail;
};

void CreateEmptyList(LIST& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST& L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = L.pHead;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void CreateList(LIST& L) {
    int n;
    while (true) {
        cin >> n;
        if (n == -1)
            break;
        NODE* p = CreateNode(n);
        AddTail(L, p);
    }
}

void Partition(LIST &L, LIST &L1, NODE *&pivot, LIST &L2) {
    NODE *p;

    if (L.pHead == NULL) return;

    pivot = SeparateHead(L);

    while (L.pHead != NULL) {
        p = SeparateHead(L);
        if (p->info <= pivot->info)
            AddTail(L1, p);
        else
            AddTail(L2, p);
    }
}

NODE* SeparateHead(LIST &L) {
    NODE*p = L.pHead;
    if (p == NULL) return NULL;

    L.pHead = L.pHead->pNext;
    if (L.pHead == NULL) L.pTail = NULL;

    p->pNext = NULL;
    return p;
}

void Join(LIST& L1, LIST& L2, NODE *pivot, LIST& L3)
{
    NODE *p;

    while (L2.pHead != NULL) {
        p = SeparateHead(L2);
        AddTail(L1, p);
    }

    AddTail(L1, pivot);

    while (L3.pHead != NULL) {
        p = SeparateHead(L3);
        AddTail(L1, p);
    }
}

void QuickSort(LIST &L) {
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);

    NODE *pivot;
    Partition(L, L1, pivot, L2);

    if (L1.pHead != L1.pTail)
        QuickSort(L1);
    if (L2.pHead != L2.pTail)
        QuickSort(L2);
    Join(L, L1, pivot, L2);
}

void PrintList(LIST L) {
    if (L.pHead == NULL)
        cout << "Empty List.";
    else {
        NODE* p = L.pHead;
        while (p) {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}

int main() {
    LIST L, L1, L2;

	int x;
	NODE *pivot;

	CreateEmptyList(L);
	CreateEmptyList(L1);
	CreateEmptyList(L2);

	CreateList(L1);
	cin >> x;
	pivot=CreateNode(x);
	CreateList(L2);


	Join(L, L1, pivot, L2);
	PrintList(L);

    return 0;
}
