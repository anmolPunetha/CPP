#include <iostream>
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

void level_order_build(node *&root){
	
    int d,c1,c2;
	queue<node*> Q;

	cin>>d;
	root = new node(d);
	Q.push(root);
	while(Q.size() >= 1){
		node *n = Q.front();
		Q.pop();
		cin>>c1>>c2; // Children of n->data
		if(c1 != -1){
			n->left = new node(c1);
			Q.push(n->left);
		}
		if(c2 != -1){
			n->right = new node(c2);
			Q.push(n->right);
		}
	}
}

void bfs(node *root){
    queue<node*> q;
    q.push(root);
	q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
		if(f==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<f->data<<",";
        	q.pop();

        	if(f->left){
            	q.push(f->left);
        	}
        	if(f->right){
            	q.push(f->right);
        	}
		}
        
    }
    return;
}

void printRightView(node*root, int level, int &maxlevel){
	//root-right-left
	if(root==NULL){
		return;
	}
	//root
	if(maxlevel<level){
		cout<<root->data<<" ";
		maxlevel=level;
	}
	//right
	printRightView(root->right, level+1, maxlevel);
	//left
	printRightView(root->left, level+1, maxlevel);
}

int main(){
	node *root;
	level_order_build(root);

	int maxlevel=-1;
	printRightView(root, 0, maxlevel);
	
	return 0;
}
