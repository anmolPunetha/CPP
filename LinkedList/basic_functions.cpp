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
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        insertAtTail(head, num);
    }
    print(head);
    return 0;
}
