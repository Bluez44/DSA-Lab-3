#include<bits/stdc++.h>
using namespace std;

// Request: Implement function:

// int lowestAncestor(BTNode* root, int a, int b);
// Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). 
// This function returns the lowest ancestor node's val of node a and node b in this binary tree (assume a and b always exist in the given binary tree).

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
        BTNode *lowestAncestorUtil(BTNode *root, int a, int b);
        int lowestAncestor(BTNode *root, int a, int b);
};

BTNode *BTNode::lowestAncestorUtil(BTNode *root, int a, int b) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == a || root->val == b) {
        return root;
    }

    BTNode *leftNode = lowestAncestorUtil(root->left, a, b);
    BTNode *rightNode = lowestAncestorUtil(root->right, a, b);

    if (leftNode && rightNode) {
        return root;
    }

    return (leftNode != NULL) ? leftNode : rightNode;
}

int BTNode::lowestAncestor(BTNode *root, int a, int b) {
    BTNode *ancestor = lowestAncestorUtil(root, a, b);
    return ancestor->val;
}