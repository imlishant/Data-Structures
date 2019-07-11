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

int main(){
    Node* root = new Node(1);
    /* 
            1
           / \
        null null
    */
    root->left = new Node(2);
    root->right = new Node(3);
    /* 
            1
          /   \
         2      3
       /   \   /  \ 
    null null null null
    */    
    cout << "root \t\t" << root->data << "\n";
    cout << "root->left \t" << root->left->data << "\n";
    cout << "root->right \t" << root->right->data << "\n";
    return 0;
}
