#include <iostream>
using namespace std;
int search(int a[], int begin, int end, int target){
    while(begin <= end){
        int mid = (begin + end) >> 1;
        if(a[mid] == target) return mid;
        if(a[mid] > a[begin]){
            if(target < a[mid] && target > a[begin])
                end = mid - 1;
            else
                begin = mid + 1;
        }
        if(a[mid] < a[begin]){
            if(target < a[end] && target > a[mid])
                begin = mid + 1;
            else
                end = mid - 1;
        }
    }
    return -1;
}
int main(){
    int a[] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int res = search(a, 0, 12, 3);
    cout<<res<<endl;
    return 0;
}