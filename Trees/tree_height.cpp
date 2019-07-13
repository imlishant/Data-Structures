#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int maxHeight(Node* node){
    if(node == nullptr)
        return 0;
    int leftHeight = maxHeight(node->left);
    int rightHeight = maxHeight(node->right);
    int maxDepth = 1 + max(leftHeight, rightHeight);
    return maxDepth;
}

int main(){
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    cout << "Height = " << maxHeight(root);
    return 0;
}