## 题目

原文：

Describe how you could use a single array to implement three stacks.

译文：

你如何只用一个数组实现三个栈？

## 解答

我们可以很容易地用一个数组来实现一个栈，压栈就往数组里插入值，栈顶指针加1； 出栈就直接将栈顶指针减1；取栈顶值就把栈顶指针指向的单元的值返回； 判断是否为空就直接看栈顶指针是否为-1。

如果要在一个数组里实现3个栈，可以将该数组分为3个部分。如果我们并不知道哪个栈将装 入更多的数据，就直接将这个数组平均分为3个部分，每个部分维护一个栈顶指针， 根据具体是对哪个栈进行操作，用栈顶指针去加上相应的偏移量即可。

代码如下：

```cpp
class stack3{
public:
	stack3(int size = 300){
		buf = new int[size*3];
		ptop[0]=ptop[1]=ptop[2]=-1;
		this->size = size;
	}
	~stack3(){
		delete[] buf;
	}
	void push(int stackNum, int val){
		int idx = stackNum*size + ptop[stackNum] + 1;
		buf[idx] = val;
		++ptop[stackNum];
	}
	void pop(int stackNum){
		--ptop[stackNum];
	}
	int top(int stackNum){
		int idx = stackNum*size + ptop[stackNum];
		return buf[idx];
	}
	bool empty(int stackNum){
		return ptop[stackNum]==-1;
	}

private:
	int *buf;
	int ptop[3];
	int size;
};

```

当然，我们也可以有第二种方案。数组不分段，无论是哪个栈入栈，都依次地往这个数组里 存放。这样一来，我们除了维护每个栈的栈顶指针外，我们还需要维护每个栈中， 每个元素指向前一个元素的指针。这样一来，某个栈栈顶元素出栈后，它就能正确地找到下 一个栈顶元素。

所以，数组里存放的不再是基本数据类型的数据，我们需要先定义一个结点结构：

```
typedef struct node{
	int val,preIdx;
}node;

```

数组中的每个元素将是这样一个结点，它保存当前位置的值，和指向上一个结点的索引。

具体代码如下：

```cpp
class stack3_1{
public:
	stack3_1(int totalSize = 900){
		buf = new node[totalSize];
		ptop[0]=ptop[1]=ptop[2]=-1;
		this->totalSize = totalSize;
		cur = 0;
	}
	~stack3_1(){
		delete[] buf;
	}
	void push(int stackNum, int val){
		buf[cur].val = val;
		buf[cur].preIdx = ptop[stackNum];
		ptop[stackNum] = cur;
		++cur;
	}
	void pop(int stackNum){
		ptop[stackNum] = buf[ptop[stackNum]].preIdx;
	}
	int top(int stackNum){
		return buf[ptop[stackNum]].val;
	}
	bool empty(int stackNum){
		return ptop[stackNum]==-1;
	}

private:
	node *buf;
	int ptop[3];
	int totalSize;
	int cur;
};

```

这种实现有一个缺点，在频繁地入栈出栈后，会造成数组空间的大量浪费。 因为当前指针cur是一直递增的，而堆栈在出栈后相应位置的空间将不会再被利用到。 代码中pop函数，只是修改了栈顶指针。如果我们对一个栈先执行出栈，再入栈， 那么再次入栈的位置是在cur，而不是原来栈顶的位置。

有没有避免这种空间浪费的方法呢？当然是有的。不过这样一来，对cur的操作就变得复杂 了。第一，每次执行pop操作，检查该元素对应索引是否小于cur，如果是， 将cur更新到该元素索引；否则cur不变。第二，每次执行完push操作， cur要沿着数组依次向后查找，直到找到第一个空的空间，用它的索引更新cur。 这部分代码实现起来也是没什么难度的，这里不再贴出。

以下是完整代码：

```cpp
#include <iostream>
using namespace std;

class stack3{
public:
	stack3(int size = 300){
		buf = new int[size*3];
		ptop[0]=ptop[1]=ptop[2]=-1;
		this->size = size;
	}
	~stack3(){
		delete[] buf;
	}
	void push(int stackNum, int val){
		int idx = stackNum*size + ptop[stackNum] + 1;
		buf[idx] = val;
		++ptop[stackNum];
	}
	void pop(int stackNum){
		--ptop[stackNum];
	}
	int top(int stackNum){
		int idx = stackNum*size + ptop[stackNum];
		return buf[idx];
	}
	bool empty(int stackNum){
		return ptop[stackNum]==-1;
	}

private:
	int *buf;
	int ptop[3];
	int size;
};

typedef struct node{
	int val,preIdx;
}node;

class stack3_1{
public:
	stack3_1(int totalSize = 900){
		buf = new node[totalSize];
		ptop[0]=ptop[1]=ptop[2]=-1;
		this->totalSize = totalSize;
		cur = 0;
	}
	~stack3_1(){
		delete[] buf;
	}
	void push(int stackNum, int val){
		buf[cur].val = val;
		buf[cur].preIdx = ptop[stackNum];
		ptop[stackNum] = cur;
		++cur;
	}
	void pop(int stackNum){
		ptop[stackNum] = buf[ptop[stackNum]].preIdx;
	}
	int top(int stackNum){
		return buf[ptop[stackNum]].val;
	}
	bool empty(int stackNum){
		return ptop[stackNum]==-1;
	}

private:
	node *buf;
	int ptop[3];
	int totalSize;
	int cur;
};

int main(){
	stack3_1 mystack;//stack3 mystack;
	for(int i=0; i<10; ++i)
		mystack.push(0, i);
	for(int i=10; i<20; ++i)
		mystack.push(1, i);
	for(int i=100; i<110; ++i)
		mystack.push(2, i);
	for(int i=0; i<3; ++i)
		cout<<mystack.top(i)<<" ";

	cout<<endl;
	for(int i=0; i<3; ++i){
		mystack.pop(i);
		cout<<mystack.top(i)<<" ";
	}
	mystack.push(0, 111);
	mystack.push(1, 222);
	mystack.push(2, 333);
	for(int i=0; i<3; ++i)
		cout<<mystack.top(i)<<" ";
	return 0;
}

```

