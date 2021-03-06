## 题目

原文：

How would you design the data structures for a very large social network (Facebook,LinkedIn, etc)? Describe how you would design an algorithm to show the connection, or path, between two people (e.g., Me -> Bob -> Susan -> Jason -> You).

译文：

你会怎样给一个非常大型的社交网站设计数据结构（比如Facebook，LinkedIn）？ 设计一个算法来找到任意两个人之间的联系，比如：我 -> Bob -> Susan -> Jason -> 你

## 解答

方法：

首先，我们先不去考虑数据规模。先从简单的入手。

我们可以把每个人看作一个结点，如果两个人之间是朋友，则这两个结点间有一条边， 这样一来我们就可以构建出一个图。假设我们将“人”这个类设计如下：

```
class Person {
	Person[] friends;
	// Other info
}

```

如果要找到两个人之间的联系，即两个人之间间隔着哪些人。我们就从其中的一个人开始， 做广度优先搜索(BFS)。（做双向的BFS会更快）

但是。。。数据规模太大了！

如果我们去处理Orkut或是Facebook上的数据，单台机器根本无法完成这个任务。 因此，我们考虑用多台机器来处理这个问题。这样一来，Person这个类就需要修改了。 在Person类中，我们存储朋友的ID，然后按照以下方式找到朋友：

```
对于每个朋友id：int machine_index = lookupMachineForUserID(id);
转到标号为machine_index的机器去
Person friend = lookupFriend(machine_index);

```

对于这个问题，要考虑的优化和问题非常多，这里只列出一些。

**优化：减少机器间的跳转次数**

机器间的跳转是非常耗时的，因此我们不随机的跳转，而是进行批处理： 比如一个人，他其中的5个朋友在同一台机器上，那么跳转到那台机器后，一次性处理他们。

**聪明地划分人与机器**

由于同一国家的人更有可能是朋友，因此我们并不随机地把人分配到不同的机器上， 而是以国家，城市，州等进行划分。这样也可以减少机器间的跳转次数。

**问题：广度优先搜索会标记已访问结点，对于这个问题，你怎么处理？**

在这个问题中，有可能同时有许多人在搜索两人间的联系， 因此直接在原数据上做修改并不好。那怎么办呢？我们可以对每一个搜索， 使用一个哈希表来记录一个结点是否已经访问过。这样一来， 不同人的搜索之间就不会互相干扰。

**其它问题**

1. 在真实的世界中，服务器有可能会出故障。你会怎么做？
2. 你怎么利用缓存？
3. 你是否一直搜索直到把图上的结点都遍历一次。如何决定什么时间停止搜索。
4. 在真实世界中，你的朋友里，有一些人的朋友会更多。 那么通过他是否更有可能让你找到与特定某个人的联系。 你怎么利用这个数据来选择遍历的顺序。

下面是算法的示例代码：（java的，就不写成C++了）

```java
public class Server {	
    ArrayList<Machine> machines = new ArrayList<Machine>();
}
public class Machine {
    public ArrayList<Person> persons = new ArrayList<Person>();
    public int machineID;
}

public class Person {	
    private ArrayList<Integer> friends;
    private int ID;
    private int machineID;
    private String info;
    private Server server = new Server();
	
    public String getInfo() { return info; }
	
    public void setInfo(String info) {
        this.info = info;
    }
	
    public int[] getFriends() {
        int[] temp = new int[friends.size()];
        for (int i = 0; i < temp.length; i++) {
            temp[i] = friends.get(i);
        }
        return temp;
    }
	
	
	
    public int getID() { return ID; }
    public int getMachineID() { return machineID; }
    public void addFriend(int id) { friends.add(id); }
	
	
    // Look up a person given their ID and Machine ID
	
    public Person lookUpFriend(int machineID, int ID) {
        for (Machine m : server.machines) {
            if (m.machineID == machineID) {
                for (Person p : m.persons) {
                    if (p.ID == ID){
                        return p;						
                    }
                }
            }
        }
        return null;
    }
	
	
    // Look up a machine given the machine ID
	
    public Machine lookUpMachine(int machineID) {
        for (Machine m:server.machines) {
            if (m.machineID == machineID)
                return m;
        }
        return null;
    }
	
	
    public Person(int iD, int machineID) {
        ID = iD;
        this.machineID = machineID;
    }
}

```