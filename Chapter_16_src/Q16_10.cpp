int **my2Dmalloc(int rows, int cols){
    int **arr = (int **)malloc(rows * sizeof(int *));
    for(int i = 0;i < rows;i++){
        arr[i] = (int *)malloc(cols * sizeof(int ));
    }
    return arr;
}
int **my2Dmalloc1(int rows, int cols){
    int head = rows * sizeof(int *);
    int body = rows * cols * sizeof(int)
    int **arr = (int **)malloc(head + body);
    int *buf = (int *)(arr + rows);
    for(int i = 0;i < rows;i++){
        arr[i] = buf + i * cols;
    }
    return arr;
}