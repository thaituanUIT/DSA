
#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

void CreateEmptyTree(TREE &T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}

void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}


void PrintTree(TREE T) {
    if (T == NULL)
    {
        cout << "Empty Tree." << endl;
        return;
    }
    if (T->pLeft != NULL)
    {
        PrintTree(T->pLeft);
    }
    cout << T->key << " ";
    if (T->pRight != NULL)
    {
        PrintTree(T->pRight);
    }
}

int Height(TREE T) {
    if (T == NULL) return 0;
    else {
        int lheight = Height(T->pLeft);
        int rheight = Height(T->pRight);

        if (lheight > rheight) return lheight + 1;
        else return rheight + 1;
    }
}

void PrintCurLevel(TREE T, int level) {
    if (T == NULL) return;
    if (level == 1) cout << T->key << " ";
    else {
        PrintCurLevel(T->pLeft, level - 1);
        PrintCurLevel(T->pRight, level - 1);
    }
}

void PrintTreeBFS(TREE T) {
    int h = Height(T);
    for (int i = 1; i <= h; i++) {
        PrintCurLevel(T, i);
        cout << endl;
    }
}

bool FindNode(TREE T, int x) {
    if (T == NULL) {
        return false;
    }
    if (T->key == x) {
        return true;
    }
    bool res1 = FindNode(T->pLeft, x);
    if (res1) return true;

    bool res2 = FindNode(T->pRight, x);
    return res2;
}

TNODE* FindParent1(TREE Root, const int &x) {
	if(Root==NULL) return NULL;
	if(Root->key==x) return NULL;

	TNODE *pre=NULL;
	TNODE *p = Root;
	while (p != NULL) {
		if (x == p->key) return pre;
		pre=p;
		if (x < p->key)	p = p->pLeft;
		else p = p->pRight;
	}
	return NULL;
}
void PrintParent(TREE T, int x) {
    if (T == NULL) {
        cout << "Empty Tree." << endl;
        return;
    }

    TNODE* parent = FindParent1(T, x);

    if (parent == NULL) {
        if (T->key == x)
            cout << x << " has no parent." << endl;
        else
            cout << "Not found " << x << "." << endl;
    } else {
        cout << parent->key << " is parent of " << x << "." << endl;
    }
}

void DeleteNodeX(TREE& T, int x) {
    if (T != NULL) {
        if (T->key < x) DeleteNodeX(T->pRight, x);
        else {
            if (T->key > x) DeleteNodeX(T->pLeft, x);
            else {
                TNODE* p;
                p = T;
                if (T->pLeft == NULL) T = T->pRight;
                else {
                    if (T->pRight == NULL) T = T->pLeft;
                    else Replace(p, T->pRight);
                }
                delete p;
            }
        }    
    }
}

void Replace(TREE& p, TREE& T) {
    if(T->pLeft != NULL) Replace(p, T->pLeft);
    else {
        p->key = T->key;
        p = T;
        T = T->pRight;
    }
}

bool Identical(TREE S, TREE T) {
    if (S == NULL && T == NULL) {
        return true;
    }
    
    if (S == NULL || T == NULL) {
        return false;
    }
    
    return (S->key == T->key && Identical(S->pLeft, T->pLeft) && Identical(S->pRight, T->pRight));
}

bool isSubtree(TREE S, TREE T) {
    if (S == NULL) return false;
    if (T == NULL) return false;
    if(Identical(S, T)) {
        return true;
    }
    return (isSubtree(S, T->pLeft) || isSubtree(S, T->pRight));
}

bool IsFullBinaryTree(TREE Root) {
    if (Root->pLeft == NULL && Root->pRight == NULL) {
        return true;
    }
    if ((Root->pLeft) && (Root->pRight)) {
        return (IsFullBinaryTree(Root->pLeft) && IsFullBinaryTree(Root->pRight));
    }
    return false;
}

int FindDepth(TREE T) {
    int depth = 0;
    while (T != NULL) {
        depth++;
        T = T->pLeft;
    }
    return depth;
}

bool IsPerfectBST(TREE T, int d, int level = 0) {
    
    if (T->pLeft == NULL && T->pRight == NULL) {
        return (d == level + 1);
    }
    
    if (T->pLeft == NULL || T->pRight == NULL) {
        return false;
    }
    
    return (IsPerfectBST(T->pLeft, d, level+1) && IsPerfectBST(T->pRight, d, level+1));
}

bool IsCompleteBST(TREE T) {
    queue<TREE> q;
    q.push(T);
    bool flag = false;
    while(!q.empty()) {
        TNODE* temp = q.front();
        q.pop();
        if(temp->pLeft) {
            if (flag == true) return false;
            q.push(temp->pLeft);
        } else flag = true;
        if(temp->pRight) {
            if (flag == true) return false;
            q.push(temp->pRight);
        } else flag = true;
    }   
    return true;
}

bool IsPerfectBinaryTree(TREE T) {
    int depth = FindDepth(T);
    return IsPerfectBST(T, depth);
}

int main()
{
    TREE S, T;
    CreateEmptyTree(S);
    CreateTree(S);
    CreateEmptyTree(T);
    CreateTree(T);
	return 0;
}