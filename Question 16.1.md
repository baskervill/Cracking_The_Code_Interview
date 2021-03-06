## 题目

原文：

Explain the following terms: virtual memory, page fault, thrashing.

译文：

解释下列术语：虚拟内存，缺页中断，抖动。

## 解答

**虚拟内存**是计算机系统内存管理的一种技术。它使得应用程序认为它拥有连续的可用的内存 （一个连续完整的地址空间），而实际上，它通常是被分隔成多个物理内存碎片， 还有部分暂时存储在外部磁盘存储器上，在需要时进行数据交换。 与没有使用虚拟内存技术的系统相比，使用这种技术的系统使得大型程序的编写变得更容易， 对真正的物理内存（例如RAM）的使用也更有效率。

<http://zh.wikipedia.org/wiki/%E8%99%9A%E6%8B%9F%E5%86%85%E5%AD%98>

**缺页中断**一个页(Page)是一个固定容量的内存区块，是物理内存和外部存储(如硬盘等) 传输的单位。当一个程序访问一个映射到地址空间却实际并未加载到物理内存的页（page）时， 硬件向软件发出的一次中断（或异常）就是一个缺页中断或叫页错误（page fault）。

<http://zh.wikipedia.org/wiki/%E9%A1%B5%E7%BC%BA%E5%A4%B1_(%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%A7%91%E5%AD%A6)>

**抖动**在分页存储管理系统中，内存中只存放了那些经常使用的页面， 而其它页面则存放在外存中，当进程运行需要的内容不在内存时， 便启动磁盘读操作将所需内容调入内存，若内存中没有空闲物理块， 还需要将内存中的某页面置换出去。也就是说，系统需要不断地在内外存之间交换信息。 若在系统运行过程中，刚被淘汰出内存的页面，过后不久又要访问它， 需要再次将其调入。而该页面调入内存后不久又再次被淘汰出内存，然后又要访问它。 如此反复，使得系统把大部分时间用在了页面的调入/换出上， 而几乎不能完成任何有效的工作，这种现象称为抖动。

参考资料：《操作系统教程》 <http://en.wikipedia.org/wiki/Thrash_(computer_science)>