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

void LevelOrderTraversal(Node* root){
    if(root == nullptr)
        return;
    queue<Node*> Queue;
    Queue.push(root);
    int round = 0;
    while(Queue.empty() == false){
        int count = Queue.size();
        cout << "Level " << round++ << " : ";
        while(count--){
            Node* node = Queue.front();
            cout << node->data << " ";
            Queue.pop();
            if(node->left != nullptr)
                Queue.push(node->left);
            if(node->right != nullptr)
                Queue.push(node->right);
        }
        cout << "\n";
    }
}

int main(){
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
    root->left->left->left = new Node(6); 
    root->left->left->left->right = new Node(7);
    LevelOrderTraversal(root); 
    return 0;
}