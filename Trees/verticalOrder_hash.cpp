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

void getVerticalOrder(Node* root, map<int, vector<int>> &m, int dist){
    if(root == nullptr)
        return;
    m[dist].push_back(root->data);
    getVerticalOrder(root->left, m, dist-1);
    getVerticalOrder(root->right, m, dist+1);
}

void printVerticalOrder(Node* root){
    map<int, vector<int>> m;
    int dist = 0;
    getVerticalOrder(root, m, dist);
    map<int, vector<int>>::iterator it;
    for(it = m.begin(); it != m.end(); ++it){
        cout << "Level " << it->first << " : ";
        for(unsigned int i = 0; i < it->second.size(); i++)
            cout << it->second[i] << " ";
        cout << "\n";
    }
}

int main() 
{ 
    /*
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); 
    */

    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); 
    root->right->right->left= new Node(10); 
    root->right->right->left->right= new Node(11); 
    root->right->right->left->right->right= new Node(12); 

    cout << "Vertical order traversal is \n"; 
    printVerticalOrder(root); 
    return 0; 
} 