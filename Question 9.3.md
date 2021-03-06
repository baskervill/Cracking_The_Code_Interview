## 题目

原文：

Given a sorted array of n integers that has been rotated an unknown number of times, give an O(log n) algorithm that finds an element in the array. You may assume that the array was originally sorted in increasing order.

EXAMPLE:

Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)

Output: 8 (the index of 5 in the array)

译文：

一个数组有n个整数，它们排好序(假设为升序)但被旋转了未知次， 即每次把最右边的数放到最左边。给出一个O(log n)的算法找到特定的某个元素。

例子：

输入：在数组(15 16 19 20 25 1 3 4 5 7 10 14)中找出5

输出：8（5在数组中的下标）

## 解答

题目中提到了几个关键的词：有序，O(log n)。我们马上能联想到的就是二分查找算法。 但简单的二分查找肯定不行，因为这个数组被旋转了。也就是该数组前面一段有序， 后面一段有序，且前面那段的数要大于等于后面那段的数(本题考虑递增序列，递减同理)。 因此，我们需要对二分查找算法做一下修改，来解决这个具体的问题。

首先，我们来看一下函数原型：

```
int search(int a[], int low, int high, int x);

```

参数和二分查找一样，数组a，下界low，上界high及要查找的数x。当low <= high时， 我们会去求它们中间的那个数，然后与x对比，如果相同，就返回下标：

```
int mid = low + (high - low)/2;
if(a[mid] == x) return mid;

```

如果a[mid]不等于x，就要分情况讨论了。我们把旋转后的数组分为前半段和后半段， 两段分别都是有序的，且前半段的数都大于后半段的数。假如a[mid]落在前半段 (即a[mid]>=a[low])，这时如果x的值是位于a[low]和a[mid]之间， 则更新high = mid - 1；否则更新low = mid + 1。假如a[mid]落在后半段 (即a[mid]<a[low])，这时如果x的值是位于a[mid]和a[low]之间， 则更新low = mid + 1；否则更新high = mid - 1。

代码如下：

```cpp
#include <iostream>
using namespace std;

int search(int a[], int low, int high, int x){
    while(low <= high){
        int mid = low + (high - low)/2;
        if(a[mid] == x) return mid;
        if(a[mid] >= a[low]) {
            if(x<a[mid] && x>=a[low])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else {
            if(x>a[mid] && x<a[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int a[12] = {
        15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
    };
    int b[19] = {
        2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2
    };
    cout<<search(a, 0, 11, 3)<<endl;
    return 0;
}

```

对于有重复元素的数组，上面的算法失效。比如说代码中对于数组b， 它也是一个有序数组然后旋转了若干次。但是调用search函数将返回-1， 也就是查找失败。