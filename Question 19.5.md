## 题目

原文：

The Game of Master Mind is played as follows:

The computer has four slots containing balls that are red (R ), yellow (Y), green (G) or blue (B). For example, the computer might have RGGB (e.g., Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue).

You, the user, are trying to guess the solution. You might, for example, guess YRGB.When you guess the correct color for the correct slot, you get a “hit”. If you guess a color that exists but is in the wrong slot, you get a “pseudo-hit”. For example, the guess YRGB has 2 hits and one pseudo hit.

For each guess, you are told the number of hits and pseudo-hits. Write a method that, given a guess and a solution, returns the number of hits and pseudo hits.

译文：

Master Mind游戏规则如下：

4个槽，里面放4个球，球的颜色有4种，红(R )，黄(Y)，绿(G)，蓝(B)。比如， 给出一个排列RGGB，表示第一个槽放红色球，第二和第三个槽放绿色球，第四个槽放蓝色球。

你要去猜这个排列。比如你可能猜排列是：YRGB。当你猜的颜色是正确的，位置也是正确的， 你就得到一个hit，比如上面第3和第4个槽猜的和真实排列一样(都是GB)，所以得到2个hit。 如果你猜的颜色在真实排列中是存在的，但位置没猜对，你就得到一个pseudo-hit。比如， 上面的R，猜对了颜色，但位置没对，得到一个pseudo-hit。

对于你的每次猜测，你会得到两个数：hits和pseudo-hits。写一个函数， 输入一个真实排列和一个猜测，返回hits和pseudo-hits。

## 解答

这个问题十分直观，但有一个地方需要去向面试官明确一下题意。关于pseudo-hits的定义， 猜对颜色但位置没对，得到一个pseudo-hit，这里是否可以包含重复？举个例子， 比如真实排列是：RYGB，猜测是：YRRR。那么hits很明显为0了。pseudo-hits呢？ 猜测中Y对应真实排列中的Y，得到一个pseudo-hits。猜测中有3个R， 而真实排列中只有一个，那这里应该认为得到1个pseudo-hits还是3个？ CTCI书认为是3个，想必理由是猜测中的3个R都满足：出现在真实排列中，位置不正确。 所以算3个。但我认为，这里算1个比较合理，真实排列中的R只和猜测中的一个R配对， 剩余的没有配对，不算。弄清题意后，代码就不难写出了。

以下是两种不同理解的实现：

```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct Result{
    int hits;
    int pseudo_hits;
};

Result Estimate(const char* solution, const char* guess){
    Result res;
    res.hits = 0;
    res.pseudo_hits = 0;
    int solution_mask = 0;
    for(int i=0; i<4; ++i){
        solution_mask |= 1 << (solution[i] - 'A');
    }
    for(int i=0; i<4; ++i){
        if(guess[i] == solution[i])
            ++res.hits;
        else if(solution_mask & ( 1<<(guess[i] - 'A')))
            ++res.pseudo_hits;
    }
    return res;
}

int Min(int a, int b){
    return a < b ? a : b;
}
Result Estimate1(const char* solution, const char* guess){
    Result res;
    res.hits = 0;
    res.pseudo_hits = 0;
    int num = 26 + 5;
    int guess_count[num], solution_count[num];
    memset(guess_count, 0, sizeof(guess_count));
    memset(solution_count, 0, sizeof(solution_count));
    for(int i=0; i<4; ++i){
        if(guess[i] == solution[i])
            ++res.hits;
        ++guess_count[(int)(guess[i]-'A')];
        ++solution_count[(int)(solution[i]-'A')];
    }
    char color[] = "RGBY";
    for(int i=0; i<4; ++i){
        int idx = (int)(color[i] - 'A');
        res.pseudo_hits += Min(guess_count[idx], solution_count[idx]);
    }
    res.pseudo_hits -= res.hits;
    return res;
}
int main(){
    char solution[] = "RYGB";
    char guess[] = "YRRR";
    Result res = Estimate(solution, guess);
    cout<<res.hits<<" "<<res.pseudo_hits<<endl;
    Result res1 = Estimate1(solution, guess);
    cout<<res1.hits<<" "<<res1.pseudo_hits<<endl;
    return 0;
}

```