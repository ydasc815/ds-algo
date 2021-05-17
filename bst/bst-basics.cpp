#include<bits/stdc++.h>
#define null NULL
using namespace std;

class BST {
public:
    int data;
    BST *left, *right;
    BST(int data) {
        this->data = data;
        this->left = this->right = null;
    }
};

void inorder(BST* root) {
    if(root == null) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void bst_insert(BST root, int data) {
    
}