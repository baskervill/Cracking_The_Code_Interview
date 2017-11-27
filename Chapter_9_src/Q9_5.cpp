#include <iostream>
#include <algorithm>
using namespace std;

int search(string s[], int begin, int end, string target){
    if(target == "") return -1;
    while(begin <= end){
        int mid = (begin + end) >> 1;
        int t = mid;
        while(s[t] == "" && t <= end){
            t += 1;
        }
        if(t > end) end = mid - 1;// from mid to end possible all ""
        else if(s[t] == target) 
            return t;
        else if(s[t] < target){
            begin = t + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}
int main(){
    string s[13] = {"at", "","", "", "ball", "", "", "car", "","", "dad", "", ""};
    int res = search(s, 0, 12, "at");
    cout<<res<<endl;
    return 0;

}