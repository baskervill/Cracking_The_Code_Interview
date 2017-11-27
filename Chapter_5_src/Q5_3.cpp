#include <iostream>
#include <vector>
using namespace std;
//find the smallest which bigger than x, with the same number of 1 in x
int count_one(int x){
    int cnt = 0;
    for(int i = 0;i < 32;i++){
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}
//each two statistic the one numbers,and then four, then eight...
int count_one_bit(int x){
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}
int next(int x){
    int max_int = ~(1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;// all is 0, or all is 1
    for(++x; count_one(x) != num && x < max_int;++x);
    if(count_one(x) == num) return x;
    return -1;
}
int previous(int x){
    int min_int = (1<<31);
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(--x; count_one(x) != num && x > min_int;--x);
    if(count_one(x) == num) return x;
    return -1;
}
//find the 
int next1(int x){
    int xx = x, bit = 0;
    for(; (x & 1) != 1 && bit < 32; x >>= 1, ++bit);
    for(; (x & 1) != 0 && bit < 32; x >>= 1, ++bit);
    if(bit == 31) return -1;//0111..., none satisfy
    x |= 1;
    x <<= bit;
    if(bit == 32) x = 0;//for 111000...000
    int num1 = count_one_bit(xx) - count_one_bit(x);
    int c = 1;
    for(; num1 > 0; x |= c, --num1, c <<= 1);
    return x;
}
int previous1(int x){
    int xx = x, bit = 0;
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    if(bit == 31) return -1; //100..11, none satisify
    x -= 1;
    x <<= bit;
    if(bit == 32) x = 0;
    int num1 = count_one(xx) - count_one(x);
    x >>= bit;
    for(; num1 > 0; x = (x<<1) | 1, --num1, --bit);
    for(; bit > 0; x <<= 1, --bit);
    return x;
}
int main(){
    int x = 32;
    cout<<next(x)<<endl;
    cout<<previous(x)<<endl;
    return 0;
}