#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val=val;
        left=right=NULL;
    }
};
TreeNode* treeBuilder(){
    int rootVal;
    cout<<"Enter Root Value"<<endl;
    cin>>rootVal;
    if(rootVal==-1)return NULL;
    TreeNode* node=new TreeNode(rootVal);
    node->left=treeBuilder();
    node->right=treeBuilder();
    return node;
}
void inorder(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val;
    inorder(root->left);
    inorder(root->right);
}
int main(){
    TreeNode* tree=treeBuilder();
    inorder(tree);
    return 0;
}