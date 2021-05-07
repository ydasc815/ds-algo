#include<bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
public:
    int data;
    Node* next = null;
};

void build_list(Node** head, int data) {
    if(*head == null) {
        // means head is list[0]
        (*head) = new Node();
        (*head)->data = data;
    } else {
        Node* newNode = new Node();
        newNode->next = null;
        newNode->data = data;
        Node* temp = *head;
        while(temp->next != null) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void pop_front(Node** head) {
    if(*head == null) {
        // means list is empty
        cout<<"Empty List !"<<"\n";
        return;
    } else {
        Node* temp1 = *head, *temp;
        while(temp1->next != null) {
            temp = temp1;
            temp1 = temp1->next;
        }
        temp->next = null;
        free(temp1);
    }
}

void pop_back(Node** head) {
    if(*head == null) {
        // means list is empty
        cout<<"Empty List !"<<"\n";
        return;
    } else {
        Node* temp = *head;
        *head = (*head)->next;
        temp->next = null;
        free(temp);
    }
}

void delete_list(Node** head) {
    Node* temp = *head, *temp1 = temp;
    while(temp != null) {
        temp = temp->next;
        free(temp1);
        temp1 = temp;
    }
    *head = null;
}

void print_list(Node** head) {
    Node* temp = *head;
    while(temp != null) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

int main() {
    Node* head = null;
    build_list(&head, 2);
    build_list(&head, 3);
    build_list(&head, 4);
    build_list(&head, 5);
    build_list(&head, 9);
    build_list(&head, 11);
    build_list(&head, 10);
    build_list(&head, 3);
    build_list(&head, 8);
    print_list(&head);

    delete_list(&head);
    print_list(&head);
}