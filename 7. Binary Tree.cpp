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

void inorder(TreeNode *root, vector<int> &result){
    if(root == nullptr){
        return;
    }
    //LDR
    inorder(root->left);
    result.push_back(root->val);
    inorder(root->right);
}

vector<int> inorder(TreeNode *root){
    vector<int> result;
    inorder(root, result);
    return result;
}

vector<int> preorder(TreeNode *root){
    if(root == nullptr){
        return {};
    }
    vector<int> result;
    stack<TreeNode *> S;
    S.push(root);
    TreeNode *temp;
    while(true){
        while (temp->left != nullptr)
        {
            result.push_back(temp->val);
            S.push(temp);
            temp = temp->left;
        }

        if(S.empty()){
            break;
        }

        temp = S.top();
        S.pop();
        temp = temp->right;        
    }
    return result;
}

int height(TreeNode *root){
    if(root == nullptr){
        return 0;
    }
    else{
        return 1 + max(height(root->left), height(root->right));
    }
}

void printGivenLevel(TreeNode *root, int level, vector<int> &levelH){
    if(root == nullptr){
        return;
    }
    if(level == 0){
        levelH.push_back(root->val);
    }
    else if(level > 0){
        printGivenLevel(root->left, level - 1, levelH);
        printGivenLevel(root->right, level - 1, levelH);
    }
}

vector<vector<int>> levelOrder(TreeNode *root){
    if(root == nullptr){
        return {};
    }

    vector<vector<int>> levelOrder;
    int H = height(root);
    for(int h = 1; h <= H; h++){
        vector<int> levelH;
        printGivenLevel(root, h, levelH);
        levelOrder.push_back(levelH);
    }
    return levelOrder;
}

vector<int> levelOrderIterative(TreeNode *root){
    if(root == nullptr){
        return {};
    }
    vector<int> result;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        root = Q.front();
        Q.pop();
        result.push_back(root->val);
        if(root->left != nullptr){
            Q.push(root->left);
        }
        if(root->right != nullptr){
            Q.push(root->right);
        }
    }
    return result;
}

vector<vector<int>> levelOrderLineByLineIterative(TreeNode *root){
    if(root == nullptr){
        return {};
    }
    vector<vector<int>> result;
    vector<int> currLevel;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        root = Q.front();
        Q.pop();
        if(root == nullptr){
            result.push_back(currLevel);
            currLevel.clear();
            if(!Q.empty()){
                Q.push(nullptr);
            }
        }
        else{
            currLevel.push_back(root->val);
            if(root->left != nullptr){
                Q.push(root->left);
            }
            if(root->right != nullptr){
                Q.push(root->right);
            }
        }
    }
    return result;
}

int main(){

}