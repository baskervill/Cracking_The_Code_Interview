#include <string>
#include <iostream>
using namespace std;
bool isSubstring(string s1, string s2){
    if(s1.find(s2) != string::npos) return true;
    else return false;
}
bool isRotation(string s1, string s2){
    if(s1.length() != s2.length()) return false;
    string s3 = s1 + s1;
    if(isSubstring(s3,s2)) return true;
    else return false;
}
int main(){
    string s1 = "apple";
    string s2 = "pleap";
    bool flag = isRotation(s1, s2);
    cout<<flag<<endl;
    return 0;
}
