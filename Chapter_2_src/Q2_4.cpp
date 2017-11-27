#include <iostream>
#include <unordered_map>
using namespace std;
struct node{
    int data;
    node* next;
};
node* addlink(node* p, node* q){
    if(p == NULL) return q;
    if(q == NULL) return p;
    node *res, *pre = NULL;
    int c = 0;
    while(p && q){
        node* r = new node();
        int t = p->data + q->data + c;
        c = t / 10;
        r->data = t % 10;
        if(pre){
            pre->next = r;
            pre = r;
        }
        else res = pre = r;//head node
        p = p->next;
        q = q->next;
    }
    while(p){
        node* r = new node();
        int t = p->data + c;
        r->data = t % 10;
        c = t / 10;
        pre->next = r;
        pre = r;
        p = p->next;
    }
    while(q){
        node* r = new node();
        int t = q->data + c;
        r->data = t % 10;
        c = t / 10;
        pre->next = r;
        pre = r;
        q = q->next;
    }
    if(c > 0){
        node* r = new node();
        r->data = 1;
        pre->next = r;
    }
    return res;  
}
node* init(int a[], int n){
    if(n == 0) return NULL;
    node *head, *p;
    for(int i = 0;i < n;i++){
        node *nd = new node();
        nd->data = a[i];
        if(i == 0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = p->next;
    }
    return head;
}
void print(node* node){
    while(node){
        cout<<node->data<<" ";
        node = node->next;
    }
}
int main(){
    int a[] = {1,2,3,4,5,6};
    int b[] = {9,4,8,4};
    node* p = init(a, 6);
    node* q = init(b, 4);
    node* res = addlink(p, q);
    print(res);
    return 0;
}