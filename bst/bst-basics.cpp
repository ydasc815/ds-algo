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

bool search_key(BST* root, int key) {
    if(root == null) return false;
    if(root->data == key) return true;
    
    if(key < root->data) {
        return search_key(root->left, key);
    } else if(key > root->data) {
        return search_key(root->right, key);
    }
    return false;
}

int main() {
//     BST* root = null;

//     inorder(root);
//     cout<<"\n";

//     root = bst_insert(root, 1);
//     root = bst_insert(root, 3);
//     root = bst_insert(root, 5);
//     root = bst_insert(root, 2);
//     root = bst_insert(root, 0);
//     root = bst_insert(root, -1);
//     root = bst_insert(root, 6);
//     root = bst_insert(root, 8);

//     inorder(root);
//     cout<<"\n";
//     cout<<search_key(root, 1);
    // vector<int> v;
    // v.push_back(2);
    // v.push_back(-3);
    // v.push_back(9);
    // v.push_back(4);
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(3);
    // v.push_back(5);
    // vector<int>::iterator vptr = v.end();
    // for(auto it=v.end()-1; it!=v.begin(); it--){
    //     cout<<*it<<" ";
    // }
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    reverse(v.begin(), v.end());
    for(int i:v) cout<<i<<" ";
}