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

bool printAncestors(Node* root, int target){
    if(root == nullptr)
        return false;
    if(root->data == target)
        return true;
    if(printAncestors(root->left, target) || printAncestors(root->right, target)){
        cout << root->data << " ";
        return true;
    }
    return false;
}

int main(){

    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);

    printAncestors(root, 5);

    return 0;
}