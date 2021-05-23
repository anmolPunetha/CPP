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

int find_k_from_last(node * head, int k){
    node*slow=head;
    node*fast=head;
    for(int i=0;i<k;i++){ //k-1 jumps implies to kth node from front
        fast=fast->next;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;

}
int main() {
    node*head = NULL;
    int n;
    cin>>n;
    while(n!=-1){
        insertAtTail(head, n);
        cin>>n;
    }
    int k;
    cin>>k;
    int ans = find_k_from_last(head,k);
    cout<<ans;
    return 0;
}
