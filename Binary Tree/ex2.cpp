#include<bits/stdc++.h>
using namespace std;



class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
        pair<int, int> longestPathSumHelper(BTNode* root);
        int longestPathSum(BTNode* root);
};



pair<int, int> BTNode::longestPathSumHelper(BTNode* root) {
        if (root == nullptr) {
            return {0, 0}; // giá trị đầu tiên là chiều dài đường đi
                           // giá trị thứ 2 là tổng các phần tử
        }
        // root = NULL -> path = 0, sum = 0;
        if (root->left == nullptr && root->right == nullptr) {
            return {1, root->val};
        }
        // Nếu chỉ có root -> path = 1; sum = root ->val;
        auto leftSum = longestPathSumHelper(root->left); // gọi đệ quy left subtree
        auto rightSum = longestPathSumHelper(root->right); // gọi đệ quy right subtree
        // so sánh độ dài của cây con trái và phải.
        if (leftSum.first > rightSum.first) {
            return {leftSum.first + 1, leftSum.second + root->val};
        } else if (leftSum.first < rightSum.first) {
            return {rightSum.first + 1, rightSum.second + root->val};
        } else {
            return {leftSum.first + 1, max(leftSum.second, rightSum.second) + root->val};
    }
    }

int BTNode::longestPathSum(BTNode* root) {
    auto result = longestPathSumHelper(root);
    return result.second;
}