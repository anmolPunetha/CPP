#include<iostream>
#include<queue>
using namespace std;
class node{
	public:
	int data;
	node*left;
	node*right;

	node(int x){
		data=x;
		left=NULL;
		right=NULL;
	}
};

void bfs(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* f = q.front();
        cout<<f->data<<",";
        q.pop();

        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}
node*createTreeFromTraversal(int*preorder, int*inorder, int s, int e){
	static int i=0;                 //to traverse preorder array
	//base
	if(s>e){
		return NULL;
	}
	//rec
	node*root=new node(preorder[i]);
	int index=-1;
	for(int j=s;j<=e;j++){
		if(inorder[j]==preorder[i]){
			index=j;
			break;
		}
	}

	i++;
	root->left=createTreeFromTraversal(preorder, inorder, s, index-1);
	root->right=createTreeFromTraversal(preorder, inorder, index+1, e);
	return root;
}

int main() {
	int n,m;
	cin>>n;
	int preorder[10005];
	int inorder[10005];
	for(int i=0;i<n;i++){
		cin>>preorder[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>inorder[i];
	}
	int s=0;
	int e=m-1;
	node*root = createTreeFromTraversal(preorder, inorder,s,e);
	bfs(root);
	return 0;
}
