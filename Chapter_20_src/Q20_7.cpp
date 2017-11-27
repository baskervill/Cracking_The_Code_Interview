#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
unordered_map<string, int> hash1;
bool MakeOfWords(string word, int length){
    int len = word.length();
    if(len == 0) return true;

    for(int i = 1;i <= len;i++){
        if(i == length) return false;
        string str = word.substr(0, i);
        //cout<<str<<endl;
        if(hash1.find(str) != hash1.end()){
            if(MakeOfWords(word.substr(i),length)){
                return true;
            }
        }
    }
    return false;

}
bool cmp(string s1, string s2){
    return s1.length() > s2.length();
}
string longestWord(string words[], int n){
    sort(words, words + n, cmp);
    for(int i = 0;i < n;i++)
        hash1[words[i]] = i;
    for(int i = 0;i < n;i++)
        if(MakeOfWords(words[i], words[i].length()))
            return words[i];
    return NULL;
}
int main(){
    string arr[] = {"test", "tester", "testertest", "testing", 
				"apple", "seattle", "banana",  "batting", "ngcat", 
                "batti","bat", "testingtester", "testbattingcat"};
    int len = 13;
    cout<<longestWord(arr, len)<<endl;;
    return 0;
}