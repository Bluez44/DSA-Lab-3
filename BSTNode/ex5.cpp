#include<bits/stdc++.h>
using namespace std;

// Request: Implement function:

// int singleChild(BSTNode* root);
// Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). 
// This function returns the number of single children in the tree.

class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};

int singleChild(BSTNode* root) {
    // STUDENT ANSWER
    if(!root) return 0;
    if(root->left && !root->right) return 1 + singleChild(root->left);
    else if(!root->left && root->right) return 1 + singleChild(root->right);
    else if(root->left && root->right) return singleChild(root->left) + singleChild(root->right);
    else return 0;
}