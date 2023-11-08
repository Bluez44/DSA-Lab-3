#include<bits/stdc++.h>
using namespace std;

// Request: Implement function:

// int kthSmallest(BSTNode* root, int k);
// Where root is the root node of given binary search tree (this tree has n elements) and k satisfy: 1 <= k <= n <= 100000.
// This function returns the k-th smallest value in the tree.

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

void NodeList(BSTNode* node, vector<int> &data) {
    if(node == NULL) return;
    data.push_back(node->val);
    NodeList(node->left, data);
    NodeList(node->right, data);
}

int kthSmallest(BSTNode* root, int k) {
    // STUDENT ANSWER
    vector<int> data;
    NodeList(root, data);
    sort(data.begin(), data.end());
    return data[k-1];
}