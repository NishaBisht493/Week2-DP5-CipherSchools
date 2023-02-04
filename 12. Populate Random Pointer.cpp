#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *random;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :  val(x), left(left), right(right) {}
};

bool isLeaf(TreeNode* root){
    return (root != nullptr && root->left == nullptr && root->right == nullptr);
}

void populateRandomPointer(TreeNode *root){
    if(root == nullptr || isLeaf(root)){
        return;
    }

    queue<TreeNode*> Q;
    Q.push(root);
    TreeNode *prev;
    while(!Q.empty()){
        int size = Q.size();

        for(int i = 0; i < size; i++){
            root = Q.front();
            Q.pop();

            if(i == 0){
                prev = root;
            }
            else{
                prev->random = root;
                prev = root;
            }

            if(root->left){
                Q.push(root->left);
            }

            if(root->right){
                Q.push(root->right);
            }   
        }
    }
}

int main(){

}