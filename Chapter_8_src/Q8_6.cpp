#include<queue>
using namespace std;
enum color{
    red, yellow, blue, green
};
//m and n is the border
bool paint_fill(color **screen, int m, int n, int x, int y, color c){
    if(x < 0 || x > m || y < 0 || y > n) return false;
    if(screen[x][y] == c) return false;
    else{
        screen[x][y] = c;
        paint_fill(screen, m, n, x - 1, y, c);
        paint_fill(screen, m, n, x + 1, y, c);
        paint_fill(screen, m, n, x, y - 1, c);
        paint_fill(screen, m, n, x, y + 1, c);
    }
    return true;
}
/*
typedef pair<int, int> pii;
queue<pii> q;
void bfs(color **screen, int m , int n, color c){
    int x, y;//seed
    if(x < 0 || y < 0 || x > m || y > n) return;
    q.push(x, y);
    while(!q.empty()){
        q.pop();
        x = q.top().first;
        y = q.top().second;
        if(screen[x][y] != c){
            screen[x][y] = c;
            q.push_back(make_pair(x - 1, y));
            q.push_back(x + 1, y);
            q.push_back(x, y - 1);
            q.push_back(x, y + 1);  
        }
    }
}
*/
int main(){
    freopen("8.6.in", "r", stdin);
    int m, n;
    cin>>m>>n;
    color **screen = new color*[m];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            int t;
            cin>>t;
            screen[i][j] = (color)t;
        }
    }
    paint_fill(screen, 5, 5, 1, 2, green);
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }
    fclose(stdin);
    return 0;
}