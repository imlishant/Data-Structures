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

Node* insert(Node* node, int data)
{
    if(node == nullptr)
        return new Node(data);
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    // when returning in if function it returns the attached node NOT the root.
    // That is it only adds the node and replaces the root everytime.
    return node;
}

void inorder(Node* root){
    if(root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        Node *root = nullptr;
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
            int k;
            cin >> k;
            root = insert(root, k);
        }
        inorder(root);
        cout << "\n";
    }
    return 0;
}