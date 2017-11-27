#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

class Median{
    private:
        priority_queue<int, vector<int>, less<int> > max_heap;
        priority_queue<int, vector<int>, greater<int> > min_heap;
    public:
        void insert(int v);
        int query();  
};
void Median::insert(int v){
    if(max_heap.empty() && min_heap.empty())
        max_heap.push(v);
    else if(!max_heap.empty() && min_heap.empty())
        max_heap.push(v);
    else if(max_heap.empty() && !min_heap.empty())
        min_heap.push(v);
    else{
        if(v < max_heap.top())
            max_heap.push(v);
        else
            min_heap.push(v);
    }
    //调整，保证两个堆的元素数量差别不大于1
    //不要用max_heap.size()-min_heap.size()>1
    //因为size返回的是unsigned类型，当左边相减得到一个负数时，本来为false
    //但会被转为一个大的正数，结果为true，出问题
    while(max_heap.size() > min_heap.size()+1){
        int data = max_heap.top();
        min_heap.push(data);
        max_heap.pop();
    }
    while(min_heap.size() > max_heap.size()+1){
        int data = min_heap.top();
        max_heap.push(data);
        min_heap.pop();
    }

}
int Median::query(){
    if(min_heap.size() == max_heap.size())
        return (min_heap.top() + max_heap.top()) / 2;
    else if(min_heap.size() < max_heap.size())
        return max_heap.top();
    else return min_heap.top();
}
int main(){
    srand((unsigned) time(0));
    Median md;
    vector<int> vi;
    int num = rand() % 30;
    for(int i = 0;i < num;i++){
        int data = rand() % 100;
        vi.push_back(data);
        md.insert(data);
    }
    sort(vi.begin(),vi.end());
    for(int i = 0;i < num;i++){
        cout<<vi.at(i)<<" ";
    }
    cout<<endl<<md.query()<<endl;
    return 0;
}
