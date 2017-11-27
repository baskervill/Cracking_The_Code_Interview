#include <iostream>
using namespace std;
int fetch(int a[], int i, int j){
    return (a[i] >> j) & 1;
}
int get(int a[], int i){
    int b = 0;
    for(int j = 32;i > 0;j--){
        b = b<<1 | fetch(a, i, j);
    }
    return b;
}
int missing(int a[], int n){
    bool *b = new bool[n + 1];
    memset(b, false, sizeof(b));
    for(int i = 0;i < n;i++){
        b[get(a, i)] = true;
    }
    for(int i = 0;i < n + 1;i++){
        if(b[i] != true) return i;
    }
    delete[] b;
}
int main(){
    int a[] = {0,1,2,3,4,5,6,7,8};
    cout<<missing(a, 8)<<endl;
}
