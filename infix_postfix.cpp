
#include <iostream>
using namespace std;
#define MAXN 100

struct NODE {
    char info;
    NODE *pNext;
};

struct stack {
    NODE* head;
    NODE* tail;
};

NODE *CreateNode(char x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
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
        p->pNext = s.head;
        s.head = p;
    }
}
int Pop(stack &s){
    if (s.head== NULL)
        return -1;
    NODE* p = s.head;
    s.head = s.head->pNext;
    if(s.head== NULL)
        s.tail = NULL;
    delete p;
    return 0;
}
char Top(stack s)
{
    if (s.head == NULL) {

        return -1;
    }
    return s.head->info;
}
bool empty(stack &s) {
    return s.head == NULL;
}

void PrintStack(stack &s)
{
    for(NODE* i=s.head;i!=NULL;i=i->pNext)
        cout<<i->info<<" ";
}

void Input_infix(char a[], int &n)
{
    char x;
    cin >> x;
    n = 0;
    while(x != '#')
    {
        a[n++] = x;
        cin >> x;
    }
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int priority(char op)
{
    if(op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infix_to_postfix(char infix[], int &ni, char postfix[], int &np)
{
    string res;
    stack s;
    createEmptyStack(s);
    for(int i = 0; i < ni; i++)
    {
        if(isdigit(infix[i]))
            res = res + infix[i];
        else if(infix[i] == '(')
        {
            Push(s,CreateNode(infix[i]));
        }
        else if(infix[i] == ')')
        {
            while(empty(s) != true && Top(s) != '(')
            {
                res += Top(s);
                Pop(s);
            }
            Pop(s);
        }
        else if(isOperator(infix[i]))
        {
            while(empty(s)!= true && priority(Top(s)) >= priority(infix[i]))
            {
                res = res + Top(s);
                Pop(s);
            }
            Push(s,CreateNode(infix[i]));
        }
    }

    while(empty(s) != true)
    {
        res = res + Top(s);
        Pop(s);
    }
    np=0;
    for(auto x : res)
    {
        postfix[np++] = x;
    }
}

void Output(char a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
