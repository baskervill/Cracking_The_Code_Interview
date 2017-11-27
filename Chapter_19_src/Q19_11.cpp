//Two Sum
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<int> TwoSum(vector<int> &a, int target){
    int n = a.size();
    unordered_map<int, int> hash;
    vector<int> res;
    for(int i = 0;i < n;i++){
        int find = target - a[i];
        if(hash.find(find) != hash.end()){
            res.push_back(hash[find]);
            res.push_back(i);
        }
        hash[a[i]] = i;
    }
    return res;
}
//this is O(nlogn), but the space need is less,no need a hash
vector<int > TwoSum1(vector<int> &a, int target){
    if(a == NULL || a.size() < 2) return NULL;
    int low = 0;
    int high = a.size() - 1;
    //int n = a.size();
    vector<int> res;
    sort(a.begin(), a.end());
    while(low <= high){
        if(a[low] + a[high] > target){
            high--;
        }
        else if(a[low] + a[high] < target){
            low++;
        }
        else{
            res.push_back(low);
            res.push_back(high);
            low++;
            high--;
        }
    }
    return res;

}
int main(){
    int a[] = {1,2,3,4,5};
    int target = 5;
    vector<int > res;
    vector<int> b(a, a + 5);
    res = TwoSum1(b, target);
    for(vector<int>::iterator it = res.begin();it != res.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}