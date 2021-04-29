#include<bits/stdc++.h>
#define null NULL
using namespace std;

class Node {
public:
	int data;
	Node* next = null;
    Node* curr_ptr = this;
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

int get_size_rec(Node** head) {
	if((*head)->next == null) return 1;
	else return 1 + get_size_rec(&((*head)->next));
}

bool detect_loop(Node* head){
	Node* hptr = head;
    map<Node*, int> m;
	int size = 5;
	while(size--) {
        m[hptr->curr_ptr]++;
		hptr = hptr->next;
	}
    for(auto it=m.begin(); it!=m.end(); it++) {
        if(it->second > 1) return true;
    }
    return false;
}

int main() {
    Node* head = null;
    build_list(&head, 1);
	build_list(&head, 3);
	build_list(&head, 2);
	build_list(&head, 5);

    head->next->next->next->next = head; // test loop

    if(detect_loop(head)) cout<<"loop found !"<<"\n";
    else cout<<"loop not found !"<<"\n";

}