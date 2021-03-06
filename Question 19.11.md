## 题目

原文：

Design an algorithm to find all pairs of integers within an array which sum to a specified value.

译文：

设计一个算法，找到数组中所有和为指定值的整数对。

## 解答

**时间复杂度O(n)的解法**

我们可以用一个哈希表或数组或bitmap(后两者要求数组中的整数非负)来保存sum-x的值， 这样我们就只需要遍历数组两次即可找到和为指定值的整数对。这种方法需要O(n) 的辅助空间。如果直接用数组或是bitmap来做，辅助空间的大小与数组中的最大整数相关， 常常导致大量空间浪费。比如原数组中有5个数：1亿，2亿，3亿，4亿，5亿。sum为5亿， 那么我们将bitmap中的sum-x位置1，即第4亿位，第3亿位，第2亿位，第1亿位，第0位置1. 而其它位置都浪费了。

如果使用哈希表，虽然不会有大量空间浪费，但要考虑冲突问题。

**时间复杂度为O(nlogn)的解法**

我们来考虑一种空间复杂度为O(1)，而且实现也很简单的算法。首先，将数组排序。 比如排序后得到的数组a是：-2 -1 0 3 5 6 7 9 13 14。然后使用low和high 两个下标指向数组的首尾元素。如果a[low]+a[high] > sum，那么说明a[high] 和数组中的任何其它一个数的和都一定大于sum(因为它和最小的a[low]相加都大于sum)。 因此，a[high]不会与数组中任何一个数相加得到sum，于是我们可以直接不要它， 即让high向前移动一位。同样的，如果a[low]+a[high] < sum，那么说明a[low] 和数组中的任何其它一个数的和都一定小于sum(因为它和最大的a[high]相加都小于sum)。 因此，我们也可以直接不要它，让low向前移动一位。如果a[low]+a[high]等于sum， 则输出。当low小于high时，不断地重复上面的操作即可。

代码如下：

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

void PrintPairSum(int a[], int n, int sum){
    if(a==NULL || n<2) return;
    
    sort(a, a+n);
    int low = 0, high = n-1;
    while(low < high){
        if(a[low]+a[high] > sum)
            --high;
        else if(a[low]+a[high] < sum)
            ++low;
        else{
            cout<<a[low]<<" "<<a[high]<<endl;
            ++low; --high;
        }
            
    }
}

int main(){
    int n = 6, sum = 6;
    int a[] = {
        1, 2, 3, 4, 5, 6
    };
    PrintPairSum(a, n, sum);
    return 0;
}

```