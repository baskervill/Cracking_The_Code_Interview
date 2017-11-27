#include <iostream>
#include <cstring>
#include <cmath>
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
//Inorder traversal
int d = 0, num = 0, dep[maxn];
void getDepth(TreeNode *head){
    if(head == NULL) return;
    ++d;
    getDepth(head->left);
    if(head->left == NULL && head->right == NULL)
        dep[num++] = d;
    getDepth(head->right);
    --d;//why? 

}
bool isBalance(TreeNode *head){
    if(head == NULL) return true;
    getDepth(head);
    int max = dep[0], min = dep[0];
    for(int i = 0;i < num;i++){
        if(dep[i] > max) max = dep[i];
        if(dep[i] < min) min = dep[i];
    }
    if(max - min > 1) return false;
    else return true;
}
int main(){
    int a[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    TreeNode* head = createTree(a, 12);
    cout<<isBalance(head)<<endl;
    return 0;
}

