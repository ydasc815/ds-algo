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
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
}

void reverse_levelorder(Node* root) {
    if(root == null) return;

    queue<Node*> q;
    stack<int> st;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        st.push(temp->data);
        if(temp->right) {
            q.push(temp->right);
        }
        if(temp->left) {
            q.push(temp->left);
        }
    }
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
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

    reverse_levelorder(root);
}