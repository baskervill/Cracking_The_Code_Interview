#include <iostream>
using namespace std;
enum Check{
    Row, Column, Diagonal, Rediagonal
};
int CheckRowColunm(int board[], int n, Check check){
    int type = 0;
    for(int i = 0;i < n;i++){
        bool found = true;
        for(int j = 0;j < n;j++){
            int k = 0;
            if(check == Row){
                k = i * n + j;
            }
            else{
                k = i + j * n;
            }
            if(j == 0){
                type = board[k];
            }
            else if(board[k] != type){
                found = false;
                break;
            }
        }
        if(found) return type;
    }
    return 0;
}
int CheckDiagonal(int board[], int n, Check check){
    int type = 0;
    bool found = true;
    for(int i = 0;i < n;i++){
        int k = 0;
        if(check == Diagonal){
            k = i + i * n;
        }
        else{
            k = i + (n - 1 - i) * n;
        }
        if(i == 0){
            type = board[k];
        }
        else if(board[k] != type){
            found = false;
            break;
        }
    }
    if(found) return type;
    return 0;
}
int HasWon(int board[], int n){
    int type = 0;
    type = CheckRowColunm(board, n, Row);
    if(type != 0) return type;
    type = CheckRowColunm(board, n, Column);
    if(type != 0) return type;
    type = CheckDiagonal(board, n, Diagonal);
    if(type != 0) return type;
    type = CheckDiagonal(board, n, Rediagonal);
    if(type != 0) return type;

    return 0;
}
int main(){
    int n = 3; // 3*3
    int board[] = {
        2, 2, 1,
        2, 1, 1,
        1, 2, 0,
    };
    int type = HasWon(board, n);
    if(type != 0)
        cout<<type<<" won!"<<endl;
    else
        cout<<"nobody won!"<<endl;
    return 0;
}

