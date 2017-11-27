#include <iostream>
using namespace std;
int getMaxSum(int a[], int n){
    if(a == NULL || n <= 0){
        return 0;
    }
    int curSum = a[0];
    int maxSum = a[0];
    for(int i = 1;i < n;i++){
        if(curSum <= 0)
            curSum = a[i];
        else 
            curSum += a[i];
        if(curSum > maxSum)
            maxSum = curSum;
    }
    return maxSum;
}
int main(){
    int a[] = {1,2,-1,-1,5,-1};
    int res = getMaxSum(a, 6);
    cout<<res<<endl;
    return 0;
}