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

BST* bst_insert(BST *root, int data) {
    if(root == null) {
        root = new BST(data);
        return root;
    }
    if(data < root->data) {
        root->left = bst_insert(root->left, data);
    } else if(data > root->data) {
        root->right = bst_insert(root->right, data);
    }
    return root;
}

int main() {
    BST* root = new BST(4);
    root->left = new BST(2);
    root->right = new BST(5);
    root->left->left = new BST(0);
    root->left->right = new BST(3);

    inorder(root);
    cout<<"\n";

    inorder(bst_insert(root, 1));

}