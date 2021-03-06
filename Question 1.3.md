## 题目

原文：

Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.

FOLLOW UP

Write the test cases for this method.

译文：

设计算法并写出代码移除字符串中重复的字符，不能使用额外的缓存空间。注意： 可以使用额外的一个或两个变量，但不允许额外再开一个数组拷贝。

进一步地，

为你的程序写测试用例。

## 解答

这道题目其实是要你就地(in place)将字符串中重复字符移除。你可以向面试官问清楚， 不能使用额外的一份数组拷贝是指根本就不允许开一个数组，还是说可以开一个固定大小， 与问题规模(即字符串长度)无关的数组。

如果根本就不允许你再开一个数组，只能用额外的一到两个变量。那么，你可以依次访问 这个数组的每个元素，每访问一个，就将该元素到字符串结尾的元素中相同的元素去掉( 比如置为’\0’).时间复杂度为O(n^2 )，代码如下：

```c
void removeDuplicate(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int p = 0;
    for(int i=0; i < len; ++i)
    {
        if(s[i] != '\0')
        {
            s[p++] = s[i];
            for(int j=i+1; j < len; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
        }
    }
    s[p] = '\0';
}

```

如	果可以开一个固定大小，与问题规模(即字符串长度)无关的数组，那么可以用一个数组来 表征每个字符的出现(假设是ASCII字符，则数组大小为256)，这样的话只需要遍历一遍字符 串即可，时间复杂度O(n)。代码如下：

```cpp
void removeDuplicate(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;
    for(int i=0; i < len; ++i)
    {
        if(!c[s[i]])
        {
            s[p++] = s[i];
            c[s[i]] = true;
        }
    }
    s[p] = '\0';    
}

```

如果字符集更小一些，比如只是a-z，即字符串里只包含小写字母，那么使用一个int变量中 的每一位来表征每个字符的出现，一样可以在O(n)的时间里移除重复字符，而且还不需要额 外开一个数组。代码如下：

```cpp
void removeDuplicate(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int check = 0, p = 0;
    for(int i=0; i < len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1 << v))==0)
        {
            s[p++] = s[i];
            check |= (1 << v);
        }
    }
    s[p] = '\0';
}

```

测试用例：

1. 不包含重复字符的字符串，比如：abcd
2. 字符串全是重复字符，比如：aaaa
3. 空字符串
4. 重复字符连续出现，比如：aaabbb
5. 重复字符不连续出现，比如：abababa

完整代码如下：

```
#include <iostream>
#include <cstring>
using namespace std;

string removeDuplicate1(string s)
{
    int check = 0;
    int len = s.length();
    if(len < 2) return s;
    string str = "";
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v)) == 0)
        {
            str += s[i];
            check |= (1<<v);
        }
    }
    return str;
}

string removeDuplicate2(string s)
{
    int len = s.length();
    if(len < 2) return s;
    string str = "";
    for(int i=0; i<len; ++i)
    {
        if(s[i] != '\0')
        {
            str += s[i];
            for(int j=i+1; j<len; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
        }
    }
    return str;
}

void removeDuplicate3(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(s[i] != '\0')
        {
            s[p++] = s[i];
            for(int j=i+1; j<len; ++j)
                if(s[j]==s[i])
                    s[j] = '\0';
        }
    }
    s[p] = '\0';
}

void removeDuplicate4(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    bool c[256];
    memset(c, 0, sizeof(c));
    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(!c[s[i]])
        {
            s[p++] = s[i];
            c[s[i]] = true;
        }
    }
    s[p] = '\0';    
}

void removeDuplicate5(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int check = 0, p = 0;
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v))==0)
        {
            s[p++] = s[i];
            check |= (1<<v);
        }
    }
    s[p] = '\0';
}
int main()
{
    string s1 = "abcde";
    string s2 = "aaabbb";
    string s3 = "";
    string s4 = "abababc";
    string s5 = "ccccc";
    cout<<removeDuplicate1(s1)<<" "<<removeDuplicate2(s1)<<endl;
    cout<<removeDuplicate1(s2)<<" "<<removeDuplicate2(s2)<<endl;
    cout<<removeDuplicate1(s3)<<" "<<removeDuplicate2(s3)<<endl;
    cout<<removeDuplicate1(s4)<<" "<<removeDuplicate2(s4)<<endl;
    cout<<removeDuplicate1(s5)<<" "<<removeDuplicate2(s5)<<endl;
    char ss1[] = "abcde";
    char ss2[] = "aaabbb";
    char ss3[] = "";
    char ss4[] = "abababc";
    char ss5[] = "ccccc";
    removeDuplicate5(ss1);
    removeDuplicate5(ss2);
    removeDuplicate5(ss3);
    removeDuplicate5(ss4);
    removeDuplicate5(ss5);
    cout<<ss1<<" "<<ss2<<" "<<ss3<<" "<<ss4<<" "<<ss5<<endl;
    return 0;
}

```