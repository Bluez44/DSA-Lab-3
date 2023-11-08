// In this question, you have to perform add and delete on binary search tree. Note that:

// - When deleting a node which still have 2 children, take the inorder successor (smallest node of the right sub tree of that node) to replace it.

// - When adding a node which has the same value as parent node, add it in the left sub tree.

// Your task is to implement two functions: add and deleteNode. You could define one or more functions to achieve this task.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    //Helping function

    void add(T value){
        //TODO
    }
    
    Node* findMin(Node* &node) ;

    void removeRec(Node *&node, const int &value) ;
    
    void deleteNode(T value){
        //TODO
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};



//Helping functions

template<class T>
void BinarySearchTree<T>::add(T value){
    //TODO
    if(!root) {root = new Node(value); return;}
    Node* tmp = root;
	while(tmp != NULL) {
	    if(tmp->value == value) {
	        Node* newnode = new Node(value);
	        newnode->pLeft = tmp->pLeft;
	        tmp->pLeft = newnode;
	        return ;
	    }
	    if(value < tmp->value) {
	        if(tmp->pLeft != NULL) tmp = tmp->pLeft;
	        else {
	            tmp->pLeft = new Node(value);
	           // cout << "add left\n";
	            return;
	        }
	    }
	    else if(value > tmp->value) {
	        if(tmp->pRight != NULL) tmp = tmp->pRight;
	        else {
	            tmp->pRight = new Node(value);
	           // cout << "add right\n";
	            return;
	        }
	    }
	}
}

template<class T> 
BinarySearchTree<T>::Node *BinarySearchTree<T>::findMin(Node *&node) {
    if(node == NULL) return NULL;
    Node* MIN = node;
    Node* left = findMin(node->pLeft);
    Node* right = findMin(node->pRight);
    if(left!= NULL && MIN->value > left->value) {
        MIN = left;
    }
    if(right != NULL && MIN->value > right->value) {
        MIN = right;
    }
    return MIN;
}

template<class T>
void BinarySearchTree<T>::removeRec(Node *&node, const int &value)
{
    if(node == NULL) return ;
    if(value < node->value) return removeRec(node->pLeft, value);
    else if(value > node->value) return removeRec(node->pRight, value);
    else if(value == node->value) {
        if(node->pLeft == NULL && node->pRight == NULL) {
            delete node;
            node = NULL;
            return ;
        }
        else if(node->pLeft != NULL && node->pRight != NULL) {
            Node* min = findMin(node->pRight);
            node->value = min->value;
            removeRec(node->pRight, min->value);
            return ;
        }
        else if(node->pLeft == NULL) {
            Node* tmp = node;
            node  = node->pRight;
            delete tmp;
            return ;
        }
        else if(node->pRight == NULL) {
            Node* tmp = node;
            node = node->pLeft;
            delete tmp;
            return ;
        }
    }
    return ;
}

template<class T>
void BinarySearchTree<T>::deleteNode(T value){
    //TODO
    // if(!root) return;
    // Node* tmp = root;
    // while(!tmp) {
    //     if(tmp->value == value) {
    //         if(!tmp->pRight && !tmp->pLeft) {delete tmp; break;}
    //         else if(!tmp->pRight) {
    //             Node* node = tmp;
    //             tmp = tmp->pLeft;
    //             delete node;
    //             break;
    //         }
    //         else {
    //             Node* min = findMin(tmp->pRight);
    //             Node* newnode = new Node(min->value);
    //             newnode->pRight = tmp->pRight;
    //             newnode->pLeft = tmp->pLeft;
    //         }
    //     }
    //     else if(value > tmp->value) {
    //         tmp = tmp->pRight;
    //     }
    //     else if(value < tmp->value) {
    //         tmp = tmp->pLeft;
    //     }
    // }
    removeRec(root, value);
};