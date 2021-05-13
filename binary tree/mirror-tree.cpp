#include<bits/stdc++.h>
#define null NULL
using namespace std;

vector<int> node_list;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = null;
    }
};

void inorder(Node* root) {
    if(root == null) return;

    inorder(root->left);
    node_list.push_back(root->data);
    inorder(root->right);
}

int height(Node* root) {
    int hl = 0, hr = 0;
    Node* temp = root;
    while(temp->left) {
        hl++;
        temp = temp->left;
    }
    temp = root;
    while(temp->right) {
        hr++;
        temp = temp->right;
    }
    return max(1+hl, 1+hr);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);
    inorder(root);
    int i = 0, j = node_list.size() - 1, flag = 0;
    while(i < j) {
        if(node_list[i] != node_list[j]) {
            flag = 1;
            break;
        }
        i++, j--;
    }
    if(flag == 0) cout<<"mirror tree !";
    else cout<<"not mirror tree !";
}