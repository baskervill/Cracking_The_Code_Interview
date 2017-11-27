# Chapter 1 Arrays and Strings

## 1.swap()

```c
void swap(){
    int a, b;
  	a = a ^ b;
  	b = a ^ b;
  	a = a ^ b;
}
```

## 2. 尾插法

```c
node* init(int a[], int n){
    node *q, *p, *head = NULL;
  	for(int i = 0;i < n;i++){
   		*p = new node();
  		p->data = a[i];  
      	if(i == 0){
            head = q = p;
          	continue;
        }
      	q->next = p;
      	q = p;
    }
  	return head;
}
```

## 3. notes

- strlen(str) 的长度不包括 '\0'
- 1 int 四字节32位

