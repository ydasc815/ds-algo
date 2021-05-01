// check for palindrome
#include<bits/stdc++.h>
#define null NULL
using namespace std;
stack<char> st;

class Node {
public:
    char data;
    Node* next;
    Node(char d) {
        this->data = d;
    }
    Node() {}
};

void build_list(Node** head, char d) {
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
    st.push(d);
}

bool check_palindrome(Node* head) {
    if(head == null) {
        cout<<"List is empty !"<<"\n";
        return false;
    } else {
        Node* temp = head;
        int flag = 0;
        while(temp != null) {
            int d = st.top();
            st.pop();
            if(d != temp->data) {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        return (flag == 0);
    }
}

int main() {
    // always initialize empty list (= null)
    Node* head = null;
    build_list(&head, 'a');
    build_list(&head, 'b');
    build_list(&head, 'c');
    build_list(&head, 'b');
    build_list(&head, 'a');

    if(check_palindrome(head)) {
        cout<<"palindrome found";
    } else cout<<"not a palindrome";
}