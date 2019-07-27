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

bool checkBST(Node* root, int min, int max){
    if(root == nullptr)
        return true;
    if(min < root->data && root->data < max){
        return checkBST(root->left, min, root->data)
         && checkBST(root->right, root->data, max);
    }
    return false;
}

bool isBST(Node* root){
    return checkBST(root, INT_MIN, INT_MAX);
}

//preorder::
//14
//12 5 3 1 7 9 8 11 15 13 14 17 20 18

int main(){
    cout << "Enter number of node : ";
    int n;
    cin >> n;
    int key;
    Node* root = nullptr;
    cout << "Enter n keys :: ";
    while(n--){
        cin >> key;
        root = insert(root, key);
    }
    int flag = isBST(root);

    if(isBST(root))
        cout << "is BST \n";
    else cout << "is NOT BST \n";

    return 0;
}