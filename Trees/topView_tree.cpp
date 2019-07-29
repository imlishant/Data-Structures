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
    //First == Third

    ///*
    map <int,pair<int, int>> m; // map
    map <int, pair<int, int>> :: iterator itr; //itterator

    void store_view(Node * root,int i,int h)
    {
        if(root==NULL)
            return;
        itr=m.find(i);
        if(itr==m.end())
            m[i]=make_pair(h,root->data);
        else
        {
            if(itr->second.first > h)
                m[i]=make_pair(h,root->data);
        }
        if(root->left!=NULL)
            store_view(root->left,i-1,h+1);
        if(root->right!=NULL)
            store_view(root->right,i+1,h+1);
        
    }

    void print_map(){
        for(itr = m.begin(); itr != m.end(); ++itr)
            cout<<itr->second.second<<" ";
    }

    void topView(Node * root)
    {
        store_view(root,0,0);
        print_map();
            return;
    }
    //*/
    
    // Second :: runs only on left OR right nodes.

    /*
    void for_left(Node * root)
    {
        if(root->left!=NULL)
            for_left(root->left);
        cout<<root->data<<" ";
    }


    void for_right(Node * root)
    {
        cout<<root->data<<" ";
        if(root->right!=NULL)
            for_right(root->right);
    }

    void topView(Node * root)
    {
        if(root->left!=NULL)
            for_left(root->left);
        cout<<root->data<<" ";
        if(root->right!=NULL)
            for_right(root->right);
        
    } 
    */

    //Third == First

    /*
    void topView(Node *root) {
        if(root == nullptr)
            return;
        map<int, vector<Node*>> m;
        int dist = 0;
        queue<pair<int, Node*>> Queue;
        Queue.push(make_pair(dist, root));
        while(Queue.empty() == false){
            pair<int, Node*> p = Queue.front();
            m[p.first].push_back(p.second);
            Queue.pop();
            if(p.second->left != nullptr)
                Queue.push(make_pair(p.first - 1, p.second->left));
            if(p.second->right != nullptr)
                Queue.push(make_pair(p.first + 1, p.second->right));
        }
        map<int, vector<Node*>>::iterator it;
        for(it = m.begin(); it != m.end(); ++it){
            cout << it->second.at(0)->data << " ";
        }
    }
    */

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

    cout << "Top View of a Tree is \n"; 
    topView(root); 
    return 0; 
} 