#include<bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
    }
    Node() {}
};

void build_list(Node** head, int d) {
    if(*head == null) {
        *head = new Node();
        (*head)->data = d;
        (*head)->next = null;
    } else {
        Node* newNode = new Node();
        Node* temp = *head;
        newNode->next = null;
        newNode->data = d;
        while(temp->next != null) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void print_list(Node* head) {
    if(head == null) {
        cout<<"List is empty !"<<"\n";
        return;
    } else {
        Node* temp = head;
        while(temp != null) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"\n";
    }
}

int main() {
    // always initialize empty list (= null)
    Node* head = null;
    build_list(&head, 2);
    build_list(&head, 1);
    build_list(&head, 4);
    build_list(&head, 3);
    build_list(&head, 7);
    build_list(&head, 8);
    print_list(head);
}