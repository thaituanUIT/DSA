#include <iostream>
using namespace std;

struct NODE{
    int info;
    NODE *next;
};
struct stack{
    NODE* head;
    NODE* tail;
};
NODE *CreateNode(int x){
    NODE *p=new NODE;
    p->info=x;
    p->next=NULL;
    return p;
}

void createEmptyStack(stack &s){
    s.head = NULL;
    s.tail = NULL;
}

void Push(stack &s,NODE* p){
    if (s.head == NULL)
    {
        s.head = p;
        s.tail = p;
    }
    else {
        p->next = s.head;
        s.head = p;
    }
}

int Pop(stack &s, int &x){
    if (s.head== NULL)
        return -1;
    x = s.head->info;
    NODE* p = s.head;
    s.head = s.head->next;
    if(s.head== NULL)
        s.tail = NULL;
    delete p;
    return 0;
}

int Top(stack s)
{
    if (s.head == NULL) {

        return -1;
    }
    return s.head->info;
}

bool empty(stack &s) {
    return s.head == NULL;
}


void Testing_Push_Pop_Top_Stack(stack &s){
    createEmptyStack(s);
    int x;
    cin >> x;
    cout << "output: ";
    while (x != -1) { // Changed from x != 0 to x != -1
        if (x != 0)
            Push(s, CreateNode(x));
        if (x == 0)
        {
            int topValue = Top(s);
            if (topValue != -1)
            {
                cout << topValue << " ";
                Pop(s, x);
            }

        }
        cin >> x;
    }
    cout << endl;
    if (empty(s) == true)
        cout << "top: ";
    else
    {
        cout << "top: ";
        cout << Top(s);
    }
}

void PrintStack(stack &s)
{
    for(NODE* i=s.head;i!=NULL;i=i->next)
        cout<<i->info<<" ";
}

int main() {
    stack s;
    Testing_Push_Pop_Top_Stack(s);
    return 0;
}