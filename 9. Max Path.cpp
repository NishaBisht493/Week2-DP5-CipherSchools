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

bool isLeaf(TreeNode* root){
    return (root != nullptr && root->left == nullptr && root->right == nullptr);
}

void maxSumPath(TreeNode *root, int sum, int &maxSum){
    if(root == nullptr){
        return;
    }
    sum += root->val;
    if(isLeaf(root)){
        maxSum = max(maxSum, sum);
        return;
    }
    else{
        maxSumPath(root->left, sum, maxSum);
        maxSumPath(root->right, sum, maxSum);
    }
}

int maxPath(TreeNode *root){
    int maxSum = 0;
    maxSumPath(root, 0, maxSum);
    return maxSum;
}

int leafToLeafMaxSum(TreeNode *root, int *ltrsum){
    if(root == NULL){
        *ltrsum = 0;
        return 0;
    }
    if(isLeaf(root)){
        *ltrsum = 0;
        return root->val;
    }

    int lSum = 0;
    int rSum = 0;

    lSum = leafToLeafMaxSum(root->left, ltrsum);
    rSum = leafToLeafMaxSum(root->right, ltrsum);
    if(root->left != nullptr && root->right != nullptr){
        //calculate answer
        *ltrsum = max(*ltrsum, root->val + lSum + rSum);
        return max(lSum, rSum) + root->val;
    }
    else if(root->left != nullptr){
        return root->val + lSum;
    }
    else{
        return root->val + rSum;    
    }


}

int main(){

}