#include<bits/stdc++.h>
using namespace std;

// Request: Implement function:

// int rangeCount(BTNode* root, int lo, int hi);
// Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements), lo and hi are 2 positives integer and lo ≤ hi. 
// This function returns the number of all nodes whose values are between [lo, hi] in this binary search tree.

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
};

int rangeCountRec(BTNode* node, int lo, int hi) {
    if(!node) return 0;
    if(node->val < lo || node->val > hi) return rangeCountRec(node->left, lo, hi) + rangeCountRec(node->right, lo, hi);
    else return 1 + rangeCountRec(node->left, lo, hi) + rangeCountRec(node->right, lo, hi);
}

int rangeCount(BTNode* root, int lo, int hi) {
    return rangeCountRec(root, lo, hi);   
}