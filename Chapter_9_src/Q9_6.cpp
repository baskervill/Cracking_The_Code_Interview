#include <iostream>
#include <vector>
using namespace std;
struct point{
    int x,y;
    point(int x, int y):x(x),y(y){}
};
int bisearch(int b[], int begin, int end, int target){
    while(begin <= end){
        int mid = (begin + end) >> 1;
        if(b[mid] == target) return mid;
        else if(b[mid] > target) begin = mid + 1;
        else end = mid - 1;
    }
    return -1;
}
//O(m + n)
int a[20][20];
point search(int m, int n, int target){
    vector<point> res;
    int s = n - 1, t = m ;
    int i = 0;
    while(s > 0 && i < t){
        if(target > a[i][s]){
            i = i + 1;
        }
        else if(target < a[i][s]){
            s = s - 1;
        }
        else{
            return point(i, s);
        }
    }
    return point(-1,-1);
}
int main(){
    freopen("9.6.in", "r", stdin);
    int m, n;
    cin>>m>>n;
    //int a[m][n];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin>>a[i][j];
        }
    }
    //vector<point> res;
    point p1(0,0);
    p1 = search(m, n, 5);
    cout<<p1.x<<" "<<p1.y<<endl;
    return 0;
}