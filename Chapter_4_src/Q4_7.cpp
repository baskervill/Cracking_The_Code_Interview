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
    //TreeNode *parent;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
bool match(TreeNode* r1, TreeNode* r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL || r2 == NULL) return false;
    if(r1->val != r2->val) return false;
    else return match(r1->left, r2->left) && match(r1->right, r2->left);
}
//traverse t1 to find if the subtree
bool isSubTree(TreeNode* t1, TreeNode* t2){
    if(t1 == NULL) return false;
    else if(t1 == t2){
        if(match(t1, t2)) return true;
    }
    else return isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
}
bool contain_tree(TreeNode* r1, TreeNode* r2){
    if(r2 == NULL) return true;
    else return isSubTree(r1, r2);
}
void createMinimalTree(TreeNode* &head, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        //head->val = a[mid];
        head = new TreeNode(a[mid]);
        //head->parent = parent;
        createMinimalTree(head->left, a, start, mid - 1);
        createMinimalTree(head->right, a, mid + 1, end);
    }
}
int main(){
    int a[] = {0,1,2,3,4,5,6,7,8};
    TreeNode* head;
    createMinimalTree(head, a, 0, 8);
    int b[] = {0, 1, 2, 3};
    TreeNode* head1;
    createMinimalTree(head1, b, 0, 3); 
    cout<<contain_tree(head, head1)<<endl;
    return 0;
}