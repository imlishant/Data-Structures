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

//assuming both x and y exist in a tree
Node* LCA(Node* root, int x, int y){
    if(root == nullptr)
        return nullptr;
    if(root->data == x || root->data == y)
        return root;
    Node* left_subtree = LCA(root->left, x, y);
    Node* right_subtree = LCA(root->right, x, y);
    if(left_subtree == nullptr)
        return right_subtree;
    if(right_subtree == nullptr)
        return left_subtree;
    return root;
}

int main(){
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    root->left->left->left = new Node(6); 
    root->left->left->left->right = new Node(7); 
    int x, y;
    cout << "Enter x & y ";
    cin >> x >> y;
    Node* lca;
    /*
    lca = LCA(root, 4, 5);
    cout << "Lowest Common Ancestor = " << lca->data << "\n";
    lca = LCA(root, 5, 6);
    cout << "Lowest Common Ancestor = " << lca->data << "\n";
    lca = LCA(root, 4, 6);
    cout << "Lowest Common Ancestor = " << lca->data << "\n";
    lca = LCA(root, 4, 3);
    cout << "Lowest Common Ancestor = " << lca->data << "\n";
    lca = LCA(root, 2, 7);
    cout << "Lowest Common Ancestor = " << lca->data << "\n";
    */
    lca = LCA(root, x, y);
    cout << "Lowest Common Ancestor = " << lca->data << "\n";
    return 0;
}