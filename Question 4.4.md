## 题目

原文：

Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).

译文：

给定一棵二叉查找树，设计算法，将每一层的所有结点构建为一个链表(也就是说， 如果树有D层，那么你将构建出D个链表)

## 解答

这道题目本质上是个BFS，也就是说，如果已经构建了第i层结点的链表， 那么将此链表中每个结点的左右孩子结点取出，即可构建第i+1层结点的链表。 设结点类型为Node，那么指向每一层链表头结点的类型为list<Node*>， 将每一层头结点指针放到vector中。如果当前层的链表不为空， 那么将该链表的结点依次取出，然后将这些结点的不为空的孩子放入新的链表中。

代码如下：

```cpp
vector<list<Node*> > find_level_linklists(Node *head){
	vector<list<Node*> > res;
	int level = 0;
	list<Node*> li;
	li.push_back(head);
	res.push_back(li);
	while(!res[level].empty()){
		list<Node*> l;
		list<Node*>::iterator it;
		for(it=res[level].begin(); it!=res[level].end(); ++it){
			Node *n = *it;
			if(n->lchild) l.push_back(n->lchild);
			if(n->rchild) l.push_back(n->rchild);
		}
		++level;
		res.push_back(l);
	}
	return res;
}

```

完整代码如下：

```cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
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
void createMinimalTree(Node* &head, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        createMinimalTree(head->lchild, head, a, start, mid-1);
        createMinimalTree(head->rchild, head, a, mid+1, end);
    }
}

vector<list<Node*> > find_level_linklists(Node *head){
    vector<list<Node*> > res;
    int level = 0;
    list<Node*> li;
    li.push_back(head);
    res.push_back(li);
    while(!res[level].empty()){
        list<Node*> l;
        list<Node*>::iterator it;
        for(it=res[level].begin(); it!=res[level].end(); ++it){
            Node *n = *it;
            if(n->lchild) l.push_back(n->lchild);
            if(n->rchild) l.push_back(n->rchild);
        }
        ++level;
        res.push_back(l);
    }
    return res;
}
void print(vector<list<Node*> > res){
    vector<list<Node*> >::iterator vit;
    for(vit=res.begin(); vit!=res.end(); ++vit){
        list<Node*> li = *vit;
        list<Node*>::iterator lit;
        for(lit=li.begin(); lit!=li.end(); ++lit){
            Node *n = *lit;
            cout<<n->key<<" ";
        }
        cout<<endl;
    }
}
int main(){
	init();
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8
    };
    Node *head = NULL;
    createMinimalTree(head, NULL, a, 0, 6);
    vector<list<Node*> > res;
    res = find_level_linklists(head);
    print(res);
    return 0;
}

```