#include<bits/stdc++.h>
using namespace std;

// Request: Implement function:

// BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi);
// Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). 
// This function returns the binary search tree after deleting all nodes whose values are outside the range [lo, hi] (inclusive).

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

BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    // STUDENT ANSWER
    if(!root) return NULL;
    
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);
    
    if(root->val < lo) {
        BSTNode* right = root->right;
        delete root;
        return right;
    }
    if(root->val > hi) {
        BSTNode* left = root->left;
        delete root;
        return left;
    }
    return root;
}