#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};

struct queue {
    NODE* head;
    NODE* tail;
};

void createEmptyQueue(queue &q) {
    q.head = NULL;
    q.tail = NULL;
}

NODE *CreateNode(int x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}

bool isEmpty(queue q) {
    if (q.head == NULL)
    {
        return true;
    }
    return false;
}

int size(queue q) {
    int count = 0;
    NODE* p = q.head;
    while (p != NULL)
    {
        count++;
        p = p->pNext;
    }
    return count;
}

void enqueue(queue &q, NODE* p){
    if (q.head == NULL)
    {
        q.head = p;
        q.tail = p;
    }
    else {
        q.tail->pNext = p;
        q.tail = p;
    }
}

void dequeue(queue &q) {
    if (isEmpty(q)) return;
    NODE* p = q.head;
    q.head = q.head->pNext;
    delete p;
}

void CreateQueue(queue& q) {
    int n, x;
    cin >> n;
    while(n-->0) {
        cin >> x;
        NODE* p = CreateNode(x);
        enqueue(q, p);
    }
}