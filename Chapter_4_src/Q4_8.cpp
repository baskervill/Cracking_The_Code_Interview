#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <unordered_map>
using namespace std;
const int maxn = 100;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode *parent;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
void createMinimalTree(TreeNode* &head, TreeNode* parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        //head->val = a[mid];
        head = new TreeNode(a[mid]);
        head->parent = parent;
        createMinimalTree(head->left, head, a, start, mid - 1);
        createMinimalTree(head->right, head, a, mid + 1, end);
    }
}
//if there is a parent pointer, then every node has only one parent. Traverse,
//all the nodes, then memorized all the parents
void print(TreeNode* node, int n){
    vector<int> v;
    for(int i = 0;i <= n;i++){
        v.push_back(node->val);
        node = node->parent;
    }
    while(!v.empty()){
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}
void find_sum(TreeNode* head, int sum){
    if(head == NULL) return;
    TreeNode* node = head;
    int tmp = 0;
    for(int i = 0; node != NULL;i++){
        tmp += node->val;
        if(tmp == sum)
            print(head, i);
        node = node->parent;
    }
    find_sum(head->left, sum);
    find_sum(head->right, sum);
}
//this level represent the node's real level in the tree
void print2(vector<int> v, int level){
    for(int i = level;i < v.size();i++)
        cout<<v.at(i)<<" ";
    cout<<endl;
}
void find_sum2(TreeNode* head, int sum, vector<int> v, int level){
    if(head == NULL) return;
    int tmp = 0;
    v.push_back(head->val);
    for(int i= level;i > -1;i--){
        tmp += v.at(i);
        if(tmp == sum){
            print2(v, i);
        }
    }
    vector<int> v1(v), v2(v);
    find_sum2(head->left, sum, v1, level + 1);
    find_sum2(head->right, sum, v2, level + 1);

}
int main(){
    int a[] = {1,2,3,4,5,6,7};
    TreeNode* head = NULL;
    createMinimalTree(head, NULL, a, 0, 6);
    //find_sum(head, 6);
    vector<int> v;
    find_sum2(head, 6, v, 0);
    return 0;

}