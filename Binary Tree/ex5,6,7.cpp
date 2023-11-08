#include<iostream>
#include<string>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }
    int countTwoChildrenNodesRec(Node* node);
    int countTwoChildrenNode();
    int getHeightRec(Node *node);
    int getHeight();
    void preOrderRecursive(Node* node, string& s);
    string preOrder();
    void inOrderRecursive(Node* node, string &s);
    string inOrder();
    void postOrderRecursive(Node* node, string &s);
    string postOrder() ;
    int sumOfLeafs(Node* node);
    int sumOfLeafs();

};
// STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
template<class K, class V>
int BinaryTree<K,V>::countTwoChildrenNodesRec(Node* node) {
    if(node->pLeft != NULL && node->pRight != NULL) return 1 + countTwoChildrenNodesRec(node->pLeft) + countTwoChildrenNodesRec(node->pRight);
    else if(node->pLeft == NULL && node->pRight != NULL) return countTwoChildrenNodesRec(node->pRight);
    else if(node->pRight == NULL && node->pLeft != NULL) return countTwoChildrenNodesRec(node->pLeft);
    else return 0;
}


template<class K, class V>
int BinaryTree<K,V>::countTwoChildrenNode()
{
    return countTwoChildrenNodesRec(root);
}

// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

template<class K, class V>
int BinaryTree<K,V>::getHeightRec(Node *node)
{
	if(node == NULL) return 0;
	int i = getHeightRec(node->pLeft);
	int j = getHeightRec(node->pRight);
	if(i >= j) return 1 + i;
	else return 1 + j;
}

template<class K, class V>
int BinaryTree<K,V>::getHeight() {
    // TODO: return height of the binary tree.
    return getHeightRec(root);
}

template<class K, class V>
void BinaryTree<K,V>::preOrderRecursive(BinaryTree<K,V>::Node* node, string& s) {
    if(!node) return;
    s += to_string(node->value) + " ";
    preOrderRecursive(node->pLeft, s);
    preOrderRecursive(node->pRight, s);
}

template<class K, class V>
string BinaryTree<K,V>::preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    string s = "";
    preOrderRecursive(root, s);
    return s;
}

template<class K, class V>
void BinaryTree<K,V>::inOrderRecursive(Node* node, string &s) {
    if(!node) return;
    inOrderRecursive(node->pLeft, s);
    s += to_string(node->value) + " ";
    inOrderRecursive(node->pRight, s);
}
template<class K, class V>
string BinaryTree<K,V>:: inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    string s = "";
    inOrderRecursive(root, s);
    return s;
}

template<class K, class V>
void BinaryTree<K,V>:: postOrderRecursive(BinaryTree<K,V>::Node* node, string &s) {
    if(!node) return;
    postOrderRecursive(node->pLeft, s);
    postOrderRecursive(node->pRight, s);
    s += to_string(node->value) + " ";
}

template<class K, class V>
string BinaryTree<K,V>:: postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    string s = "";
    postOrderRecursive(root, s);
    return s;
}

//Helping functions
template<class K, class V>
int BinaryTree<K,V>:: sumOfLeafs(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->pLeft == nullptr && node->pRight == nullptr) {
        return node->value;
    }
    return sumOfLeafs(node->pLeft) + sumOfLeafs(node->pRight);
}

template<class K, class V>
int BinaryTree<K,V>:: sumOfLeafs(){
    //TODO
    return sumOfLeafs(root);    
}
// STUDENT ANSWER END
// STUDENT ANSWER END