#include <iostream>
using namespace std;
const int Stack_Size = 100;
const int Stack_Num = 10;

class stack{
private:
    int *buf;
    int cur;
    int capacity;
public:
    stack(int capa = Stack_Size){
        buf = new int[capa];
        cur = -1;
        capacity = capa;
    }
    ~stack(){
        delete[] buf;
    }
    void push(int val){
        buf[++cur] = val;
    }
    void pop(){
        --cur;
    }
    int top(){
        return buf[cur];
    }
    bool empty(){
        return cur == -1;
    }
    bool full(){
        return cur == capacity - 1;
    }

};
class SetOfStacks{
private:
    stack *st;
    int cur;
    int capacity;
public:
    SetOfStacks(int capa = Stack_Num){
        st = new stack[capa];
        cur = 0;// index of the stacks
        capacity = capa;
    }
    ~SetOfStacks(){
        delete[] st;
    }
    void push(int val){
        if(st[cur].full()) ++cur;
        st[cur].push(val);
    }
    void pop(){
        while(st[cur].empty()) --cur;//must be while ,beacase there is possible several stack is empty 
        st[cur].pop(); //so as the popAt, top, empty
    }
    void popAt(int idx){
        while(st[idx].empty()) --idx;
        st[idx].pop();
    }
    int top(){
        while(st[cur].empty()) --cur;
        return st[cur].top();
    }
    bool empty(){
        while(st[cur].empty()) --cur;
        return st[cur].empty();
    }
    bool full(){
        if(cur == capacity - 1){
            return st[cur].full();
        }
        else return false;
    }
};
int main(){
    SetOfStacks ss1;
    for(int i = 0;i < 3 * Stack_Size + 1;i++){
        ss1.push(i);
    }
    for(int i = 0;i < Stack_Size; i++){
        ss1.popAt(0);
        ss1.popAt(2);
    }
    ss1.popAt(3);
    while(!ss1.empty()){
        cout<<ss1.top()<<endl;
        ss1.pop();
    }
    return 0;
}