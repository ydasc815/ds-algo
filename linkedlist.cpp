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
		Node* temp = *head;
		while(temp->next != null) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void print_list(Node** head){
	Node* hptr = *head;
	while(hptr->next != null) {
		cout<<hptr->data<<" ";
		hptr = hptr->next;
	}
}

int main() {
	Node* head = null;
	build_list(&head, 2);
	build_list(&head, 1);
	build_list(&head, 3);
	build_list(&head, 4);
	build_list(&head, 5);
	build_list(&head, 8);

	print_list(&head);
}