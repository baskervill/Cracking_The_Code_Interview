## 题目

原文：

Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n-pairs of parentheses.

EXAMPLE:

input: 3 (e.g., 3 pairs of parentheses)

output: ((())), (()()), (())(), ()(()), ()()()

译文：

实现一个算法打印出n对括号的有效组合。

例如：

输入：3 （3对括号）

输出：((())), (()()), (())(), ()(()), ()()()

## 解答

对于括号的组合，要考虑其有效性。比如说，)(， 它虽然也是由一个左括号和一个右括号组成，但它就不是一个有效的括号组合。 那么，怎样的组合是有效的呢？对于一个左括号，在它右边一定要有一个右括号与之配对， 这样的才能是有效的。所以，对于一个输出，比如说(()())， 从左边起，取到任意的某个位置得到的串，左括号数量一定是大于或等于右括号的数量， 只有在这种情况下，这组输出才是有效的。我们分别记左，右括号的数量为left和right， 如下分析可看出，(()())是个有效的括号组合。

```
(, left = 1, right = 0
((, left = 2, right = 0
((), left = 2, right = 1
(()(, left = 3, right = 1
(()(), left = 3, right = 2
(()()), left = 3, right = 3

```

这样一来，在程序中，只要还有左括号，我们就加入输出串，然后递归调用。 当退出递归时，如果剩余的右括号数量比剩余的左括号数量多，我们就将右括号加入输出串。 直到最后剩余的左括号和右括号都为0时，即可打印一个输出串。代码如下：

```cpp
void print_pare(int l, int r, char str[], int cnt){
    if(l<0 || r<l) return;
    if(l==0 && r==0){
        for(int i=0; i<cnt; ++i){
            cout<<str[i];
        }
        cout<<", ";
    }
    else{
        if(l > 0){
            str[cnt] = '(';
            print_pare(l-1, r, str, cnt+1);
        }
        if(r > l){
            str[cnt] = ')';
            print_pare(l, r-1, str, cnt+1);
        }
    }
}

```

完整代码如下：

```cpp
#include <iostream>
using namespace std;

void print_pare(int l, int r, char str[], int cnt){
    if(l<0 || r<l) return;
    if(l==0 && r==0){
        for(int i=0; i<cnt; ++i){
            cout<<str[i];
        }
        cout<<", ";
    }
    else{
        if(l > 0){
            str[cnt] = '(';
            print_pare(l-1, r, str, cnt+1);
        }
        if(r > l){
            str[cnt] = ')';
            print_pare(l, r-1, str, cnt+1);
        }
    }
}
int main(){
    int cnt = 3;
    char str[2*cnt];
    print_pare(cnt, cnt, str, 0);
    return 0;
}

```