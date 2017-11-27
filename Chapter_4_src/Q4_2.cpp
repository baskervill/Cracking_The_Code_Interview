//BFS
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100;
bool route(int src, int dst, vector<vector<int> > &g, int n){
    bool visited[maxn];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        if(dst == t) return true;
        for(int i = 0;i < n;i++){
            if(g[t][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}
bool visited1[maxn];
void dfs(int src, vector<vector<int> > g,int n){
    visited1[src] = true;
    for(int i = 0;i < n;i++){
        if(g[src][i] && !visited1[i]){
            dfs(i, g, n);
        }
    }
}
int main(){
    vector<vector<int> > g(4);
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            g[i].push_back(i);
        }
    }
    g[1][2] = g[2][1] = 0;
    g[2][3] = g[3][2] = 0;
    g[0][3] = g[3][0] = 0;
    //bool flag = route(2,3 , g, 4);
    dfs(2,g,4);
    cout<<visited1[0]<<endl;
}