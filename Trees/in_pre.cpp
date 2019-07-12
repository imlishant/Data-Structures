#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;
    Node(int value){
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int search(char arr[], int start, int end, char value);
void print_inorder(Node* root);

Node* build(char inorder[], char preorder[], int start, int end){
    static int preIndex = 0;
    if(start > end)
        return nullptr;
    Node* node = new Node(preorder[preIndex++]);
    if(start == end)
        return node;
    int inIndex = search(inorder, start, end, node->data);

    node->left = build(inorder, preorder, start, inIndex-1);
    node->right = build(inorder, preorder, inIndex+1, end);

    return node;
}

int main(){
    char inorder[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char preoder[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int length = sizeof(inorder) / sizeof(inorder[0]);
    Node* root = build(inorder, preoder, 0, length-1);
    print_inorder(root);
    return 0;    
}

int search(char arr[], int start, int end, char value){
    for(int i = start; i < end; i++){
        if(arr[i] == value)
            return i;
    }
    //return 0; // why?????????
}

void print_inorder(Node* root){
    if(!root)
        return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}