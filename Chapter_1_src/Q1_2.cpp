#include <cstring>
#include <iostream>
using namespace std;
void swap(char &a, char &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
// notice a c style string has '\0' in the end
void reverse1(char *s){
    if(s == NULL) return ;
    char *q = s ,*p = s;
    while (*q != '\0') q++;
    q--;
    while(p < q){
        swap(*p++, *q--);
    }
}
void reverse2(char *s){
    if(!s) return;
    int length = strlen(s);
    for(int i = 0;i < length / 2;i++){
        swap(s[i], s[length - i - 1]);
    }
}
int main(){
    char a[] = "abcd";
    reverse1(a);
    reverse2(a);
    cout<<a<<endl;
    return 0;
}