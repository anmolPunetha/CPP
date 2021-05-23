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

node * reverse_k(node*head, int k){
	//base
	if(head==NULL){
		return NULL;
	}
	//rec
	node*prev=NULL;
	node*n=NULL;
	node *current =head;
	int count=0;
	while(count<k and current!=NULL){
		n=current->next;
		current->next=prev;
		prev=current;
		current=n;
		count++;
	}
	//next is now a pointer to (k+1)th node
	if(n!=NULL){
		head->next=reverse_k(n,k); //imp
	}
	//prev is the new head
	return prev;
}
int main() {
    node*head = NULL;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        insertAtTail(head, num);
    }

	cout<<endl;
	node*c = reverse_k(head, k);
    print(c);
    return 0;
}
