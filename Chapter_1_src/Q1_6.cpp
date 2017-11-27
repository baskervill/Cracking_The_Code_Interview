#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
//clockwise 90 degree is as fold twice 
void transpose(vector<vector<int> > &a){
    int n = a.size();
    for(int i = 0;i < n / 2;i++){
        for(int j = 0;j < n;j++){
            swap(a[i][j], a[n - i - 1][j]);
        }
    }
    for(int i = 0;i < n ;i++){
        for(int j = i + 1;j < n;j++){
            swap(a[i][j], a[j][i]);
        }
    }
}
int main(){
    vector<vector<int> > a(4);
    for(int i = 0;i < 4;i++){
        a[i].resize(4);
    }
    int p = 1;
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[0].size();j++){
            a[i][j] = p++;
        }
    }
    transpose(a);
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[0].size();j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}


