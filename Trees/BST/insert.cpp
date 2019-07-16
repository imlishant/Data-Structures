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
    Node *ptr = node;
    Node *temp = new Node(data);
    if(node == nullptr)
        return new Node(data);
    Node *pre = node;
    while(ptr != nullptr){
        pre = ptr;
        if(ptr->data < data){
            ptr = ptr->right;
        }
        else if(ptr->data > data){
            ptr = ptr->left;
        }else return node;
    }
    if(data < pre->data)
        pre->left = temp;
    else if(data > pre->data)
        pre->right = temp;
    
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
