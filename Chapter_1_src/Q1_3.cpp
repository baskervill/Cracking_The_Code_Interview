#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
//no need for a spare array, O(n ^ 2)
void removeDuplicate1(char s[]){
    int length = strlen(s);
    if(length < 2) return;
    int p = 0;
    for(int i = 0;i < length;i++){
        if(s[i] != '\0'){
            s[p++] = s[i];
            for(int j=i+1; j < length; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
        }
    }
    s[p] = '\0';
}
//ascii set ,need a 256 array , O(n)
void removeDuplicate2(char s[]){
    bool flag[256];
    int len = strlen(s);
    if(len < 2) return;
    int p = 0;
    memset(flag, false, sizeof(flag));
    for(int i = 0;i < len;i++){
        if(!flag[(int)s[i]]){
            s[p++] = s[i];
            flag[(int)s[i]] = true;
        }
    }
    s[p] = '\0';
}
//only a-z, need a spare int, O(n)
void removeDuplicate3(char s[]){
    int flag = 0;
    int len = strlen(s);
    int p = 0;
    if(len < 2) return ;
    for(int i = 0;i < len;i++){
        if(!(flag & (1<<(s[i] - 'a')))) {
            s[p++] = s[i];
            flag |= 1<<(s[i] - 'a');
        }
    }
    s[p] = '\0';
}
/*
test cases:
0. no duplicate: "abcd"
1. all duplicate: "aaaa"
2. null :""
3. duplicate in step by step: "abaaad"
4. duplicate in seperately: "ababab"
*/
int main(){
    char s[] = "abaacd";
    removeDuplicate3(s);
    cout<<s<<endl;
    return 0;
}