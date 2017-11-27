#include <iostream>
#include <unordered_map>
using namespace std;
struct node{
    int data;
    node* next;
};
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
//if can have a hash_map ,can reach O(n) time
void removeDuplicate(node *head){
    //bool flag[256];//better use a hash_map , always the array is very large
    unordered_map<int, bool> flag;
    if(head == NULL) return ;
    node *p = head, *q = head->next;
    //memset(flag, false, sizeof(flag));
    flag[p->data] = true;
    while(q != NULL){    //not include the head one 
        if(flag.find(q->data) != flag.end()){ //unordered_map need a pair and find returns a location
            node *tmp = q;
            p->next = q->next;
            q = p->next;
            delete tmp;  
        }
        else{
            //flag[q->data] = true;
            flag[q->data] = true;// hash_map <int, bool>
            p = q;
            q = q->next;
        }
    }
}
//if there is no ultra space to use,use another pointer, and time can reach O(n ^ 2)
void removeDuplicate2(node *head){
    node *p , *q, *c = head;
    while(c){
        p = c, q = c->next;
        int d = c->data;
        while(q){
            if(d == q->data){
                node *tmp = q;
                p->next = q->next;
                q = p->next;
                delete tmp;
            }
            else{
                p = q;
                q = q->next;
            }
        }
        c = c->next;
    }
}
void print(node *node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
}
int main(){
    int a[] = {1,2,3,1,2,4,5,6};
    node *p = init(a, 8);
    removeDuplicate2(p);
    print(p);
    return 0;

}