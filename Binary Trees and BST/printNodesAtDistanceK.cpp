#include<iostream>
#include<set>
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
void printKthLevel(node*root,int k, set<int> &s){
    if(root==NULL){
        return;
    }
    if(k==0){
        // cout<<root->data<<" ";
		s.insert(root->data);
        return;
    }
    printKthLevel(root->left,k-1,s);
    printKthLevel(root->right,k-1,s);
    return;
}
int printAtDistanceK(node*root, node*target,int k, set<int> &s){
	if(root==NULL){
		return -1;
	}
	if(root==target){
		printKthLevel(target,k,s);
		return 0;
	}
	int DL = printAtDistanceK(root->left,target,k,s);
	if(DL!=-1){
		if(DL+1==k){
			// cout<<root->data<<" ";
			s.insert(root->data);
		}
		else{
			printKthLevel(root->right,k-2-DL,s);
		}
		return 1+DL;
	}
	int DR = printAtDistanceK(root->right,target,k,s);
	if(DR!=-1){
		if(DR+1==k){
			// cout<<root->data<<" ";
			s.insert(root->data);
		}
		else{
			printKthLevel(root->left,k-2-DR,s);
		}
		return 1+DR;
	}
	return -1;
}
node* find_target_node(node*root, int target_data){
	//base
	if(root==NULL){
		return NULL;
	}
	//rec
	if(root->data==target_data){
		return root;
	}
	else{
		node*ls;
        node*rs;
		ls=find_target_node(root->left, target_data);
        if(ls==NULL){
		    rs=find_target_node(root->right,target_data);
            return rs;
        }
        else{
            return ls;
        }
	}
}
int main() {
	int n;
	cin>>n;
	int preorder[10005];
	int inorder[10005];
	for(int i=0;i<n;i++){
		cin>>preorder[i];
	}
	for(int i=0;i<n;i++){
		cin>>inorder[i];
	}
	int s=0;
	int e=n-1;
	node*root = createTreeFromTraversal(preorder, inorder,s,e);

	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		set<int>s;
		int target_data, k;
		cin>>target_data>>k;
		node*target = find_target_node(root,target_data);
		printAtDistanceK(root, target,k,s);
		if(s.size()){
			for(int a:s){
				cout<<a<<" ";
			}
		}
		else{
			cout<<"0";
		}
		cout<<endl;
	}
	return 0;
}
