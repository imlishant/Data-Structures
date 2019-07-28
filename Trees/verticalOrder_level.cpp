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

void printVerticalOrder(Node* root){
    if(root == nullptr)
        return;
    map<int, vector<Node*>> m;
    int dist = 0;
    queue<pair<int, Node*>> Queue;
    Queue.push(make_pair(dist, root));
    while(Queue.empty() == false){
        pair<int, Node*> p = Queue.front();
        Queue.pop();
        m[p.first].push_back(p.second);
        if(p.second->left != nullptr)
            Queue.push(make_pair(p.first-1, p.second->left));
        if(p.second->right != nullptr)
            Queue.push(make_pair(p.first+1, p.second->right));
    }

    map<int, vector<Node*>>::iterator it;
    for(it = m.begin(); it != m.end(); ++it){
        cout << "Level " << it->first << " : ";
        for(unsigned int i = 0; i < it->second.size(); i++){
            cout << it->second.at(i)->data << " ";
        }
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