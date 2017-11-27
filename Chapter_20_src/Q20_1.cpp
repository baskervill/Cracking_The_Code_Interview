#include <iostream>
using namespace std;
//implement + without using +
int Add(int a, int b){
    if(b == 0) return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return Add(sum, carry);
}
int Add1(int a, int b){
    while(b != 0){
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}
/*
int Add2(char  a, char  b){
    char *c = (char*) a;
    return (char)&c[b];
}
*/
int main(){
     int a = 16;
     int b = 8;
    cout<<Add1(a, b)<<endl;
    return 0;
}