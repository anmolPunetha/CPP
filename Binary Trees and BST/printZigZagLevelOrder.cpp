#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s){
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;

}

void printKthLevelLtoR(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printKthLevelLtoR(root->left,k-1);
    printKthLevelLtoR(root->right,k-1);
    return;

}

void printKthLevelRtoL(node*root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
	printKthLevelRtoL(root->right,k-1);
    printKthLevelRtoL(root->left,k-1);
    
    return;
}

void printZigzagLevelOrder(node *root){
	int H = height(root);
	for(int i=1;i<=H;i++){
		if(i%2){
			printKthLevelLtoR(root,i);
		}
		else{
			printKthLevelRtoL(root,i);
		}
	}
}

int main() {
	node *root = build("true");
	printZigzagLevelOrder(root);
	return 0;
}
