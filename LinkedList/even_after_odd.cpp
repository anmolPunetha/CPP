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

void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    return;
}

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

void even_after_odd(node*&head){
    node*tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    
    //till head is odd
    while((head->data)%2==0){
        cout<<head->data<<endl;
        node *n = head->next;
        tail->next=head;
        tail=tail->next;
        head->next = NULL;
        head=n;
    }

    //when middle num is even
    node *temp=head->next;
    while(temp->next!=NULL){
        tail->next = temp;
        head->next = temp->next;
        temp->next=NULL;
        tail=tail->next;
    }
}

int main() {
    node*head = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        insertAtTail(head, num);
    }
    even_after_odd(head);
    print(head);
    return 0;
}
