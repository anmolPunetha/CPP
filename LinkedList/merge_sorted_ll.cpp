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

node* merge_sorted_ll(node* &a, node* &b){
    //base
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    //rec
    node*c;
    if((a->data) < (b->data)){
        c=a;
        c->next = merge_sorted_ll(a->next, b);
    }
    else{
        c=b;
        c->next = merge_sorted_ll(a, b->next);
    }
    return c;
}

int main() {

    int t;
    cin>>t;
    for(int times=0;times<t;times++){

		node*head = NULL;
        node*head2=NULL;
        int n1;
        cin>>n1;
        for(int i=0;i<n1;i++){
            int num;
            cin>>num;
            insertAtTail(head, num);
        }

        int n2;
        cin>>n2;
        for(int i=0;i<n2;i++){
            int num2;
            cin>>num2;
            insertAtTail(head2, num2);
        }
    node * result = merge_sorted_ll(head, head2);
    print(result);
	cout<<"\n";//added
    }
    return 0;
}
