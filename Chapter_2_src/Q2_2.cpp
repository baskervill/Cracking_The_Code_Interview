#include <iostream>
#include <unordered_map>
using namespace std;
struct node{
    int data;
    node* next;
};
//I used to use a int count to mermorized the length of the linked list 
//use a stack to implement , a stack is the represent of recursion, but use two global, not beautiful
node *pp;
int nn;
node* findNthtolast1(node* head){
    if(head == NULL) return NULL;
    findNthtolast1(head->next);
    if(nn == 1) pp = head;
    --nn;
}
//maintain two pointers that maintain distance of n
node* findNthtolast2(node* head, int n){
    if(head == NULL || n < 1) return NULL;
    node* p = head, *q = head;
    for(int i = 0;i < n;i++) q = q->next;
    while(q){
        p = p->next;
        q = q->next;
    }
    return p;
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
int main(){
    int a[] = {1,2,3,4,5,6,7};
    node* head = init(a, 7);
    node* pp = findNthtolast2(head, 2);
    cout<<pp->data<<endl;
    //cout<<nth<<endl;
}