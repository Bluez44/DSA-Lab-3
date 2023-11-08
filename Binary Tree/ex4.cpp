#include<bits/stdc++.h>
using namespace std;


// Request: Implement function:

// int sumDigitPath(BTNode* root);
// Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). 
// This function returns the sum of all digit path numbers of this binary tree (the result may be large, so you must use mod 27022001 before returning).

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
        int sumDigitPathUtil(BTNode* node, int sum);
        int sumDigitPath(BTNode* root);
};


int BTNode::sumDigitPathUtil(BTNode* node, int sum) {
    if (node == NULL) {
        return 0;
    }
    sum = (sum * 10 + node->val) % 27022001;
    if (node->left == NULL && node->right == NULL) {
        return sum;
    }
    int leftSum = sumDigitPathUtil(node->left, sum);
    int rightSum = sumDigitPathUtil(node->right, sum);
    return (leftSum + rightSum) % 27022001;
}

int BTNode::sumDigitPath(BTNode* root) {
    return sumDigitPathUtil(root, 0);
}