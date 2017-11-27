#include <iostream>
#include <stack>
#include <cstdlib>
#include <queue>
using namespace std;
//use another stack as the insertion sort , O(n ^ 2), stack t maintain sorted everytime a new data
//come in , those in t who bigger than it will be pushed into s
stack<int> Ssort(stack<int> s){
    stack<int> t;
    while(!s.empty()){
        int data = s.top();
        s.pop();
        while(!t.empty() && t.top() > data){
            s.push(t.top());
            t.pop();
        }
        t.push(data);
    }
    return t;
}
//use a priority queue 
void Qsort(stack<int> &s){
    priority_queue<int, vector<int>, greater<int> > q;
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    while(!q.empty()){
        s.push(q.top());
        q.pop();
    }
}
int main(){
    srand((unsigned) time(0));
    stack<int> s1;
    for(int i = 0;i < 10;i++){
        s1.push(rand() % 100);
    }
    Qsort(s1);
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return 0;
}