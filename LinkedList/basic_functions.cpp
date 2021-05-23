#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int d){
            data = d;
            next = NULL;
        }
};

void insertAtTail(node* &head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }

    node *tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return ;
}

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    return;
}
int main() {
    node*head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    print(head);
    return 0;
}
