#include <iostream>
#include <unordered_map>
using namespace std;
struct node{
    int data;
    node* next;
};
//use a fast pointer and a low point, when the two pointer meet,
node* loopstart1(node* head){
    if(head == NULL) return NULL;
    node* fast = head, *slow = head;
    //the fast two times faster than the slow
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) break;
    }
    if(!fast || !fast->next) return NULL;
    slow = head;
    //the two pointers reach the same speed ,they will meet at the beginning of the loop
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
//use a hash map to store the nodes
node* loopstart(node* head){
    unordered_map<node* ,bool> hash;
    while(head){
        if(hash.find(head) != hash.end()){
            if(hash[head]) return head;
        }
        else{
            hash[head] = true;
        }
        head = head->next;
    }
    return NULL;
}
node* init(int a[], int n, int m){
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
    node* q = head;
    for(int i = 0;i < m;i++){
        q = q->next;
    }
    p->next = q;
    return head;
}
int main(){
    int a[] = {1,2,3,4,5,6,3};
    node* head = init(a, 6, 0);
    node* start = loopstart1(head);
    cout<<start->data<<endl;
    return 0;
}