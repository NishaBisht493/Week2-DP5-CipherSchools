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

// bool isLeaf(TreeNode* root){
//     return (root != nullptr && root->left == nullptr && root->right == nullptr);
// }

// void range(TreeNode* root, const pair<int, int> &rg, vector<int> &result){
//     if(root == nullptr){
//         return;
//     }
//     if(root->val < rg.first){
//         range(root->right, rg, result);
//     }
//     else if(root->val > rg.second){
//         range(root->left, rg, result);
//     }
//     else{
//         result.push_back(root->val);
//         range(root->left, rg, result);
//         range(root->right, rg, result);
//     }
// }

int find(vector<int> &preorder, int start, int end, int x){
    int index = start;
    while(index <= end && preorder[index] > x){
        index++;
    }
    return index;
}

TreeNode* buildTree(vector<int> &preOrder, int start, int end){
    if(start > end){
        return nullptr;
    }
    TreeNode *newNode = new TreeNode(preOrder[start]);
    if(start == end){
        return newNode;
    }
    else{
        int index = find(preOrder, start + 1, end, newNode->val);
        newNode->left = buildTree(preOrder, start, index - 1);
        newNode->right = buildTree(preOrder, index, end);
    }
}

TreeNode *buildTree1(vector<int> &sortedArr, int start, int end){
    if(start > end){
        return nullptr;
    }
    int mid = start + (end - start)/2;
    TreeNode *newNode = new TreeNode(sortedArr[mid]);
    
    // int index = find(preOrder, start + 1, end, newNode->val);
    newNode->left = buildTree1(sortedArr, start, mid- 1);
    newNode->right = buildTree1(sortedArr, mid + 1, end);

}

int main(){
    
}