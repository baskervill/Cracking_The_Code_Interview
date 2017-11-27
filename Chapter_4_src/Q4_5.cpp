#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
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
//find the minimal left child 
TreeNode* minimal(TreeNode* node){
    if(node == NULL) return NULL;
    while(node->left)
        node = node->left;
    return node;
}
//if node has right child, then it will be the minimal of its right child , else find the first one 
//between his parents which bigger than it 
TreeNode* successor(TreeNode* node){
    if(node == NULL) return NULL;
    if(node->right) return minimal(node->right);
    TreeNode* y = node->parent;
    while(y && y->right == node){ // this is important, if node don't has a right, is is the first one 
    //the feature of this is it's in the first parent's left, not right
        node = y;
        y = y->parent;
    }
    return y;
}
int main(){
    int a[] = {0,1,2,3,4,5,6,7,8};
    TreeNode* head;
    createMinimalTree(head, NULL, a, 0, 8);
    //in this case 3 and 8 has some different , so checkout in the function successor
    TreeNode* res = successor(head->left->right->right);
    cout<<res->val<<endl;
    return 0;
}
