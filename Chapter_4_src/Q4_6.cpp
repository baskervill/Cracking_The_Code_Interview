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
    TreeNode(int x): val(x), left(NULL), right(NULL), parent(NULL){}
};
TreeNode *createTree(int a[], int n){
    if(n <= 0) return NULL;
    TreeNode **tree = new TreeNode*[n];
    for(int i = 0;i < n;i++){
        if(a[i] == 0){
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos = 1;
    for(int i = 0;pos < n && i < n;i++){
        if(tree[i]){
            tree[i]->left = tree[pos++];
            if(pos < n)
                tree[i]->right = tree[pos++];
        }
    }
    return tree[0];
}
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
unordered_map<TreeNode*, int> m1;
TreeNode* ancestor(TreeNode* n1, TreeNode* n2){
    int count = 0;
    while(n1){
        n1 = n1->parent;
        m1[n1] = count;
    }
    while(n2){
        if(m1.find(n2->parent) != m1.end())
            return n2->parent;
        else 
            n2 = n2->parent;
    }
    return NULL;
}
//if can't use another space , then
bool father(TreeNode* n1, TreeNode* n2){
    if(n1 == NULL) return false;
    if(n1 == n2) return true;
    else return father(n1->left, n2) || father(n1->right, n2);
}
TreeNode* first_ancestor(TreeNode* n1, TreeNode* n2){
    if(n1 == NULL || n2 == NULL) return NULL;
    while(n1){
        if(father(n1, n2)) return n1;
        n1 = n1->parent;
    }
    return NULL;
}
//if there is no parent pointer, then from the root because root must be the common ancestor
void first_ancestor2(TreeNode* head, TreeNode* n1, TreeNode* n2, TreeNode* &ans){
    if(head == NULL || n1 == NULL || n2 == NULL) return ;
    if(head && father(head, n1) && father(head, n2)){
        ans = head;
        first_ancestor2(head->left, n1, n2, ans);
        first_ancestor2(head->right, n1, n2, ans);
    }
}
int main(){
    int a[] = {0,1,2,3,4,5,6,7,8};
    TreeNode* head;
    createMinimalTree(head, NULL, a, 0, 8);
    TreeNode* anc = ancestor(head->left->left, head->left->right);
    TreeNode* ans;
    first_ancestor2(head, head->left->left,  head->left->right, ans);
    cout<<anc->val<<endl;
    cout<<ans->val<<endl;
    return 0;
}