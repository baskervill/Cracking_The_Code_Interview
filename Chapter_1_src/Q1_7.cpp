#include <iostream>
#include <vector>
using namespace std;
void zero(vector<vector<int> > &a){
    int m = a.size();
    int n = a[0].size();
    bool row[m];
    bool col[n];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(a[i][j] == 0){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(row[i] == true || col[j] == true){
                a[i][j] = 0;
            }
        }
    }

}
//if you need a O(1) space and a O(m * n) time , you need to reuse the first row and the first col
//the full implement is in leetcode-cpp.pdf
int main(){
    vector<vector<int> > a(4);
    for(int i = 0;i < 4;i++){
        a[i].resize(4);
    }
    int p = 0;
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[0].size();j++){
            a[i][j] = p++;
        }
    }
    zero(a);
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a[0].size();j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;

}