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

Node* Findmin(Node* node){
    //node never null;
    //so no base case;
    while(node->left){
        node = node->left;
    }
    return node;
}

Node* delete_bst(Node* root, int target){
    if(root == nullptr)
        return nullptr;
    if(target < root->data)
        root->left = delete_bst(root->left, target);
    else if(target > root->data)
        root->right = delete_bst(root->right, target);
    else{
        //case 1 :: no child
        if(root->left == nullptr && root->right == nullptr){
            delete(root);
            root = nullptr;
        }//case 2 :: 2 child 
        else if(root->left != nullptr && root->right != nullptr){
            Node* temp = Findmin(root->right);
            root->data = temp->data;
            root->right = delete_bst(root->right, temp->data);
        }else{
            if(root->left == nullptr){
                Node* temp = root;
                root = root->right;
                delete temp;
            }else{
                Node* temp = root;
                root = root->left;
                delete temp;
            }
        }
    }
    return root;
}

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
    cout << "Before inorder :: ";
    inorder(root);
    cout << "\nEnter value to delete :: ";
    int k;
    cin >> k;
    root = delete_bst(root, k);
    cout << "After inorder :: ";
    inorder(root);
    return 0;
}