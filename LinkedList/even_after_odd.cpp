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
        cout<<head->data<<" ";
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
    node*oddstart=NULL;
    node*evenstart=NULL;
    node*oddend=NULL;
    node*evenend=NULL;

    node*temp = head;
    while(temp!=NULL){
        if(temp->data %2){
            if(oddstart==NULL){
                oddstart=temp;
                oddend=oddstart;
            }
            else{
                oddend->next=temp;
                oddend=oddend->next;

            }
        }
        else{
            if(evenstart==NULL){
                evenstart=temp;
                evenend=evenstart;
            }
            else{
                evenend->next=temp;
                evenend=evenend->next;
			}
        }
        temp=temp->next;
    }

	if(oddstart == NULL || evenstart == NULL){ //entire odd/ even
        return;
    }
    oddend->next=evenstart;
    evenend->next=NULL;
    head=oddstart;
    return ;
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
