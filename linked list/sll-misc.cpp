// // check for palindrome
// #include<bits/stdc++.h>
// #define null NULL
// using namespace std;
// stack<char> st;

// class Node {
// public:
//     char data;
//     Node* next;
//     Node(char d) {
//         this->data = d;
//     }
//     Node() {}
// };

// void build_list(Node** head, char d) {
//     if(*head == null) {
//         *head = new Node();
//         (*head)->data = d;
//         (*head)->next = null;
//     } else {
//         Node* newNode = new Node();
//         Node* temp = *head;
//         newNode->next = null;
//         newNode->data = d;
//         while(temp->next != null) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
//     st.push(d);
// }

// bool check_palindrome(Node* head) {
//     if(head == null) {
//         cout<<"List is empty !"<<"\n";
//         return false;
//     } else {
//         Node* temp = head;
//         int flag = 0;
//         while(temp != null) {
//             int d = st.top();
//             st.pop();
//             if(d != temp->data) {
//                 flag = 1;
//                 break;
//             }
//             temp = temp->next;
//         }
//         return (flag == 0);
//     }
// }

// void print_list(Node* head) {
//     Node* temp = head;
//     while(temp != null) {
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<"\n";
// }

// int main() {
//     // always initialize empty list (= null)
//     Node* head = null;
//     build_list(&head, 'a');
//     build_list(&head, 'b');
//     build_list(&head, 'c');
//     build_list(&head, 'b');
//     build_list(&head, 'a');

//     if(check_palindrome(head)) {
//         cout<<"palindrome found";
//     } else cout<<"not a palindrome";
// }

// // swap even odd in sll
// #include<bits/stdc++.h>
// #define null NULL
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node(int d) {
//         this->data = d;
//     }
//     Node() {}
// };

// void build_list(Node** head, int d) {
//     if(*head == null) {
//         *head = new Node();
//         (*head)->data = d;
//         (*head)->next = null;
//     } else {
//         Node* newNode = new Node();
//         Node* temp = *head;
//         newNode->next = null;
//         newNode->data = d;
//         while(temp->next != null) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// void swap_even_odd(Node* head) {
//     Node* temp = head, *temp1;
//     while(temp != null) {
//         if(temp->data % 2 != 0) {
//             temp1 = temp->next;
//             while(temp1->data % 2 != 0) {
//                 temp1 = temp1 -> next;
//                 if(temp1 == null) return;
//             }
//             swap(temp->data, temp1->data);
//         } else temp = temp->next;
//     }
// }

// void print_list(Node* head) {
//     Node* temp = head;
//     while(temp != null) {
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     cout<<"\n";
// }

// int main() {
//     // always initialize empty list (= null)
//     Node* head = null;
//     build_list(&head, 17);
//     build_list(&head, 15);
//     build_list(&head, 8);
//     build_list(&head, 12);
//     build_list(&head, 10);
//     build_list(&head, 5);
//     build_list(&head, 4);
//     build_list(&head, 1);
//     build_list(&head, 7);
//     build_list(&head, 6);

//     swap_even_odd(head);
//     print_list(head);

// }

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
    Node* temp = head;
    while(temp != null) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void remove_duplicates(Node* head) {
    Node* temp = head;
    while(temp->next != null) {
        if(temp->data == temp->next->data) {
            Node* delTemp = temp;
            delTemp = delTemp->next;
            temp->next = delTemp->next;
            delTemp->next = null;
            delete(delTemp);
        } else temp = temp->next;
    }
}
 
void remove_duplicates_unsorted(Node* head) {
    map<int, int> m;
    Node* temp = head->next, *temp1 = head;
    m[temp->data]++;
    while(temp != null) {
        m[temp->data]++;
        if(m[temp->data] > 1) {
            m[temp->data]--;
            Node* delTemp = temp;
            temp1->next = delTemp->next;
            delTemp->next = null;
            delete(delTemp);
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
}
int main() {
    // always initialize empty list (= null)
    Node* head = null;
    build_list(&head, 12);
    build_list(&head, 11);
    build_list(&head, 12);
    build_list(&head, 21);
    build_list(&head, 41);
    build_list(&head, 43);
    build_list(&head, 21);
    remove_duplicates_unsorted(head);

    print_list(head);

}