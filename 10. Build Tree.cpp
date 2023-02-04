#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :  val(x), left(left), right(right) {}
};

// int height(TreeNode *root){
//     if(root == nullptr){
//         return 0;
//     }
//     else{
//         return 1 + max(height(root->left), height(root->right));
//     }
// }

int find(vector<int> inOrder, int start, int end, int x){
    for(int i = start; i <= end; i++){
        if(inOrder[i] == x){
            return i;
        }
    }
    return -1;
}

TreeNode* buildTree(const vector<int> &preOrder, const vector<int> &inOrder, int start, int end, int &curr){
    if(start > end){
        return nullptr;
    }
    TreeNode *newNode = new TreeNode(preOrder[curr]);
    curr++;

    if(start == end){
        return newNode;
    }
    else{
        int index = find(inOrder, start, end, newNode->val);
        newNode->left = buildTree(preOrder, inOrder, start, index - 1, curr);
        newNode->right = buildTree(preOrder, inOrder, index + 1, end, curr);
    }
}

TreeNode* buildTree(const vector<int> &preOrder, const vector<int> &inOrder){

}

int main(){

}