#include<bits/stdc++.h>
using namespace std;

// Request: Implement function:

// vector<int> levelAlterTraverse(BSTNode* root);
// Where root is the root node of given binary search tree (this tree has between 0 and 100000 elements). 
// This function returns the values of the nodes in each level, alternating from going left-to-right and right-to-left..

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

vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
    vector<int> RES;
    if(!root) return RES;
    bool left_to_right = true;
    queue<BSTNode*> q;
    stack<BSTNode*> s;
    
    q.push(root);
    
    while(1) {
        if(left_to_right) {
            while(!q.empty()) {
                BSTNode* tmp = q.front();
                q.pop();
                RES.push_back(tmp->val);
                if(tmp->left) s.push(tmp->left);
                if(tmp->right) s.push(tmp->right);
            }
        }
        else {
            vector<BSTNode*> vec;
            while(!s.empty()) {
                BSTNode* tmp = s.top();
                s.pop();
                RES.push_back(tmp->val);
                if(tmp->right) vec.push_back(tmp->right);
                if(tmp->left) vec.push_back(tmp->left);
                
            }
            int n = vec.size();
            for(int i = 0; i < n; i++) {
                q.push(vec.back());
                vec.pop_back();                
            }
        }
        
        (left_to_right)? left_to_right = false : left_to_right = true;
        if(q.empty() && s.empty()) break;  
    }
    
    return RES;
}