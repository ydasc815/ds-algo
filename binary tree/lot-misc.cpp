#include<bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = null;
    }
};

void levelorder(Node* root) {
    if(root == null) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != null) {
            q.push(temp->left);
        }
        if(temp->right != null) {
            q.push(temp->right);
        }
    }
}

void levelorder_insertion(Node* root, int key) {
    if(root == null) {
        root = new Node(key);
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp->left != null) {
            q.push(temp->left);
        } else {
            temp->left = new Node(key);
            return;
        }
        if(temp->right != null) {
            q.push(temp->right);
        } else {
            temp->right = new Node(key);
            return;
        }
    }
}

Node* getLastNode(Node* root) {
    if(root == null) {
        return null;
    }
    if(root->left == null && root->right == null) {
        return root;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp->left != null) {
            q.push(temp->left);
        } else {
            return temp->left;
        }
        if(temp->right != null) {
            q.push(temp->right);
        } else {
            return temp->right;
        }
    }
    return null;
}

void deleteNode(Node* root, int key) {
    // TODO
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(3);
    root->right = new Node(1);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(8);
    root->right->right = new Node(7);

    levelorder(root);
    cout<<"\n";

    levelorder_insertion(root, 5);

    levelorder(root);
}