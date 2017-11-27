#include <iostream>
using namespace std;
typedef long long ll;
//recursion
long long fib(long long n){
    if(n < 1) return -1;
    if(n == 1 | n == 2) return 1;
    else return fib(n - 1) + fib(n - 2);
}
//O(n)
long long fib1(long long n){
    if(n < 1) return -1;
    if(n == 1 | n == 2) return 1;
    long long a = 1, b = 1;
    for(long long i = 3;i <= n;i++){
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;

}

//fast power
//O(n), ordinary
ll pow(ll m, ll n){
    ll res = 1;
    for(int i = 0;i < n;i++){
        res *= m;
    }
    return res;
}
//fast power O(logn)
ll pow1(ll m, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res *= m;
        m *= m; // reserve the square
        n >>= 1;
    }
    return res;
}
//fast power for matrix
//ordinary matrix multiply
void mul(ll c[2][2], ll a[2][2], ll b[2][2]){
    ll t[4];
    t[0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    t[1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    t[2] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    t[3] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    c[0][0] = t[0];
    c[0][1] = t[1];
    c[1][0] = t[2];
    c[1][1] = t[3];
}
void pow2(ll s[2][2], ll a[2][2], ll n){
    while(n > 0){
        if(n & 1) mul(s, s, a);
        mul(a, a, a);
        n >>= 1;
    }
}
//then fib can be resolved by fast matrix multiply
ll fib2(ll n){
    if(n < 1) return -1;
    if(n == 1 | n == 2) return 1;
    ll a[2][2] = {{1,1}, {1, 0}};
    ll s[2][2] = {{1,0}, {0, 1}};
    pow2(s, a, n - 2);
    return s[0][0] + s[0][1];

}
int main(){
    for(int i = 0 ;i < 20;i++){
        cout<<fib(i)<<" ";
    }
    cout<<endl;
    for(int i = 0;i < 20;i++){
        cout<<fib1(i)<<" ";
    }
    cout<<endl;
    for(int i = 0;i < 20;i++){
        cout<<fib2(i)<<" ";
    }
    cout<<endl;
    return 0;
}