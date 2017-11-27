#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
//dictionary order to sort , the same is the answer, O(nlogn)
bool isAnagram1(string s, string t){
    if(s == "" || t == "") return false;
    if(s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t) return true;
    else return false;
}
//need a array, for ascii is 256, to statistic the times every  char appears, traverse the first to add
//the array , and minus the array when traverse the second one, make it O(n)
bool isAnagram2(string s, string t){
    if(s == "" || t == "") return false;
    if(s.length() != t.length()) return false;
    int times[256];
    int lens = s.length();
    int lent = s.length();
    memset(times, 0, sizeof(times));
    for(int i = 0; i < lens;i++){
        ++times[(int)s[i]];
        --times[(int)t[i]];
    }
    for(int i = 0;i < 256;i++){
        if(times[i]) return false;
    }
    return true;
}
int main(){
    string s = "abcde";
    string t = "bcda";
    bool flag = isAnagram2(s, t);
    cout<<flag<<endl;
    return 0;
}