## 题目

原文：

What are the different types of joins? Please explain how they differ and why certain types are better in certain situations.

译文：

SQL的连接有哪些不同的类型？解释它们的不同点及在什么情况下用哪种连接，为什么？

## 解答

连接(JOIN)将数据库中的两个或多个表组合起来。为了使用连接， 每个表至少要包含一个相同的字段(属性)。不同的连接类型决定了哪些记录会出现在结果集。

假设我们有以下两张表：

![img](http://www.hawstein.com/assets/img/2013/2/15/regular.png) ![img](http://www.hawstein.com/assets/img/2013/2/15/caloriefree.png)

一张表列的是常规饮料，另一张表列的是无热量饮料。每张表有两个字段： 饮料名和产品代码。产品代码字段将用于连接时进行匹配。为了简化， 我们用RB代表常规饮料表，CFB代表无热量饮料表。

**1. 内连接(INNER JOIN)：**结果只包含两个表中严格匹配的记录。 本例中只返回3条记录，1条COCACOLA的和2条PEPSI的。SQL语句如下：

```
SELECT * from RB INNER JOIN CFB ON RB.Code = CFB.Code

```

**2. 外连接(OUTER JOIN)：**外连接一定包含内连接的结果，但同时还包含一些别的记录。 外连接可分为以下类型：

**2.1 左外连接(LEFT OUTER JOIN)：**简称左连接(LEFT JOIN)， 结果包含左边的表中所有记录，对于与右表没有匹配的记录，来自右表的所有列设为NULL， 本例中会返回4条记录，除了内连接的3个结果，BUDWEISER也会被列出来。SQL语句如下：

```
SELECT * from RB LEFT OUTER JOIN CFB ON RB.Code = CFB.Code

```

**2.2 右外连接(RIGHT OUTER JOIN)**简称右连接(RIGHT JOIN)， 右连接与左连接相反，结果将包含右表中的所有记录。右连接很少使用， 因为它总是可以被替换成左连接，只需要交换两表的位置即可。本例中， 右连接会得到5条记录，除了内连接的3条，FRESCA和WATER也会被列出来。SQL语句如下：

```
SELECT * from RB RIGHT OUTER JOIN CFB ON RB.Code = CFB.Code

```

**2.3 全连接(FULL OUTER JOIN)**全连接是左右连接的并集， 结果集中包含被连接表的所有记录，如果缺少匹配的记录，即以NULL填充。本例子中， 全连接会得到6条记录。SQL语句如下：

```
SELECT * from RB FULL OUTER JOIN CFB ON RB.Code = CFB.Code

```

关于连接，维基百科讲得非常好，看它就OK了： [连接(SQL)](http://zh.wikipedia.org/zh/%E8%BF%9E%E6%8E%A5_(SQL/))