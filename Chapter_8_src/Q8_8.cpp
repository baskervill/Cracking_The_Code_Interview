#include <iostream>
using namespace std;
int cnt = 0;
int n = 8;
int c[20];
void search(int r){
    if(r == n){
        //print();
        cnt++;
        return;
    }
    for(int i = 0;i < n;i++){
        c[r] = i;
        int ok = 1;
        for(int j = 0;j < r;j++){
            if(c[r] == c[j] || r - j == c[r] - c[j] || r - j == c[j] - c[r]){
                ok = 0;
                break;
            }
        }
        if(ok) search(r + 1);
    }
}
int main(){
    search(0);
    cout<<cnt<<end;
    return 0;
}