#include<bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        this->left = this->right = null;
    }
};

int height(Node* root) {
    if(root == null) return 0;
    else return max(1+height(root->left), 1+height(root->right));
}

void levelorder(Node* node, int level) {
    if(node == null) return;
    if(level == 1) cout<<node->data<<" ";
    else {
        levelorder(node->left, level-1);
        levelorder(node->right, level-1);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(10);
    root->left->right = new Node(4);
    root->right->right = new Node(9);
    root->left->right->left = new Node(5);
    root->left->right->left->left = new Node(6);
    root->left->right->left->right = new Node(8);
    root->left->right->left->left->right = new Node(7);

    int h = height(root);
    for(int i=1; i<=h; i++) {
        levelorder(root, i);
    }
}