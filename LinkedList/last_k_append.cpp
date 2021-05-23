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
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

void k_append(node *&head, int k, int n){

    int node_num=n-k;
    node *temp=head;
    for(int i=1;i<node_num;i++){
        temp=temp->next;
    }
    node *tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = head;
    node * temp_next = temp->next;
    temp->next = NULL;
    head=temp_next;
}

int main() {
    node*head = NULL;
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        insertAtTail(head, num);
    }

    cin>>k;
	k=k%n;//added to make k<n...vo ek cycle m honge!!
    k_append(head, k, n);
    print(head);
    return 0;
}
