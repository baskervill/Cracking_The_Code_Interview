#include <iostream>
#include <stack>
using namespace std;
//start status:(1~n, 0, 0)
//destination status:(0, 0, 1~n)
//there must be a status like this:(n, 1~n-1, 0)
//then move n to dst, like this:(0, 1~n - 1, n)
void hanoi(int n, char src, char bri, char dst){//this function means move 1~n disks from src to dst via bri
    if(n == 1){
        cout<<"move disk "<<n<<" from "<<src<<" to "<<dst<<endl;
    }
    else{ //there is no return , so take care of this
        hanoi(n - 1, src, dst, bri);
        cout<<"move disk "<<n<<" from "<<src<<" to "<<dst<<endl;
        hanoi(n - 1, bri, src, dst);
    }

}
//use a stack instead of a recursion, then I can use this to solve the preorder traversal problem
//the status has four styles:
//(1~n, 0, 0)
//(n, 1~n-1, 0)
//(0, 1~n-1, n)
//(0, 0, 1~n)
//need a data structure op to reserve all the arguments in the process
struct op{
    int begin, end;
    char src, bri, dst;
    op(){}
    op(int pbegin, int pend, char psrc, char pbri, char pdst ):begin(pbegin),end(pend),src(psrc),bri(pbri),dst(pdst){}
};
// move begin to end ,from src to dst via bri status
void hanoi1(int n, char src, char bri, char dst){
    stack<op> st;
    op tmp;
    st.push(op(1, n, src, bri, dst));//(0, 1~n-1, n)->(0, 0, 1~n) this is the destination
    while(!st.empty()){
        tmp = st.top();
        st.pop();
        if(tmp.begin != tmp.end){//three push indicates the status variation between the four states 
            st.push(op(tmp.begin, tmp.end - 1, tmp.bri, tmp.src, tmp.dst));//(0, 1~n-1, n)->(0, 0, 1~n)
            st.push(op(tmp.end, tmp.end, tmp.src, tmp.bri, tmp.dst));//(n, 1~n-1, 0)->(0, 1~n-1, n)
            st.push(op(tmp.begin, tmp.end - 1, tmp.src, tmp.dst, tmp.bri));//(1~n, 0, 0)->(n, 1~n-1, 0)
        }//the order is reverse ,so pop the right answer
        else{ //if begin == end , then it can be move from src to dst
            cout<<"Move disk "<<tmp.begin<<" from "<<tmp.src<<" to "<<tmp.dst<<endl;
        }
    }

}
int main(){
    int n = 3;
    hanoi1(n, 'A', 'B', 'C');
    return 0;
}