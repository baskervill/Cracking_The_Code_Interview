## 题目

原文：

Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in a binary search tree where each node has a link to its parent.

译文：

给定二叉查找树的一个结点， 写一个算法查找它的“下一个”结点(即中序遍历后它的后继结点)， 其中每个结点都有指向其父亲的链接。

## 解答

我们知道，在二叉查找树中， 每个结点的值都大于等于它左子树所有结点的值且小于右子树所有结点的值( 或是大于它左子树所有结点的值且小于等于右子树所有结点的值，等号放哪边示情况而定。) 二叉查找树中序遍历后，元素将按递增排序， 某一结点的后继结点即为比该结点大的结点中最小的一个。如果该结点有右儿子， 则后继结点为右儿子的最左子孙。否则需要不断地向上查找该结点的祖先， 直到找到第一个比它大的结点为止。

代码如下：

```cpp
Node* minimal(Node* no){
    if(no == NULL) return NULL;
    while(no->lchild)
        no = no->lchild;
    return no;
}
Node* successor(Node* no){
    if(no == NULL) return NULL;
    if(no->rchild) return minimal(no->rchild);
    Node *y = no->parent;
    while(y && y->rchild==no){
        no = y;
        y = y->parent;
    }
    return y;
}

```

完整代码如下：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *p, node[maxn];
int cnt;

void init(){
    p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}
Node* minimal(Node* no){    
    if(no == NULL) return NULL;
    while(no->lchild)
        no = no->lchild;
    return no;
}
Node* successor(Node* no){
    if(no == NULL) return NULL;
    if(no->rchild) return minimal(no->rchild);
    Node *y = no->parent;
    while(y && y->rchild==no){
        no = y;
        y = y->parent;
    }
    return y;
}
int main(){
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    init();
    Node *head = NULL;
    create_minimal_tree(head, NULL, a, 0, 9);
    cout<<"the head is "<<head->key<<endl;
    cout<<"the successor of head is: "<<(successor(head))->key<<endl;
    return 0;
}

```