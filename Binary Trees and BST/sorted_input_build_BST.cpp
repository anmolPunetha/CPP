#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* insertFromSortedArray(int *arr, int s, int e){
	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);
	root->left = insertFromSortedArray(arr,s,mid-1);
	root->right = insertFromSortedArray(arr,mid+1,e);
	return root;
}

node* build(){
    int n;
    cin>>n;
	int arr[10000];
    // node*root = NULL;
	for(int i =0;i<n;i++){
		cin>>arr[i];
	}
	node * root = insertFromSortedArray(arr,0,n-1);
    return root;
}
void preorder(node*root){
    if(root==NULL){
        return;
    }
	cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		node *root = build();
		preorder(root);
		cout<<endl;
	}
	return 0;
}
