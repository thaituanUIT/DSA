#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE* pNext;
};

struct List
{
    NODE* pHead;
    NODE* pTail;
};

// Create an empty list
void CreateEmptyList (List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

// Create a new node
NODE* CreateNode (int x)
{
    NODE* p = new NODE;
    if (p == NULL)
    {
        cout << "Memory allocation failed!" << endl;
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

// add a node to the head of the list
void AddHead (List& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else 
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

// add a node to the tail of the list
void AddTail (List& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void reverse(List& l) {
    NODE* p = l.pHead;
    l.pHead = l.pTail;
    l.pTail = p;
    NODE* q = p->pNext;
    p->pNext = NULL;
    while (q != NULL) {
        p = q;
        q = q->pNext;
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

// Quick sort on linked list
void Partition(List& l, List& l1, NODE*& pivot, List& l2)
{
    pivot = l.pHead;
    NODE* p = l.pHead->pNext;
    while (p != NULL)
    {
        NODE* pNext = p->pNext;
        if (p->data > pivot->data)
        {
            AddHead(l2, p);
        }
        else
        {
            AddHead(l1, p);
        }
    }
}

void Join (List& l, List& l1, NODE* pivot, List& l2)
{
    if (l1.pHead != NULL)
    {
        l.pHead = l1.pHead;
        l1.pTail->pNext = pivot;
    }
    else
    {
        l.pHead = pivot;
    }
    if (l2.pHead != NULL)
    {
        pivot->pNext = l2.pHead;
        l.pTail = l2.pTail;
    }
    else
    {
        l.pTail = pivot;
    }
}

void QuickSort (List& l)
{
    if (l.pHead == NULL || l.pHead == l.pTail)
    {
        return;
    }
    List l1, l2;
    CreateEmptyList(l1);
    CreateEmptyList(l2);

    NODE* pivot;
    Partition(l, l1, pivot, l2);

    if (l1.pHead != l1.pTail)
    {
        QuickSort(l1);
    }
    if (l2.pHead != l2.pTail)
    {
        QuickSort(l2);
    }
    Join(l, l1, pivot, l2);
}

// Merge sort on linked list
void MergeSplit(List& l, List& l1, List& l2)
{
    NODE* p =l.pHead;
    while (p != NULL)
    {
        AddTail(l1, p);
        p = p->pNext;
        if (p != NULL)
        {
            AddTail(l2, p);
            p = p->pNext;
        }
    }
    l.pHead = NULL;
    l.pTail = NULL;
}

void Merge(List& l, List& l1, List& l2)
{
    NODE* p1 = l1.pHead;
    NODE* p2 = l2.pHead;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            AddTail(l, p1);
            p1 = p1->pNext;
        }
        else
        {
            AddTail(l, p2);
            p2 = p2->pNext;
        }
    }
    while (p1 != NULL)
    {
        AddTail(l, p1);
        p1 = p1->pNext;
    }
    while (p2 != NULL)
    {
        AddTail(l, p2);
        p2 = p2->pNext;
    }
}

void MergeSort(List& l)
{
    if (l.pHead == l.pTail)
    {
        return;
    }
    List l1, l2;
    MergeSplit(l, l1, l2);
    MergeSort(l1);
    MergeSort(l2);
    Merge(l, l1, l2);
}

// insertion sort on linked list
void InsertionSort (List& l)
{
    if (l.pHead == l.pTail)
    {
        return;
    }
    NODE* p = l.pHead->pNext;
    while (p != NULL)
    {
        NODE* pNext = p->pNext;
        NODE* pPrev = NULL;
        NODE* q = l.pHead;
        while (q != p && q->data < p->data)
        {
            pPrev = q;
            q = q->pNext;
        }
        if (q != p)
        {
            if (pPrev == NULL)
            {
                l.pHead = p->pNext;
            }
            else
            {
                pPrev->pNext = p->pNext;
            }
            p->pNext = q;
            if (pPrev == NULL)
            {
                l.pHead = p;
            }
            else
            {
                pPrev->pNext = p;
            }
        }
        p = pNext;
    }
}

// selection sort on linked list
void SelectionSort (List& l)
{
    if (l.pHead == l.pTail)
    {
        return;
    }
    NODE* p = l.pHead;
    while (p != l.pTail)
    {
        NODE* pMin = p;
        NODE* q = p->pNext;
        while (q != NULL)
        {
            if (q->data < pMin->data)
            {
                pMin = q;
            }
            q = q->pNext;
        }
        if (pMin != p)
        {
            int temp = p->data;
            p->data = pMin->data;
            pMin->data = temp;
        }
        p = p->pNext;
    }
}

// Print the list 
void PrintList (List l)
{
    NODE* p = l.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
}