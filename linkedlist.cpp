#include<bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
public:
	int data;
	Node* next = null;
	Node(int d) {
		this->data = d;
	}
	Node() {}
};

void build_list(Node** head, int d) {
	if((*head) == null) {
		// it is head node
		*head = new Node();
		(*head)->data = d;
	} else {
		Node* newNode = new Node();
		newNode->data = d;
		newNode->next = null;
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

int get_size(Node** head) {
	int size = 0;
	Node* temp = *head;
	while(temp != null) {
		size++;
		temp = temp->next;
	}
	return size;
}

int get_size_rec(Node** head) {
	if((*head)->next == null) return 1;
	else return 1 + get_size_rec(&((*head)->next));
}

void print_list(Node** head){
	Node* hptr = *head;
	while(hptr != null) {
		cout<<hptr->data<<" ";
		hptr = hptr->next;
	}
	cout<<"\n";
}

int main() {
	Node* head = null;
	build_list(&head, 1);
	build_list(&head, 3);
	build_list(&head, 2);
	build_list(&head, 5);
	build_list(&head, 9);
	build_list(&head, 7);
	build_list(&head, 6);
	build_list(&head, 4);
	build_list(&head, 10);

	print_list(&head);
	cout<<"size of given list = "<<get_size_rec(&head)<<"\n";
}