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
	while(hptr != null) {
		cout<<hptr->data<<" ";
		hptr = hptr->next;
	}
}

int main() {
	Node* head = null; int data;
	// building a singly linkedlist with user input data [size = 10]
	for(int i=0; i<10; i++){
		cin>>data;
		build_list(&head, data);
	}

	print_list(&head);
}