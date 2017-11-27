#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
void initBST(TreeNode* &head, vector<int> &a, int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        head = new TreeNode(a[mid]);
        initBST(head->left, a, start, mid - 1);
        initBST(head->right, a, mid + 1, end);
    }
}
//use BFS
vector<list<TreeNode*> > find_level_linklists(TreeNode *head){
    vector<list<TreeNode*> > res;
    int level = 0;
    list<TreeNode*> li;
    li.push_back(head);
    res.push_back(li);
    while(!res[level].empty()){
        list<TreeNode*> l;
        list<TreeNode*>::iterator it;
        for(it=res[level].begin(); it!=res[level].end(); ++it){
            TreeNode *n = *it;
            if(n->left) l.push_back(n->left);
            if(n->right) l.push_back(n->right);
        }
        ++level;
        res.push_back(l);
    }
    return res;
}
int main(){
    int a[] = {0,1,2,3,4,5,6,7,8};
    vector<int> b(a, a+9);
    TreeNode* head;
    initBST(head, b, 0, 8);
    vector<list<TreeNode*> > res1;
    res1 = find_level_linklists(head);
    vector<list<TreeNode*> >::iterator vit;
    for(vit = res1.begin();vit != res1.end();vit++){
        list<TreeNode*> li = *vit;
        list<TreeNode*>::iterator lit;
        for(lit = li.begin();lit != li.end();lit++){
            TreeNode* n = *lit;
            cout<<n->val<<" ";
        }
        cout<<endl;
    }
    return 0;
}