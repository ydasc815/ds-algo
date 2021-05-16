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

void inorder_iter(Node* root) {
    stack<Node*> st;
    if(root == null) return;

    Node* temp = root;
    st.push(root);
    while(!st.empty()) {
        if(temp->left) {
            temp = temp->left;
            st.push(temp);
        } else {
            cout<<temp->data<<" ";
            st.pop();
            temp = st.top();
            cout<<temp->data<<" ";
            temp = temp->right;
        }
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

    inorder_iter(root);
}