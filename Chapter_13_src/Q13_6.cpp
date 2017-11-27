#include <iostream>
using namespace std;
class FirstClass{
    public:
        virtual void MethodA(int);
        virtual void MethodA(int, int);
    
};
void FirstClass::MethodA(int i){
    cout<<"One"<<endl;
}
void FirstClass::MethodA(int i, int j){
    cout<<"Two"<<endl;
}
class SecondClass : public FirstClass{
    public:
        void MethodA(int);
};
void SecondClass::MethodA(int i){
    cout<<"Three"<<endl;
}
int main(){
    SecondClass a;
    a.MethodA(1);
    a.MethodA(1, 1);//hide in the base
    return 0;
}