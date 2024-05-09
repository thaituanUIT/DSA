#include <iostream>
#include <queue>
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

int Height(TREE T) {
    if (T == NULL) return 0;
    else {
        int lheight = Height(T->pLeft);
        int rheight = Height(T->pRight);

        if (lheight > rheight) return lheight + 1;
        else return rheight + 1;
    }
}

void PrintLevel(TREE T, int& level) {
    if (T == NULL) {
        cout << "Empty Tree.";
        return;
    }
    if (!(level < Height(T) && level >= 0)) {
        cout << "Khong ton tai level " << level << ".";
        return;
    }
    
    
}

//it doesn't work



int main() {
    TREE T;
    CreateEmptyTree(T);
    CreateTree(T);
	int level;
	cin >> level;
	PrintLevel(T, level);
    return 0;
}