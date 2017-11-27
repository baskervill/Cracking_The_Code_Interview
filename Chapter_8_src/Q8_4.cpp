#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<string> vs;
vs permu(string s){
    vs result;
    if(s == ""){
        result.push_back("");
        return result;
    }
    string c = s.substr(0, 1);
    vs res = permu(s.substr(1));
    for(int i = 0;i < res.size();i++){
        string t = res[i];
        for(int j = 0;j <= t.length();j++){
            string u = t;
            u.insert(j, c);
            result.push_back(u);
        }
    }
    return result;
}
vs permu1(string s){
    vs result;
    if(s == ""){
        result.push_back("");
        return result;
    }
    for(int i = 0;i < s.length();i++){
        string c = s.substr(i, 1);
        string t = s;
        vs res = permu1(t.erase(i, 1));
        for(int j = 0;j < res.size();j++){
            result.push_back(c + res[j]);
        }
    }
    return result;
}
int main(){
    string s = "abc";
    sort(s.begin(), s.end());
    do{
        cout<<s<<" ";
    }while(next_permutation(s.begin(), s.end()));
    cout<<endl;
    vs result1 = permu(s);
    for(int i = 0;i < result1.size();i++){
        cout<<result1[i]<<" ";
    }
    cout<<endl;
    vs result2 = permu1(s);
    for(int i = 0;i < result2.size();i++){
        cout<<result2[i]<<" ";
    }
    cout<<endl;
    return 0;
}