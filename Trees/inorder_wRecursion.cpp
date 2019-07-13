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

void inorder(Node* root){
    if(root == nullptr)
        return;
    Node* curr = root;
    stack<Node*> s;
    //s.push(curr);
    while(curr != nullptr || s.empty() == false){
        while(curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        cout << curr->data << " ";
        s.pop();
        curr = curr->right;
    }
}

int main(){
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    inorder(root);
    return 0;
}