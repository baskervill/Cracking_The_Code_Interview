//for each node ,reserve two values, this value and the current min
#include <stack>
#include <iostream>
using namespace std;
const int MAX_INT = ~(1<<31);//2147483647
typedef struct node{
    int val, min;
}node;

class stackWithMin{
private:
    node *buf;
    int cur;
public:
    stackWithMin(int size = 1000){
        buf = new node[size];
        buf[0].min = MAX_INT;
        cur = 0;
    }
    ~stackWithMin(){
        delete[] buf;
    }
    void push(int val){
        buf[cur + 1].val = val;
        if(val < buf[cur].min)
            buf[cur + 1].min = val;
        else
            buf[cur + 1].min = buf[cur].min;
        cur++;
    }
    void pop(){
        cur--;
    }
    int top(){
        return buf[cur].val;
    }
    int min(){
        return buf[cur].min;
    }

};
//use another ordinary stack to save all the mins, the above has too many redundant
//push always not problem, when pop, if the value is equal the top of the second
//stack's value then ,pop the second stack too

class stackWithMin1{
private:
    stack<int> s1;
    stack<int> s2;
public:
    stackWithMin1(){}
    ~stackWithMin1(){}
    void push(int val){
        s1.push(val);
        if(val <= min())
            s2.push(val);
    }
    void pop(){
        if(s1.top() == min())
            s2.pop();
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    int min(){
        if(s2.empty()) return MAX_INT;
        else return s2.top();
    }

};
int main(){
    stackWithMin mystack;
    for(int i = 0;i < 20;i++){
        mystack.push(i);
    }
    cout<<mystack.min()<<endl;
    mystack.push(-100);
    cout<<mystack.min()<<endl;
    mystack.pop();
    cout<<mystack.min()<<endl;
    return 0;
}

