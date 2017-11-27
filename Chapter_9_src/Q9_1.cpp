#include <iostream>
using namespace std;
//if the traditional mergesort, then will
//affect the current value, then try to compare from
//the last to the first
void merge(int a[], int b[], int n, int m){
    int k = n + m - 1;
    int i = n - 1, j = m - 1;
    while(i >= 0 && j >= 0){
        if(a[i] > b[j]) a[k--] = a[i--];
        else a[k--] = b[j--];
    }
    while(j >= 0) a[k--] = b[j--];
}
void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
void merge1(int a[], int begin, int mid, int end){
    for(int i = begin;i <= mid;i++){
        if(a[i] > a[mid + 1]){
            swap(a[i], a[mid + 1]);
            for(int j = mid + 1;j < end;j++){
                if(a[j] > a[j + 1]){
                    swap(a[j], a[j + 1]);
                }
                else break;
            }
        }
    }
}
int main(){
    int a[8] = {1,2,3,5};
    int b[4] = {4,6,7,8};
    merge(a, b, 4, 4);
    for(int i = 0; i < 8;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int c[10] = {8, 9, 11, 15, 17, 1, 3, 5, 12, 18};
    merge1(c, 0, 4, 9);
    for(int i = 0;i < 9;i++)
        cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}