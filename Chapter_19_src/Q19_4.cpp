#include <iostream>
using namespace std;
int max1(int a, int b){
    int z = a - b;
    int k = (z>>31) & 1;
    return a - z * k;
}
int max2(int a, int b){
    int c[2] = {a, b};
    int z = a - b;
    int k = (z>>31) & 1;
    return c[k];
}
int main(){
    int a = 5;
    int b = 6;
    cout<<max1(a, b)<<endl;
    cout<<max2(a, b)<<endl;
    return 0;
}