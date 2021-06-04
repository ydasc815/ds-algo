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

vector<int> diagonal(Node *root)
{
   Node* temp = root;
   queue<Node*> q;
   vector<int> res;
   while(temp) {
       cout<<temp->left->data<<"\n";
       if(temp->left) q.push(temp->left);
       res.push_back(temp->data);
       temp = temp->right;
   }
   while(!q.empty()) {
       temp = q.front();
    //    cout<<temp->data<<"\n";
    //    if(temp->data == 6) {
    //        cout<<(temp->left == null) + " " + (temp->right == null)<<"\n";
    //    }
       if(temp->left) q.push(temp->left);
       res.push_back(temp->data);
       if(temp->right) res.push_back(temp->right->data);
       q.pop();
   }
   return res;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    vector<int> v = diagonal(root);
    for(int x:v) cout<<x<<" ";

}