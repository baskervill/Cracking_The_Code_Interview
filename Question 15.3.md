## 题目

原文：

Draw an entity-relationship diagram for a database with companies, people, and professionals (people who work for companies).

译文：

画出一个数据库的实体关系图(ER图)，其中的实体有公司(companies)，人(people)， 专业人士(professionals)。

## 解答

在公司中工作的人(people)是专业人士(professionals)，因此， professionals和people间是ISA(is a)的关系。 或者，我们可以说professionals是从people派生出来的。

除了people的属性，每个professional还有自己额外的属性，如：级别，工作经验等。

一个professional只能去一家公司上班(一般情况下是这样)， 而一家公司可以雇佣很多的professional。因此，它们之间是多对一的关系。 “工作(work for)”关系可以有如下属性：加入公司的时间，工资等。 为什么这两个属性是关系的属性而不是professional的属性呢？ 因为只有当我们将professional和companies联系起来，才会有这些属性， 或是说这些属性才有意义。

一个人可以有多个电话号码，因此电话号码是一个多值属性。

ER图如下：

![img](http://www.hawstein.com/assets/img/2013/2/16/ER.png)

