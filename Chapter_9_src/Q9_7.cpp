#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct person{
    int height, weight;
    person(int h, int w):height(h), weight(w){}
};
bool cmp(person p1, person p2){
    if(p1.height == p2.height) return p1.weight < p2.weight;
    else return p1.height < p2.height;
}
//O(n^2) for LIS
int LIS(vector<int> &list){
    int t = list.size();
    int d[t];
    int len = 1;
    //d(i) = max{1, d(j) + 1} when A[i] >= A[j] and j <= i
    for(int i = 0;i < t;i++){
        d[i] = 1;
        for(int j = 0;j < i;j++){
            if(list[i] >= list[j] && d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
            }
        }
        if(len < d[i])
            len = d[i];
    }
    return len;
}
//O(nlogn) for LIS use bisearch
int LIS1(vector<int> &list){
    int n = list.size();
    int k = 1;
    int *d = new int[n];
    d[0] = list[0];
    for(int i = 1;i < n;i++){
        if(list[i] >= d[k - 1]) d[k++] = list[i];
        else{
            int j ;
            for(j = k - 1;j >= 0 && d[j] > list[i];j--)
                d[j + 1] = list[i];
        }
    }
    return k;
}
int count(vector<person> &vp){
    sort(vp.begin(), vp.end(), cmp);
    vector<int> weights;
    for(int i = 0;i < vp.size();i++){
        weights.push_back(vp[i].weight);
    }
    int n = LIS1(weights);
    return n;

}


int main(){
    freopen("9.7.in", "r", stdin);
    int n;
    cin>>n;
    vector<person> vp;
    for(int i = 0;i < n;i++){
        int h, w;
        cin>>h>>w;
        vp.push_back(person(h, w));
    }
    int res = count(vp);
    cout<<res<<endl;
    return 0;


}