## 题目

原文：

Write a program to find whether a machine is big endian or little endian.

译文：

写一个程序判断一台机器是大端序还是小端序。

## 解答

关于什么是大端序和小端序，可参见维基百科： [字节序](http://zh.wikipedia.org/wiki/%E5%AD%97%E8%8A%82%E5%BA%8F)

判断程序如下：

```cpp
#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1
int TestByteOrder(){
	short int word = 0x0001;
	char *byte = (char *) &word;
	return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

```

