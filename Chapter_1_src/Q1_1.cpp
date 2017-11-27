/*
description:
Implement an algorithm to determine if a string has all 
unique characters. What if you can not use additional 
data structures?
*/
#include <iostream>
#include <string>
using namespace std;
bool isunique1(string s){
    bool a[256];
    int order;
    bool flag = true;
    memset(a, false, sizeof(a));
    for(int i = 0; i < s.size();i++){
        order = (int)s[i];
        if(a[order]){
            flag = false;
            break;
        }
        else{
            a[order] = true;
        } 
    }
    return flag;
}
//1 int = 32 bit, 256 ascii need 8 int ,length is O(n) so dont put it into for
bool isunique2(string s){
    int a[8];
    memset(a, 0, sizeof(a));
    int length = s.length();
    int order;
    for(int i = 0;i < length;i++){
        order = (int)s[i];
        int idx = order / 32, shift = order % 32;
        if(a[idx] & (1<<shift)) return false;
        a[idx] |= (1<<shift);
    }
    return true;

}
//if there si only a-z or A-Z ,a int is enough
bool isunique3(string s){
    int length = s.length();
    int a = 0;
    for(int i = 0;i < length; i++){
        int order = s[i] - 'a';
        if(a & (1<<order)) return false;
        a |= (1<<order);
    }
    return true;
    
}
int main(){
    string s = "abc";
    bool flag = isunique1(s);
    cout<<flag<<endl;
    bool flag1 = isunique2(s);
    cout<<flag1<<endl;
    bool flag2 = isunique3(s);
    cout<<flag2<<endl;
}