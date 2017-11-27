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
    TreeNode(int x): val(x), left(NULL), right(NULL){}
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
//the minimal tree should be balance that the left node's number equal to the right's
void createMinimalTree(TreeNode* &head, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        //head->val = a[mid];
        head = new TreeNode(a[mid]);
        createMinimalTree(head->left, a, start, mid - 1);
        createMinimalTree(head->right, a, mid + 1, end);
    }
}
int height(TreeNode *head){
    if(head == NULL) return 0;
    return max(height(head->left), height(head->right)) + 1;
}
int main(){
    int a[] = {0,1,2,3,4,5,6,7,8};
    TreeNode* head;
    createMinimalTree(head, a, 0, 8);
    //TreeNode* head = createTree(a, 6);
    int h = height(head);
    cout<<h<<endl;
    return 0;
}