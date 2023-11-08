// Given class BinarySearchTree, you need to finish method find(i) to check whether value i is in the tree or not; 
// method sum(l,r) to calculate sum of all all elements v in the tree that has value greater than or equal to l and less than or equal to r.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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
    Node* addRec(Node* root, T value);
    void add(T value) ;
    // STUDENT ANSWER BEGIN
 
    // STUDENT ANSWER END
};

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

template<class T>
bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    Node* tmp = root;
    while(tmp != NULL) {
        if(i < tmp->value) tmp = tmp->pLeft;
        else if(i > tmp->value) tmp = tmp->pRight;
        else if(i == tmp->value) return true;
    }
    return false;
}

template<class T>
T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    Node* tmp = root;
    Node* array[100];
    int n = 0, sum = 0;
    int j = 0;
    while(j <= n) {
        if(tmp->value >= l && tmp->value <= r) sum += tmp->value;
        if(tmp->pLeft) {
            array[n] = tmp->pLeft;
            n++;
        }
        if(tmp->pRight) {
            array[n] = tmp->pRight;
            n++;
        }
        tmp = array[j];
        j++;
    }
    return sum;
}

// STUDENT ANSWER END

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

template<class T>
T getMin() {
    //TODO: return the minimum values of nodes in the tree.
    if(!root) return -1;
    Node* tmp = root;
    while(tmp->pLeft != NULL) {
        tmp = tmp->pLeft;
    }
    return tmp->value;
}

template<class T>
T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    if(!root) return -1;
    Node* tmp = root;
    while(tmp->pRight != NULL) {
        tmp = tmp->pRight;
    }
    return tmp->value;
}

// STUDENT ANSWER END