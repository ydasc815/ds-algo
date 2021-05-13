#include<bits/stdc++.h>
#define null NULL
#pragma gcc optimize -O3
using namespace std;

class Node {
    public: 
    int data;
    Node *left, *right;
    // create a constructor so as to avoid defining
    // left and right nodes as null, everytime a node is created.
    Node(int data) {
        this->data = data;
        this->left = this->right = null;
    }
};

void inorder(Node* node) {
    if(node == null) return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

void levelorder(Node* node) {
    if(node == null) return;

    queue<Node*> q;
    q.push(node);
    while(!q.empty()) {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        if(temp->left != null) q.push(temp->left);
        if(temp->right != null) q.push(temp->right);
        q.pop();
    }
}

void insert_levelorder(Node* node, int data) {
    if(node == null){
        // root node not exist
        node = new Node(data);
        return;
    }

    queue<Node*> q;
    q.push(node);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp->left != null) {
            q.push(temp->left);
        } else {
            temp->left = new Node(data);
            return;
        }
        if(temp->right != null) {
            q.push(temp->right);
        } else {
            temp->right = new Node(data);
            return;
        }
    }
}

void preorder(Node* node) {
    if(node == null) return;

    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if(node == null) return;

    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    // // printing inorder traversal of binary tree
    // inorder(root);
    // cout<<"\n";

    // // printing preorder traversal of binary tree
    // preorder(root);
    // cout<<"\n";

    // // printing postorder traversal of binary tree
    // postorder(root);
    // cout<<"\n";

    // level order traversal 
    levelorder(root);
    cout<<"\n";
    insert_levelorder(root, 10);
    // level order after insertion
    levelorder(root);
    cout<<"\n";
    // inorder after insertion
    inorder(root);
}