## 题目

原文：

You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).

EXAMPLE:

Input: N = 10000000000, M = 10101, i = 2, j = 6

Output: N = 10001010100

译文：

给定两个32位的数，N和M，还有两个指示位的数，i和j。 写程序使得N中第i位到第j位的值与M中的相同(即：M变成N的子串且位于N的第i位和第j位之间)

例子：

输入: N = 10000000000, M = 10101, i = 2, j = 6

输出: N = 10001010100

## 解答

方案1：先将N中第0位到第i位保存下来(左闭右开：[0, i))，记作ret， 然后将N中第0位到第j位全清0([0, j])，通过向右移动j+1位然后再向左移动j+1位得到。 最后用上面清0后的值或上(m«i)再或上ret即可。

代码如下：

```cpp
int update_bits(int n, int m, int i, int j){
    int ret = (1 << i) -1;
    ret &= n;
    return ((n>>(j+1)) << (j+1)) | (m<<i) | ret;
}

```

方案2：用一个左边全为1，中间一段全为0(这段的长度与m长度一样)， 右边全为1的掩码mask去和n按位与，得到的值是将n中间一段清0的结果。 然后再与m左移i位后按位或，得到最终结果。

代码如下：

```cpp
int update_bits1(int n, int m, int i, int j){
    int max = ~0;	//全为1
    int left = max - ((1 << j+1) - 1);
    int right = ((1 << i) -1);
    int mask = left | right;
    return (n & mask) | (m << i);
}

```

C++中关于位操作，记录几点需要注意的地方：

- 一个有符号数，如果它的最高位为1，它右移若干位后到达位置i， 那么最高位到第i位之间全是1，例如：

```
int a = 1;
a <<= 31;	//a:1后面带31个0
a >>= 31;	//a:32个1，即-1
cout<<a<<endl;	//输出-1(写下负号，然后取反加1)

```

- 一个无符号数，如果它的最高位为1，它右移若干位后到达位置i， 那么最高位到第i位之间全是0，例如：

```
unsigned int a = 1;
a <<= 31;	//a:1后面带31个0
a >>= 31;	//a:31个0后面带一个1，即1
cout<<a<<endl;	//输出1

```

- 无论是有符号数还是无符号数，左移若干位后，原来最低位右边新出现的位全为0
- 一个有符号的正数，它的最高位为0，如果因为左移使得最高位为1，那么它变为负数， 而后无论怎样右移，它都还是负数。除非因为再次左移使最高位变为0，那么它变回正数。
- int的最大值：~(1«31)，即0后面跟31个1
- int的最小值：1«31，即1后面跟31个0
- unsigned int最大值：~0，即32个1
- unsigned int最小值：0
- 其它数据类型与int类似，只是位长不一样。

完整代码如下：

```cpp
#include <iostream>
#include <vector>
using namespace std;

void print_binary(int n){
    vector<int> v;
    int len = 8 * sizeof(int);
    int mask = 1;
    while(len--){
        if(n&mask) v.push_back(1);
        else v.push_back(0);
        mask <<= 1;
    }
    while(!v.empty()){
        cout<<v.back();
        v.pop_back();
    }
    cout<<endl;
}
int update_bits(int n, int m, int i, int j){
    int ret = (1 << i) -1;
    ret &= n;
    return ((n>>(j+1)) << (j+1)) | (m<<i) | ret;
}
int update_bits1(int n, int m, int i, int j){
    int max = ~0;
    int left = max - ((1 << j+1) - 1);
    int right = ((1 << i) -1);
    int mask = left | right;
    return (n & mask) | (m << i);
}
int main(){
    int n = 1<<10, m = 21;
    int ans = update_bits(n, m, 2, 6);
    print_binary(n);
    print_binary(m);
    print_binary(ans);
    return 0;
}
```