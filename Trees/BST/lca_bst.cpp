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
    return node;
}

void inorder(Node* root){
    if(root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* lca(Node* root, int a, int b){
    if(a < root->data && b < root->data)
        return lca(root->left, a, b);
    else if(a > root->data && b > root->data)
        return lca(root->right, a, b);
    else return root;
}

int main(){
    int n;
    cin >> n;
    int key;
    Node* root = nullptr;
    while(n--){
        cin >> key;
        root = insert(root, key);
    }
    int a, b;
    cin >> a >> b;
    Node* node = lca(root, a, b);
    cout << "lca = " << node->data;
    return 0;
}