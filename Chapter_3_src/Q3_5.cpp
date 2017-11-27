#include <stack>
#include <iostream>
using namespace std;
//everytime a push in queue, then, move all into the first stack, then push
//everytime a pop in queue, put all into the second stack, then pop,
//template <typename T> MyQueue<int> to initial it
class MyQueue{
private:
    stack<int> s1, s2;
public:
    MyQueue(){}
    ~MyQueue(){}
    void push(int val){
        move(s2, s1);
        s1.push(val);
    }
    void pop(){
        move(s1, s2);
        s2.pop();
    }

    int front(){
        move(s1, s2);
        s2.top();
    }
    int back(){
        move(s2, s1);
        s1.top();
    }
    bool empty(){
        return s1.empty() && s2.empty();
    }
    int size(){
        return s1.size() + s2.size();
    }
    void move(stack<int> &stack1, stack<int> &stack2){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
};
//reduce the move operations, only the second is NULL then 
class MyQueue1{
private:
    stack<int> s1, s2;
public:
    MyQueue1(){}
    ~MyQueue1(){}
    void push(int val){
        s1.push(val);
    }
    void pop(){
        move(s1, s2);
        s2.pop();
    }
    int front(){
        move(s1, s2);
        return s2.top();
    }
    int back(){
        move(s2, s1);
        return s1.top();
    }
    bool empty(){
        return s1.empty() && s2.empty();
    }
    int size(){
        return s1.size() + s2.size();
    }
    void move(stack<int> &stack1, stack<int> &stack2){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

};
int main(){
    MyQueue1 queue;
    for(int i = 0;i < 10;i++){
        queue.push(i);
    }
    cout<<queue.size()<<endl;
    cout<<queue.front()<<endl;
    cout<<queue.back()<<endl;
    queue.pop();
    cout<<queue.front()<<endl;
    return 0;
}