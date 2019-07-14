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

// queue approach
/*
void print_K_distance(Node* root, int k){
    
    // base case here
    
    Node* node = root;
    queue<Node*> q;
    int reach = k+1;
    q.push(root);
    while(!q.empty() && reach){
        node = q.front();
        int levelCount = q.size();
    }
}
*/

// recursive 
void print_K_distance(Node* root, int k){
    if(root == nullptr || k < 0)
        return ;
    if(k == 0){
        cout << root->data << " ";
        return;
    }
    print_K_distance(root->left, k-1);
    print_K_distance(root->right, k-1);
}

int main(){

    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(456); 
    root->left->right = new Node(579); 
  
    print_K_distance(root, 2); 
    return 0; 
}