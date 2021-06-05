#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node * left;
	node * right;

	node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

node* buildTree(){
	int a, b;
	cin>>a>>b;
	node*root;
	if(b==0){
		root = new node(a);
	}
	if(b==2){
		root = new node(a);
		root->left = buildTree();
		root->right = buildTree();
	}
	if(b==1){
		root = new node(a);
		root->left = buildTree();
	}
	return root;
}

static int i=0;
void printKthLevel(node*root,int k){
    
    if(root==NULL){
        return;
    }
    if(k==0){
        // cout<<root->data<<" ";
        i+=root->data;
        return;
    }
    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
    return;
}

int main() {
	node *root = buildTree();
	int k;
	cin>>k;
	printKthLevel(root, k);
  cout<<i;
	return 0;
}
