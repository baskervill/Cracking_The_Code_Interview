#include <iostream>
#include <unordered_map>
using namespace std;
struct node{
    int data;
    node* next;
};
void remove(node* c){
    if(c == NULL) return; 
    if(c->next == NULL){
        delete c;
        return;
    }// tail node, it is really a problem here ,why? need a special process
    node* q = c->next;
    c->data = q->data;
    c->next = q->next;
    delete q;
}
bool remove1(node* c){
    if(c == NULL || c->next == NULL) return false; 
    node* q = c->next;
    c->data = q->data;
    c->next = q->next;
    delete q;
    return true;
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
void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main(){
    int a[] = {1,2,3,4,5,6,7};
    node* head = init(a, 7);
    node* p = head;
    int cc = 6;
    for(int i = 0;i < cc;i++) {
        head = head->next;
    }
    //remove(head);
    if(remove1(head)) //there is something to process for tail node
        print(p); // something strange when delete the tail node ,looks like nothing happens
    return 0;
}