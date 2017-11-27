# Chapter 2 Linked Lists

## 1. 链表节点定义

```cpp
typedef struct node{
  int data;
  node* next;
}node;
```

## 2. 链表初始化（尾插法）

```cpp
void init(int a[], int n){
  node *head, *p;
  for(int i = 0;i < n;i++){
    node *nd = new node();
    nd->data = a[i];
    if(i == 0){
      head = p = nd;
      continue;
    }
    p->next = nd;
    p = nd;
  }
  return head;
}
```

## 3. 链表节点删除(需要两个指针才能删除)

```
node *p, *q;
node *t = q;
p->next = q->next;
q = p->next;
delete t;
```

## 4. 注意尾节点的处理

直接delete尾节点会出现意外的结果，需要特殊处理