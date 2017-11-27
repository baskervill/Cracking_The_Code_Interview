#include <iostream>
#include <cstdlib>
using namespace std;
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
void RandomShuffle(int a[], int n){
    for(int i = 0;i < n;i++){
        int j = rand() % (n - i) + i;
        swap(a[i], a[j]);
    }
}
int main(){
    srand((unsigned) time(0));
    int n = 9;
    int a[] = {1,2,3,4,5,6,7,8,9};
    RandomShuffle(a, n);
    for(int i = 0;i < n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}